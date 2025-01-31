/*
 * files.c
 *
 *  Created on: 2019. 11. 10.
 *      Author: Baram
 */




#include "files.h"

#include "FatFs/src/ff.h"




FILE *ob_fopen(const char *filename, const char *mode)
{
  FRESULT res;
  BYTE flags = 0;
  FIL *fil;
  int i;

  fil = malloc(sizeof(FIL));
  if (!fil)
    return NULL;

  for (i=0; mode[i] != 0; i++) {
    switch (mode[i]) {
      case 'w':
        flags |= FA_WRITE | FA_CREATE_ALWAYS;
        break;
      case 'r':
        flags |= FA_READ;
        break;
      case '+':
        flags |= FA_READ | FA_WRITE;
        break;
    }
  }

  res = f_open(fil, filename, flags);
  if (res != FR_OK) {
    free(fil);
    return NULL;
  }

  return (FILE *) fil;
}

int ob_fclose(FILE *stream)
{
  FRESULT res;
  FIL *fil = (FIL *) stream;
  res = f_close(fil);
  if (res != FR_OK)
    return -1;

  free(fil);
  return 0;
}
size_t ob_fread(void *ptr, size_t size, size_t count, FILE *stream)
{
  FRESULT res;
  FIL *fil = (FIL *) stream;
  UINT bread;
  res = f_read(fil, ptr, size * count, &bread);
  if (res != FR_OK)
    return 0;

  return bread;
}
size_t ob_fwrite(const void *ptr, size_t size, size_t count, FILE *stream)
{
  FRESULT res;
  FIL *fil = (FIL *) stream;
  UINT bwrite;
  res = f_write(fil, ptr, size * count, &bwrite);
  if (res != FR_OK)
    return 0;

  return bwrite;
}
int ob_fflush(FILE *stream)
{
  FRESULT res;
  FIL *fil;
  if (!stream)
    return 0;

  fil = (FIL *) stream;
  res = f_sync(fil);
  if (res != FR_OK)
    return -1;

  return 0;
}
int ob_feof(FILE *stream)
{
  FIL *fil = (FIL *) stream;
  return f_eof(fil);
}
int ob_fseek(FILE *stream, long offset, int whence)
{
  FRESULT res;
  FIL *fil = (FIL *) stream;
  long o;
  switch (whence) {
    case SEEK_SET:
      o = offset;
      break;
    case SEEK_CUR:
      o = offset + f_tell(fil);
      break;
    case SEEK_END:
      o = f_size(fil) + offset;
      if (o < 0)
        o = 0;
      break;
    default:
      return -1;
  }
  res = f_lseek(fil, o);
  if (res != FR_OK)
    return -1;

  return 0;
}

long ob_ftell(FILE *stream)
{
  FIL *fil = (FIL *) stream;
  return f_tell(fil);
}

int ob_fgetc(FILE *stream)
{
  char c;
  FIL *fil = (FIL *)stream;
  FRESULT res;
  UINT bread;

  res = f_read(fil, &c, 1, &bread);
  if (res != FR_OK)
    return (EOF);

  return (c);
}

char* ob_fgets(char* str, int num, FILE* stream)
{
  FIL *fil = (FIL *)stream;


  return f_gets(str, num, fil);
}

/*
 * hw.c
 *
 *  Created on: 2019. 6. 14.
 *      Author: HanCheol Cho
 */




#include "hw.h"



__attribute__((section(".version"))) uint8_t boot_name[32] = "OROCABOY3";
__attribute__((section(".version"))) uint8_t boot_ver[32]  = "B191122R1";

static uint8_t reset_count = 0;


static void bootModeWait(void);


void hwInit(void)
{
  bspInit();



  resetInit();
  microsInit();
  millisInit();
  delayInit();
  cmdifInit();
  swtimerInit();

  uartInit();
  uartOpen(_DEF_UART1, 57600);

  logPrintf("\n\n[ Bootloader Begin... ]\r\n");
  logPrintf("Booting..Name \t\t: %s\r\n", boot_name);
  logPrintf("Booting..Ver  \t\t: %s\r\n", boot_ver);


  resetLog();
  rtcInit();
  pwmInit();
  ledInit();

  bootModeWait();
  sdramInit();
  if (hwGetResetCount() >= 2)
  {
    if (sdramTest() == true)
    {
      logPrintf("SDRAM Test \t\t: OK\r\n");
    }
    else
    {
      logPrintf("SDRAM Test \t\t: Fail\r\n");
    }
  }

  qspiInit();
  flashInit();
  buttonInit();
  i2cInit();
  eepromInit();
  if (eepromValid(0) == true)
  {
    logPrintf("eeprom %dKB \t\t: OK\r\n", (int)eepromGetLength()/1024);
  }
  else
  {
    logPrintf("eeprom %dKB \t\t: Fail\r\n", (int)eepromGetLength()/1024);
  }


  logPrintf("Start...\r\n");
}

void bootModeWait(void)
{
  rtcWriteBackupData(_HW_DEF_RTC_RESET_SRC, resetGetBits());

  logPrintf("ResetBits \t\t: 0x%X\n", (int)rtcReadBackupData(_HW_DEF_RTC_RESET_SRC));


  if (resetGetBits() == (1<<_DEF_RESET_PIN))
  {
    reset_count = (uint8_t)rtcReadBackupData(_HW_DEF_RTC_BOOT_RESET);
    logPrintf("ResetCount \t\t: %d\r\n", (int)reset_count);

    rtcWriteBackupData(_HW_DEF_RTC_BOOT_RESET, rtcReadBackupData(_HW_DEF_RTC_BOOT_RESET) + 1);
    ledOn(_DEF_LED1);
    delay(500);
    rtcWriteBackupData(_HW_DEF_RTC_BOOT_RESET, 0);
    ledOff(_DEF_LED1);

    rtcWriteBackupData(_HW_DEF_RTC_BOOT_MODE, 0);
  }
  else
  {
    logPrintf("ResetCount \t\t: %d\r\n", (int)reset_count);
    rtcWriteBackupData(_HW_DEF_RTC_BOOT_RESET, 0);
  }

  logPrintf("ResetMode \t\t: %d\r\n", (int)rtcReadBackupData(_HW_DEF_RTC_BOOT_MODE));
}

uint8_t hwGetResetCount(void)
{
  return reset_count;
}



// 4.12.2 dither_algorithm=2 alpha_dither=yes layout_rotation=0 opaque_image_format=RGB565 non_opaque_image_format=ARGB8888 section=ExtFlashSection extra_section=ExtFlashSection generate_png=no 0xd1ea6dce
// Generated by imageconverter. Please, do not edit!

#include <touchgfx/Bitmap.hpp>
#include <BitmapDatabase.hpp>

extern const unsigned char _counter_box[]; // BITMAP_COUNTER_BOX_ID = 0, Size: 152x154 pixels
extern const unsigned char _down_btn[]; // BITMAP_DOWN_BTN_ID = 1, Size: 130x56 pixels
extern const unsigned char _down_btn_disabled[]; // BITMAP_DOWN_BTN_DISABLED_ID = 2, Size: 130x56 pixels
extern const unsigned char _down_btn_pressed[]; // BITMAP_DOWN_BTN_PRESSED_ID = 3, Size: 130x56 pixels
extern const unsigned char _up_btn[]; // BITMAP_UP_BTN_ID = 4, Size: 130x56 pixels
extern const unsigned char _up_btn_disabled[]; // BITMAP_UP_BTN_DISABLED_ID = 5, Size: 130x56 pixels
extern const unsigned char _up_btn_pressed[]; // BITMAP_UP_BTN_PRESSED_ID = 6, Size: 130x56 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] =
{
    { _counter_box, 0, 152, 154, 0, 0, 152, (uint8_t)(touchgfx::Bitmap::RGB565) >> 3, 154, (uint8_t)(touchgfx::Bitmap::RGB565) & 0x7 },
    { _down_btn, 0, 130, 56, 3, 0, 124, (uint8_t)(touchgfx::Bitmap::ARGB8888) >> 3, 55, (uint8_t)(touchgfx::Bitmap::ARGB8888) & 0x7 },
    { _down_btn_disabled, 0, 130, 56, 3, 0, 124, (uint8_t)(touchgfx::Bitmap::ARGB8888) >> 3, 55, (uint8_t)(touchgfx::Bitmap::ARGB8888) & 0x7 },
    { _down_btn_pressed, 0, 130, 56, 3, 0, 124, (uint8_t)(touchgfx::Bitmap::ARGB8888) >> 3, 55, (uint8_t)(touchgfx::Bitmap::ARGB8888) & 0x7 },
    { _up_btn, 0, 130, 56, 3, 0, 124, (uint8_t)(touchgfx::Bitmap::ARGB8888) >> 3, 55, (uint8_t)(touchgfx::Bitmap::ARGB8888) & 0x7 },
    { _up_btn_disabled, 0, 130, 56, 3, 0, 124, (uint8_t)(touchgfx::Bitmap::ARGB8888) >> 3, 55, (uint8_t)(touchgfx::Bitmap::ARGB8888) & 0x7 },
    { _up_btn_pressed, 0, 130, 56, 3, 0, 124, (uint8_t)(touchgfx::Bitmap::ARGB8888) >> 3, 55, (uint8_t)(touchgfx::Bitmap::ARGB8888) & 0x7 }
};

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance()
{
    return bitmap_database;
}
uint16_t getInstanceSize()
{
    return (uint16_t)(sizeof(bitmap_database) / sizeof(touchgfx::Bitmap::BitmapData));
}
}

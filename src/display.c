#include "display.h"
#include "config.h"
#include "oled.h"
const uint8_t logo_buffer[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x04, 0xF4, 0xF4, 0x04, 0xE8, 0xE8, 0x28, 0x28, 0x28, 0x28, 0xE8, 0xC8,
    0x10, 0xC8, 0xE8, 0x28, 0x28, 0x28, 0x28, 0xE8, 0xC8, 0x08, 0xE8, 0xE8, 0xC8, 0x90, 0x10, 0x08, 0xE8, 0xE8, 0x08, 0x04, 0x82, 0x8A, 0xE2, 0x0C, 0x10, 0x90, 0xC8, 0xE4, 0x74, 0xA2, 0x49, 0x1C,
    0x8E, 0x07, 0x03, 0xE1, 0xF0, 0x12, 0x15, 0x14, 0x14, 0xF4, 0xE4, 0x08, 0x64, 0xF4, 0x94, 0x94, 0x94, 0x94, 0x14, 0x44, 0xB8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x20, 0x2F, 0x2F, 0x20, 0x2F, 0x2F, 0x21, 0x11, 0x11, 0x21, 0x2F, 0x2E,
    0x20, 0x27, 0x2F, 0x28, 0x28, 0x28, 0x28, 0x2F, 0x27, 0x20, 0x2F, 0x2F, 0x20, 0x11, 0x13, 0x26, 0x2F, 0x2F, 0x20, 0x43, 0x8D, 0xA1, 0x98, 0x54, 0x43, 0x23, 0x15, 0x12, 0x09, 0x04, 0x02, 0x01,
    0x00, 0x0F, 0x10, 0x27, 0x2F, 0x28, 0x28, 0x28, 0x28, 0x2F, 0x27, 0x20, 0x28, 0x28, 0x28, 0x28, 0x28, 0x2F, 0x27, 0x10, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

void display_show_version(void) {
  // Prints to the screen, the DFU version
  oled_clearScreen();
#ifdef BOOTLOADER_MODE
  OLED_DrawString("DFU Bootloader", 0);
#else
#ifdef RUNTIME_MODE
  OLED_DrawString("DFU Runtime", 0);
#else
#error DISPLAY NEEDS MODE DEFINE
#endif

#endif
  OLED_DrawString(VERSION, 1);
  oled_Refresh();
}
void display_splash(void) {
  // Print the splash screen directly to the OLED
  oled_clearScreen();
  oled_DrawArea(0, 0, 96, 16, logo_buffer);
  oled_Refresh();
}

/*
 * usb_device.c
 *
 *  Created on: Dec 20, 2025
 *      Author: wandouuu
 */

#include <macropad_USB_handler.h>
#include "usbd_customhid.h"
#include "matrix_scan.h"
#include <string.h>
#include "usbd_customhid.h" 
#include "ssd1306.h"
#include <stdio.h>

extern const SSD1306_Font_t Font_11x18;
extern USBD_HandleTypeDef hUsbDeviceFS;

uint8_t prev_report[KEYPAD_REPORT_SIZE] = {0};
uint8_t curr_report[KEYPAD_REPORT_SIZE] = {0};

void send_and_form_USBHID_report(){

   curr_report[0] = 0x01; // Report ID for keyboard

   uint8_t ctr = 3;
   for(uint8_t r = 0; r < KEYPAD_ROWS; ++r){
      for(uint8_t c = 0; c < KEYPAD_COLS; ++c){

         if(key_stable_state[r][c] == KEY_PRESSED){
            curr_report[ctr] = keymap[r][c];
            ++ctr;
         }

      }
   }

   if(memcmp(prev_report, curr_report, KEYPAD_REPORT_SIZE) != 0){
      USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, curr_report, KEYPAD_REPORT_SIZE);
      memcpy(prev_report, curr_report, KEYPAD_REPORT_SIZE);
   }
   

   return;

}

void update_display(uint8_t volume){
   
   ssd1306_Fill(Black); // Clear screen
   uint8_t x = 10;
   uint8_t y = 16;
   char str[12];
   snprintf(str, sizeof(str), "Volume: %d", volume);
   ssd1306_SetCursor(x,y);
   ssd1306_WriteString(str, Font_11x18, White);
   ssd1306_UpdateScreen();
   
   return;
}

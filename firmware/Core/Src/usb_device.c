/*
 * usb_device.c
 *
 *  Created on: Dec 20, 2025
 *      Author: wandouuu
 */

 #include "usb_device.h"
 #include "usbd_customhid.h"
 #include "keymap.h"

 uint8_t USB_send_key(uint8_t key_state, uint8_t row, uint8_t col){
   
   uint8_t report[]{};

   return USBD_CUSTOM_HID_SendReport();

 }




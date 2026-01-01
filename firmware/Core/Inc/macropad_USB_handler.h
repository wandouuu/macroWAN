/*
 * usb_device.h
 *
 *  Created on: Dec 20, 2025
 *      Author: wandouuu
 */

#ifndef INC_MACROPAD_USB_HANDLER_H_
#define INC_MACROPAD_USB_HANDLER_H_

#include "matrix_scan.h"

#define KEYPAD_REPORT_SIZE 0x09U

// Keyboard matrix handler
void send_and_form_USBHID_report();

// Rotary encoder (rotation) handler
void encoder_handler(void); // temporary arguments

// SSD1306 OLED display handler
void display_handler(void); // temporary arguments
#endif /* INC_MACROPAD_USB_HANDLER_H_ */

/*
 * usb_device.h
 *
 *  Created on: Dec 20, 2025
 *      Author: wandouuu
 */

#ifndef INC_USB_DEVICE_H_
#define INC_USB_DEVICE_H_

#include "matrix_scan.h"

// Keyboard matrix handler
void matrix_handler(uint8_t key_state, uint8_t row, uint8_t col);

// Rotary encoder (rotation) handler
void encoder_handler(void); // temporary arguments

// SSD1306 OLED display handler
void display_handler(void); // temporary arguments
#endif /* INC_USB_DEVICE_H_ */

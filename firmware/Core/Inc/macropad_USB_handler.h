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
#define ENCODER_REPORT_SIZE 0x02U

extern uint8_t encoder_curr_report[ENCODER_REPORT_SIZE];
// Keyboard matrix handler
void send_matrix_HID_report(void);

// Rotary encoder (rotation) handler
void send_encoder_HID_report(uint8_t vol);

// SSD1306 OLED display handler
void update_display(uint8_t volume);
#endif /* INC_MACROPAD_USB_HANDLER_H_ */

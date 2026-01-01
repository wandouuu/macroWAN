/*
 * matrix_keypad.h
 *
 *  Created on: Dec 17, 2025
 *      Author: wandouuu
 */

#ifndef INC_MATRIX_SCAN_H_
#define INC_MATRIX_SCAN_H_

#include "stm32f4xx_it.h"
#include <stdint.h>

// Define rows and columns
#define KEYPAD_ROWS    3
#define KEYPAD_COLS 3

// Rows
#define ROW0_GPIO_Port GPIOA
#define ROW0_Pin       GPIO_PIN_8
#define ROW1_GPIO_Port GPIOA
#define ROW1_Pin       GPIO_PIN_15
#define ROW2_GPIO_Port GPIOB
#define ROW2_Pin       GPIO_PIN_4

// Columns
#define COL0_GPIO_Port GPIOB
#define COL0_Pin       GPIO_PIN_9
#define COL1_GPIO_Port GPIOB
#define COL1_Pin       GPIO_PIN_8
#define COL2_GPIO_Port GPIOB
#define COL2_Pin       GPIO_PIN_15

// Define values for key presses and key released
#define KEY_RELEASED   0
#define KEY_PRESSED    1

// Define values for debouncing
#define DEBOUNCE_ITER  5 // will check in main loop every 3 ms, compounding to 15 ms debounce time

#ifdef __cplusplus
extern "C" {
#endif

// Keymap
extern uint8_t keymap[KEYPAD_ROWS][KEYPAD_COLS];

// Tracking the state of each key
extern uint8_t key_state[KEYPAD_ROWS][KEYPAD_COLS];

// Tracking the stable state of each key
extern uint8_t key_stable_state[KEYPAD_ROWS][KEYPAD_COLS];

// Key iteration (for debouncing)
extern uint8_t key_iteration[KEYPAD_ROWS][KEYPAD_COLS];

// Initialize keypad
void keypad_init(void);

// Scanning
void matrix_scan(void);
#ifdef __cplusplus
}
#endif

#endif /* INC_MATRIX_SCAN_H_ */

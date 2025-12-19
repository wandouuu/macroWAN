/*
 * matrix_keypad.h
 *
 *  Created on: Dec 17, 2025
 *      Author: wandouuu
 */

#ifndef INC_MATRIX_SCAN_H_
#define INC_MATRIX_SCAN_H_

#include "stm32f4xx_it.h"

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

#ifdef __cplusplus
extern "C" {
#endif


// Tracking the state of each key
static const char key_state[KEYPAD_ROWS][KEYPAD_COLS] = {
    {'\0', '\0', 'A'}, // ROW 0 
    { 'B' , 'C', 'D'}, // ROW 1
    { 'E',  'F', 'G'}  // ROW 2
    // C0    C1   C2
};

// Initialize keypad
void Keypad_Init(void);

// Scanning
void Keypad_GetKey(void);
#ifdef __cplusplus
}
#endif

#endif /* INC_MATRIX_SCAN_H_ */

/*
 * matrix_keypad.c
 *
 *  Created on: Dec 17, 2025
 *      Author: wandouuu
 */

#include "matrix_keypad.h"

// Arrays containing row ports/pins and column ports/pins
static GPIO_TypeDef* const ROW_PORT[KEYPAD_ROWS] = {
    ROW0_GPIO_Port, ROW1_GPIO_Port, ROW2_GPIO_Port
};

static const uint16_t ROW_PIN[KEYPAD_ROWS] = {
    ROW0_Pin, ROW1_Pin, ROW2_Pin
};

static GPIO_TypeDef* const COL_PORT[KEYPAD_COLS] = {
    COL0_GPIO_Port, COL1_GPIO_Port, COL2_GPIO_Port
};

static const uint16_t COL_PIN[KEYPAD_COLS] = {
    COL0_Pin, COL1_Pin, COL2_Pin
};

void Keypad_Init(void){
    uint8_t i = 0;

    for(i = 0; i < KEYPAD_COLS; ++i){
        HAL_GPIO_WritePin(COL_PORT[i], COL_PIN[i], GPIO_PIN_SET); // Set pin to high
    }
}
#ifndef __MATRIX_KEYPAD_H_
#define __MATRIX_KEYPAD_H_

#include "stm32f4xx_it.h"

// Define rows and columns
#define KEYPAD_ROWS    3
#define KEYPAD_COLUMNS 3

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

#ifdef __cplusplus
}
#endif
#endif /* __MATRIX_KEYPAD_H_ *
/*
 * encoder_scan.h
 *
 *  Created on: Jan 3, 2026
 *      Author: wandouuu
 */

#ifndef INC_ENCODER_SCAN_H_
#define INC_ENCODER_SCAN_H_

#include "stm32f4xx_it.h"
#include <stdint.h>

// Define Pin A
#define ENC_A_PORT     GPIOB
#define ENC_A_PIN      GPIO_PIN_13

// Define Pin B
#define ENC_B_PORT     GPIOB
#define ENC_B_PIN      GPIO_PIN_12

#define VOLUME_UP      0x01
#define VOLUME_DOWN    0x02

#ifdef __cplusplus
extern "C" {
#endif

extern uint8_t encoder_release_flag;
extern uint32_t encoder_previous_time;

void encoder_scan(void);

#ifdef __cplusplus
}
#endif



#endif /* INC_ENCODER_SCAN_H_ */

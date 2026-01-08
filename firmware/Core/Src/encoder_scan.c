/*
 * encoder_scan.c
 *
 *  Created on: Jan 3, 2026
 *      Author: wandouuu
 */

#include "main.h"
#include "encoder_scan.h"
#include "macropad_USB_handler.h"

uint8_t previous_ENC_A_state = GPIO_PIN_SET; // default is HIGH (1)

void encoder_scan(){
    GPIO_PinState current_ENC_A_state = HAL_GPIO_ReadPin(ENC_A_PORT, ENC_A_PIN);

    if(previous_ENC_A_state == GPIO_PIN_SET){
        
        if(current_ENC_A_state == GPIO_PIN_RESET){

            if(current_ENC_A_state != HAL_GPIO_ReadPin(ENC_B_PORT, ENC_B_PIN)){ // CW
                send_encoder_HID_report(VOLUME_UP);
            } else{ // CCW (same state)
                send_encoder_HID_report(VOLUME_DOWN);
            }

            encoder_release_flag = 1;
            encoder_previous_time = HAL_GetTick();
            

        }

    }

    previous_ENC_A_state = current_ENC_A_state;
    // otherwise do nothing
    return;

}


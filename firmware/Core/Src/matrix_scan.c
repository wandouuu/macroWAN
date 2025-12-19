#include <matrix_scan.h>

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

// Set each column to high (not reading state)
void keypad_init(void){
    uint8_t i = 0;
    
    for(i = 0; i < KEYPAD_COLS; ++i){
        HAL_GPIO_WritePin(COL_PORT[i], COL_PIN[i], GPIO_PIN_SET); // Set column to high
    }

    return;
}

void matrix_scan(void){

    
    for(uint8_t c = 0; c < 3; ++c){
        
        // Set current column low to start reading row
        HAL_GPIO_WritePin(COL_PORT[c], COL_PIN[c], GPIO_PIN_RESET); // Set column to low

        for(uint8_t r = 0; r < 3; ++r){
            
            // If the row pin reads LOW but the previous state was released
            if(HAL_GPIO_ReadPin(ROW_PORT[r], ROW_PIN[r]) == GPIO_PIN_RESET && key_state[r][c] == KEY_RELEASED){
                
                key_state[r][c] = KEY_PRESSED;
                key_iteration[r][c] = 0;

            // If the row pin reads HIGH but the previous state was pressed
            } else if(HAL_GPIO_ReadPin(ROW_PORT[r], ROW_PIN[r]) == GPIO_PIN_SET && key_state[r][c] == KEY_PRESSED){ // 
                
                key_state[r][c] = KEY_RELEASED;
                key_iteration[r][c] = 0;

            // If the row pin reads HIGH and the previous state was pressed
            } else{
                
                // Still unstable, check next
                if(key_iteration[r][c] < DEBOUNCE_ITER){
                    key_iteration[r][c]++;

                // Valid click!
                } else if(key_iteration[r][c] == DEBOUNCE_ITER){
                    key_iteration[r][c]++;
                    // USB handler
                }

            }
        }

        // Set current column back to high to stop reading row
        HAL_GPIO_WritePin(COL_PORT[c], COL_PIN[c], GPIO_PIN_SET);

    }

}
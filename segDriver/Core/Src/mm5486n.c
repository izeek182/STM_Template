#include "mm5486n.h"

uint32_t segD;
uint16_t segVal = 0x1234;
uint8_t place = 0; // Even Is clock high, odd is clk low. 
// data is sent on low clock

char segTable[16] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F, // 9
    0x77, // A
    0x7C, // B
    0x39, // C
    0x5E, // D
    0x79, // E
    0x71  // F
};


void regenSegD(){
    segD = 0;
    for(int i =0;i<4;i++){
        uint8_t val = (segVal >> (i * 4))&0xF;
        segD |= segTable[val];
        if(i == 3){
            break;
        }
        segD = segD << 8;
    }
}

void sendData(uint16_t data){
    segVal = data;
}

void segTick(){ 
    place++;
    if(place > 65){
        place = 0;
        regenSegD();
        HAL_GPIO_WritePin(SegLock_GPIO_Port,SegLock_Pin,GPIO_PIN_SET);
        HAL_GPIO_WritePin(gLED_GPIO_Port,gLED_Pin,GPIO_PIN_SET);
    }
    if(place == 1){
        HAL_GPIO_WritePin(SegLock_GPIO_Port,SegLock_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(gLED_GPIO_Port,gLED_Pin,GPIO_PIN_RESET);
    }
    // Clock rising edge
    if(!(place&0x1)){
        HAL_GPIO_WritePin(segClk_GPIO_Port,segClk_Pin,GPIO_PIN_SET);
        return;
    }
    // clock falling edge
    HAL_GPIO_WritePin(segClk_GPIO_Port,segClk_Pin,GPIO_PIN_RESET);
    
    if(segD&0x1){
        HAL_GPIO_WritePin(segD_GPIO_Port,segD_Pin,GPIO_PIN_SET);
        HAL_GPIO_WritePin(oLED_GPIO_Port,oLED_Pin,GPIO_PIN_SET);
    }else{
        HAL_GPIO_WritePin(segD_GPIO_Port,segD_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(oLED_GPIO_Port,oLED_Pin,GPIO_PIN_RESET);
    }
    // Aline the next bit of data
    segD = segD>>1;
}

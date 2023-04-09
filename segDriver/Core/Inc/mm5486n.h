#ifndef __MM5486N
#define __MM5486N

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f0xx_hal.h"
#include "main.h"

void sendData(uint16_t data);
void segTick();

#ifdef __cplusplus
}
#endif

#endif /* MM5486N */
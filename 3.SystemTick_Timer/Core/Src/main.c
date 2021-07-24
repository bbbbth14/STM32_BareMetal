#include "stm32f4xx.h"



int main(void) {
    RCC->AHB1ENR |=  8;
    GPIOD->MODER |=  0x10000000;

    /* Configure SysTick */
    SysTick->LOAD = 3200000-1;
		SysTick->VAL = 0;
    SysTick->CTRL = 5;

    while (1) {

		   if(SysTick->CTRL & 0x10000)

        GPIOD->ODR ^= 0x4000;
    }
}

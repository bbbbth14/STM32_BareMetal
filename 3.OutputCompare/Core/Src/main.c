#include "stm32f4xx.h"


int main(void) {

    RCC->AHB1ENR |=  8;
    GPIOD->MODER |=  0x80000000;
    GPIOD->AFR[0] |= 0x00100000;  // Set AF1 for Timer2

    RCC->APB1ENR |= 1;
    TIM2->PSC = 1600 - 1;
    TIM2->ARR = 10000 - 1;
    TIM2->CCMR1 = 0x30;     // Set output to toggle on match
    TIM2->CCR1 = 0;         // Set match mode
    TIM2->CCER |= 1;         // Enable CH1 compare mode
    TIM2->CNT = 0;           // Clear counter
    TIM2->CR1 = 1;           // Enable TIM2


    while (1) {

    }
}


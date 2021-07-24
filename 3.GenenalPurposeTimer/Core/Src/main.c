#include "stm32f4xx.h"

void systickDelayMs(int n);

int main(void) {
    //GPIO initialization
	RCC->AHB1ENR |=  8;
    GPIOD->MODER |=  0x40000000;

    RCC->APB1ENR |= 1;
    TIM2->PSC = 1600 - 1;
    TIM2->ARR = 10000 - 1;
    TIM2->CNT = 0; // Clear timer counter
    TIM2->CR1 = 1; // Counter enable


    while (1) {
        while(!(TIM2->SR & 1)) {} // Timer flag isn't set, do nothing
        TIM2->SR &= ~1; // Set => clear flag and start to blink SR & 0
        GPIOD->ODR ^= 0x8000;
    }
}



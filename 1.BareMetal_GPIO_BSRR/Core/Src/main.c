#include "stm32f4xx.h"


void delayMs(int delay);

int main(void) {

    RCC->AHB1ENR |=  8;

    GPIOA->MODER |=  0x40000000;

    while(1) {
        GPIOA->BSRR = 0x20;
        delayMs(50);
        GPIOA->BSRR = 0x00200000;   /* turn off LED */
        delayMs(100);
    }
}

void delayMs(int n) {
    int i;
    for (; n > 0; n--)
        for (i = 0; i < 3195; i++) ;
}

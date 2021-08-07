#include "stm32f4xx.h"
// LED: PD15/PD14
//Button: PA0



void systickDelayMs(int n);

int counter=0;

int main(void) {
    __disable_irq();

    RCC->AHB1ENR |= 8;	         // Port D
    RCC->AHB1ENR |= 1;           // Port A
    RCC->APB2ENR |= 0x4000;      // Enable SYSCFG clock, System configuration controller clock

    //configure PD15 for LED
    GPIOD->MODER |=  0x40000000;
    SYSCFG->EXTICR[0] |= 0x0000;        // Select port A for external interrupt 0

    EXTI->IMR |= 0x0001;                // unmask EXTI13
    EXTI->FTSR |= 0x0001;               // Select falling edge trigger

    NVIC_EnableIRQ(EXTI0_IRQn);

    __enable_irq();

    while(1) {
    }
}

void EXTI0_IRQHandler(void) {
        GPIOD->BSRR = 0x80000000;
        systickDelayMs(400);
        GPIOD->BSRR = 0x00008000;
        systickDelayMs(400);
        GPIOD->BSRR = 0x80000000;
        systickDelayMs(400);
        GPIOD->BSRR = 0x00008000;
        systickDelayMs(400);
				counter++;
        EXTI->PR = 0x0001;               // Pending register
}

void systickDelayMs(int n) {

    /* Configure SysTick */
    SysTick->LOAD = 16000;  // Reload with number of clocks per millisecond
    SysTick->VAL = 0;       // Clear current value register
    SysTick->CTRL = 0x5;    // Enable the timer

    for(int i = 0; i < n; i++) {

		// Wait until the COUNTFLAG is set
        while((SysTick->CTRL & 0x10000) == 0)
            { }
    }
    SysTick->CTRL = 0;
}

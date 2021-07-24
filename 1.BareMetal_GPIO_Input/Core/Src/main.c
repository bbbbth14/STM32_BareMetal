#include "stm32f4xx.h"

#define GPIOD_EN (1<<3)
#define GPIOA_EN1 (1<<0)
#define MODER_15_OUT (1<<28)
#define ODR_15_SET (1<<14)
#define ODR_15_RESET (0<<14)

#define LED_PIN (1<<14)

int main(void)
{

	RCC->AHB1ENR |= GPIOD_EN;
	RCC->AHB1ENR |= GPIOA_EN1;
//	RCC->AHB1ENR |= 8;
//  RCC->AHB1ENR |= 1;
	  //GPIOD->MODER |=0x40000000;
	GPIOD->MODER |= MODER_15_OUT;
	while(1)
	{

		 if (GPIOA->IDR & 0x00000001)
            GPIOD->BSRR = 0x4000;
        else
            GPIOD->BSRR = 0x40000000;


	}
}


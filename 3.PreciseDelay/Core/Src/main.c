#include "stm32f4xx.h"

void systickDelay_ms(int n);

int main()
{
	RCC->AHB1ENR |= 8;
	GPIOD->MODER |= 0x10000000;

	while(1)
	{
		GPIOD->ODR ^= 0x4000;
		systickDelay_ms(300);
	}
}

void systickDelay_ms(int n)
{
// Configure Systick
	SysTick->LOAD = 16000-1; // Reload
	SysTick->VAL = 0; // Clear current value register
	SysTick->CTRL = 0x5; // Enable the timer

	for(int i = 0; i<n; i++)
	{
		//Wait until the COUNTERFLAG is set
		while((SysTick->CTRL & 0x10000) == 0)
		{}
	}
	SysTick->CTRL = 0;


}


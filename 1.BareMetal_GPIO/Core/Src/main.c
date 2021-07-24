#include "stm32f4xx.h"

void delay(int delay);

int main()
{
	RCC->AHB1ENR |= 8;
	GPIOD->MODER |= 0x40000000;
	while(1)
	{
		GPIOD->ODR |= 0x8000;
		delay(200);
		GPIOD->ODR &=~0x8000;
		delay(200);
	}
}
void delay(int n)
    {
	int i;
	for (; n > 0; n--)
	    for (i = 0; i < 3195; i++);
	}



#include "stm32f4xx.h"


void USART2_init (void);
char USART2_read (void);
void LED_play(int value);
void delayMs(int delay);

int main (void) {

   char c;

   RCC->AHB1ENR |=  8;             /* enable GPIOD clock */
   GPIOA->MODER |=  0x10000000;    /* set pin to output mode */

	USART2_init();          /* initialize USART2 */

    while(1) {
        c = USART2_read();
        LED_play(c);
    }
}



void USART2_init (void) {

    RCC->APB1ENR |= 0x20000;
    RCC->AHB1ENR |= 1;
    GPIOA->AFR[0] |=  0x7000;
    GPIOA->MODER  |=  0x0080;   /* Set PA3 to alternate function */


    USART2->BRR = 0x008B;       // 115200   @ 16 MHz
    USART2->CR1 = 0x0004;       // enable Tx
    USART2->CR1 |= 0x2000;      // enable USART2
}

/* Read a character from USART2 */
char USART2_read(void) {
    while (!(USART2->SR & 0x0020)) {}   // wait until char arrives
    return USART2->DR;
}

/* turn on or off the LEDs according to the value */
void LED_play(int value) {
    value %= 16;                    /* cap the max count at 15 */

    for (; value > 0; value--) {
    	GPIOD->BSRR = 0x4000;    // 0000 0000 0000 0000 0100 0000 0000 0000
        delayMs(100);
    	GPIOD->BSRR = 0x40000000;    // 0100 0000 0000 0000 0000 0000 0000 0000
    	delayMs(100);

    delayMs(400);
}
}
void delayMs(int delay) {
    int i;
    for (; delay > 0; delay--)
        for (i = 0; i < 3195; i++) ;
}


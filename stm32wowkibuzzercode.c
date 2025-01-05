#include "stdio.h"
#include "stm32c0xx.h"
// Connect LED to PC8
#define GPIOCEN (1U<<2) // enable port C
#define LED (1U<<8) // LED is connected to 8th pin of C port
int main()
{
    RCC->IOPENR|=(1<<0); // Enable GPIOA
    RCC->IOPENR|=(1<<1); // Enable GPIOBGPIOB->MODER |= (1U<<16);// Mode 8 is used so 16 pin set to high
    GPIOB->MODER &=~(1U<<17);// Mode 8 is used so 17 pin set to Low
    GPIOC->MODER |= (1U<<16);// Mode 8 is used so 16 pin set to high

while(1)
{
GPIOB->ODR|=LED; // LED is connected in current sinking so 
for (volatile int i=0; i<10000; i++); 
GPIOB->ODR&=~LED;
for (volatile int i=0; i<10000; i++); 
}
}
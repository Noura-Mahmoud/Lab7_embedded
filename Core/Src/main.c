#include "GPIO.h"

#define GPIO_REG(PORT_ID,REG_ID)  (unsigned int*)(PORT_ID + REG_ID) //The Generic macro
#define RCC_APB2ENR               GPIO_REG(0x40023800 , 0x44) //RCC APB2 peripheral clock enable register
#define SYSCFG_EXTICR1        	  GPIO_REG(0x40013800 , 0x08) //SYSCFG external interrupt configuration register 1
#define EXTI_IMR              	  GPIO_REG(0x40013C00 , 0x00) //Interrupt mask register
#define EXTI_FTSR              	  GPIO_REG(0x40013C00 , 0x0C) //Falling trigger selection register
#define EXTI_RTSR				  GPIO_REG(0x40013C00 , 0x08) //Rising trigger selection register
#define EXTI_PR           	      GPIO_REG(0x40013C00 , 0x14) //Pending register
#define NVIC_ISER0  	  	  	  (unsigned int*)(0xE000E100) //Interrupt set-enable register
#define NVIC_ICER0          	  (unsigned int*)(0XE000E180) //Interrupt clear-enable register

int main(void)
{
    unsigned char button_port = 0;
	unsigned char led_port = 0;
	unsigned char button_pin = 0;
	unsigned char led_pin = 1;
    
	GPIO_Init( button_port , button_pin , INPUT,PULL_UP); // push button PA 0 // make sure the clock is enabled
	GPIO_Init( led_port , led_pin , OUTPUT,PUSH_PULL); // LED PA 1 // make sure the clock is enabled

	(*RCC_APB2ENR) |= 0x00004000;  // enable system config on pin 14
	(*SYSCFG_EXTICR1) |= 0x00000000; // enable external interrupt 0
	(*EXTI_IMR) |= 0x00000001; // not masking line 0
	(*EXTI_FTSR) |= 0x00000001; // enable falling edge for line 0 (button)
	(*EXTI_RTSR) |= 0x00000000; // disable rising edge for line 0 (button)

	(*NVIC_ISER0) = 1<<6; // enable interrupt

	while(1)
	{
	}
	  return 0;
}

void toggle_led_by_interrupt()
	{
		unsigned char led_port = 0;
		unsigned char led_pin = 1;
		unsigned char Data;

		Data = !GPIO_ReadPin(led_port,led_pin) ;
		GPIO_WritePin(led_port, led_pin, Data);

		*EXTI_PR = 0x00000001; // clear PR0 by setting it to 1

	}




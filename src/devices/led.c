#include "led.h"

void LED1_Config_Request(void)
{
	/* Set the PIO_7 as output */
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, LED1_PORT, LED1_BIT);
}

void LED2_Config_Request(void)
{
	// LED2 P1_0 out
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, LED2_PORT, LED2_BIT);
}

void LED3_Config_Request(void)
{
	// LED3 P1_4 out
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, LED3_PORT, LED3_BIT);
}

void LED4_Config_Request(void)
{
	// LED4 P1_5 out
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, LED4_PORT, LED4_BIT);
}

//=======================
// Set LED State
//=======================
void LED_Set_Request(led_name_t led_num, bool state)
{
	if(led_num == LED1)
		Chip_GPIO_SetPinState(LPC_GPIO, LED1_PORT, LED1_BIT, state);
	if(led_num == LED2)
		Chip_GPIO_SetPinState(LPC_GPIO, LED2_PORT, LED2_BIT, state);
	if(led_num == LED3)
		Chip_GPIO_SetPinState(LPC_GPIO, LED3_PORT, LED3_BIT, state);
	if(led_num == LED4)
		Chip_GPIO_SetPinState(LPC_GPIO, LED4_PORT, LED4_BIT, state);
}

void LED_off_request(led_name_t led_num)
{
	if(led_num == LED1)
		Chip_GPIO_SetPinState(LPC_GPIO, LED1_PORT, LED1_BIT, true);
	if(led_num == LED2)
		Chip_GPIO_SetPinState(LPC_GPIO, LED2_PORT, LED2_BIT, true);
	if(led_num == LED3)
		Chip_GPIO_SetPinState(LPC_GPIO, LED3_PORT, LED3_BIT, true);
	if(led_num == LED4)
		Chip_GPIO_SetPinState(LPC_GPIO, LED4_PORT, LED4_BIT, true);
}

void LED_on_request(led_name_t led_num)
{
	if(led_num == LED1)
		Chip_GPIO_SetPinState(LPC_GPIO, LED1_PORT, LED1_BIT, false);
	if(led_num == LED2)
		Chip_GPIO_SetPinState(LPC_GPIO, LED2_PORT, LED2_BIT, false);
	if(led_num == LED3)
		Chip_GPIO_SetPinState(LPC_GPIO, LED3_PORT, LED3_BIT, false);
	if(led_num == LED4)
		Chip_GPIO_SetPinState(LPC_GPIO, LED4_PORT, LED4_BIT, false);
}

#include "sw.h"

uint32_t SW_Status_Read_Request(enum SW_NAME sw_num)
{
	bool status;

	if(sw_num == SW1)
		status = Chip_GPIO_GetPinState(LPC_GPIO, SW1_PORT, SW1_BIT);
	if(sw_num == SW2)
		status = Chip_GPIO_GetPinState(LPC_GPIO, SW2_PORT, SW2_BIT);
	if(sw_num == SW3)
		status = Chip_GPIO_GetPinState(LPC_GPIO, SW3_PORT, SW3_BIT);
	if(sw_num == SW4)
		status = Chip_GPIO_GetPinState(LPC_GPIO, SW4_PORT, SW4_BIT);

	return (uint32_t)status;
}


void SW1_Config_Request(void)
{
	/* Configure GPIO pin as input pin */
	Chip_GPIO_SetPinDIRInput(LPC_GPIO, SW1_PORT, SW1_BIT);
#if SW_INTERRUPT == 1
	SW_interrupt_request(SW1);
#endif
}

void SW2_Config_Request(void)
{
	/* Configure GPIO pin as input pin */
	Chip_GPIO_SetPinDIRInput(LPC_GPIO, SW2_PORT, SW2_BIT);
#if SW_INTERRUPT == 1
	SW_interrupt_request(SW2);
#endif
}

void SW3_Config_Request(void)
{
	/* Configure GPIO pin as input pin */
	Chip_GPIO_SetPinDIRInput(LPC_GPIO, SW3_PORT, SW3_BIT);
#if SW_INTERRUPT == 1
	SW_interrupt_request(SW3);
#endif
}

void SW4_Config_Request(void)
{
	/* Configure GPIO pin as input pin */
	Chip_GPIO_SetPinDIRInput(LPC_GPIO, SW4_PORT, SW4_BIT);
#if SW_INTERRUPT == 1
	SW_interrupt_request(SW4);
#endif
}

void SW_interrupt_request(enum SW_NAME sw_num)
{
	if(sw_num == SW1) {
		/* Configure channel interrupt as edge sensitive and falling edge interrupt */
		Chip_GPIO_SetPinModeEdge(LPC_GPIO, SW1_PORT, (1 << SW1_BIT));
		Chip_GPIO_SetEdgeModeSingle(LPC_GPIO, SW1_PORT, (1 << SW1_BIT));
		Chip_GPIO_SetModeLow(LPC_GPIO, SW1_PORT, (1 << SW1_BIT));
		/* The 3 above calls can be done with a single call as follows:
	   	   Chip_GPIO_SetupPinInt(LPC_GPIO, GPIO_PININT_PORT, GPIO_PININT, GPIO_INT_FALLING_EDGE); */

		/* Enable GPIO pin intrerrupt */
		Chip_GPIO_EnableInt(LPC_GPIO, SW1_PORT, (1 << SW1_BIT));
		if(SW1_PORT){
			/* Enable interrupt in the NVIC */
			NVIC_EnableIRQ(EINT1_IRQn);
		} else {
			NVIC_EnableIRQ(EINT0_IRQn);
		}
	}
	if(sw_num == SW2) {
		/* Configure channel interrupt as edge sensitive and falling edge interrupt */
		Chip_GPIO_SetPinModeEdge(LPC_GPIO, SW2_PORT, (1 << SW2_BIT));
		Chip_GPIO_SetEdgeModeSingle(LPC_GPIO, SW2_PORT, (1 << SW2_BIT));
		Chip_GPIO_SetModeLow(LPC_GPIO, SW2_PORT, (1 << SW2_BIT));
		/* The 3 above calls can be done with a single call as follows:
	   	   Chip_GPIO_SetupPinInt(LPC_GPIO, GPIO_PININT_PORT, GPIO_PININT, GPIO_INT_FALLING_EDGE); */

		/* Enable GPIO pin intrerrupt */
		Chip_GPIO_EnableInt(LPC_GPIO, SW2_PORT, (1 << SW2_BIT));
		if(SW2_PORT){
			/* Enable interrupt in the NVIC */
			NVIC_EnableIRQ(EINT1_IRQn);
		} else {
			NVIC_EnableIRQ(EINT0_IRQn);
		}
	}
	if(sw_num == SW3) {
		/* Configure channel interrupt as edge sensitive and falling edge interrupt */
		Chip_GPIO_SetPinModeEdge(LPC_GPIO, SW3_PORT, (1 << SW3_BIT));
		Chip_GPIO_SetEdgeModeSingle(LPC_GPIO, SW3_PORT, (1 << SW3_BIT));
		Chip_GPIO_SetModeLow(LPC_GPIO, SW3_PORT, (1 << SW3_BIT));
		/* The 3 above calls can be done with a single call as follows:
	   	   Chip_GPIO_SetupPinInt(LPC_GPIO, GPIO_PININT_PORT, GPIO_PININT, GPIO_INT_FALLING_EDGE); */

		/* Enable GPIO pin intrerrupt */
		Chip_GPIO_EnableInt(LPC_GPIO, SW3_PORT, (1 << SW3_BIT));
		if(SW3_PORT){
			/* Enable interrupt in the NVIC */
			NVIC_EnableIRQ(EINT1_IRQn);
		} else {
			NVIC_EnableIRQ(EINT0_IRQn);
		}

	}
	if(sw_num == SW4) {
		/* Configure channel interrupt as edge sensitive and falling edge interrupt */
		Chip_GPIO_SetPinModeEdge(LPC_GPIO, SW3_PORT, (1 << SW4_BIT));
		Chip_GPIO_SetEdgeModeSingle(LPC_GPIO, SW4_PORT, (1 << SW4_BIT));
		Chip_GPIO_SetModeLow(LPC_GPIO, SW4_PORT, (1 << SW4_BIT));
		/* The 3 above calls can be done with a single call as follows:
	   	   Chip_GPIO_SetupPinInt(LPC_GPIO, GPIO_PININT_PORT, GPIO_PININT, GPIO_INT_FALLING_EDGE); */

		/* Enable GPIO pin intrerrupt */
		Chip_GPIO_EnableInt(LPC_GPIO, SW4_PORT, (1 << SW4_BIT));
		if(SW4_PORT){
			/* Enable interrupt in the NVIC */
			NVIC_EnableIRQ(EINT1_IRQn);
		} else {
			NVIC_EnableIRQ(EINT0_IRQn);
		}
	}
}


#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>

// TODO: insert other include files here
#include "tx_api.h"
#include "sw.h"

// TODO: insert other definitions and declarations here
extern TX_EVENT_FLAGS_GROUP    event_flags_0;

void PIOINT1_IRQHandler(void)
{
	uint32_t sw = Chip_GPIO_GetMaskedInts(LPC_GPIO, 1);
	UINT    status;

    if (sw&(1<<SW1_BIT))  {
    	/* Clear interrupt */
    	Chip_GPIO_ClearInts(LPC_GPIO, SW1_PORT, (1 << SW1_BIT));

    	/* Set event flag 0 to wakeup thread 1.  */
    	status =  tx_event_flags_set(&event_flags_0, 0x1, TX_OR);
    	/* Check status.  */
    	if (status != TX_SUCCESS) while(1);
    }

    if (sw&(1<<SW2_BIT))  {
    	/* Clear interrupt */
    	Chip_GPIO_ClearInts(LPC_GPIO, SW2_PORT, (1 << SW2_BIT));
    }
}

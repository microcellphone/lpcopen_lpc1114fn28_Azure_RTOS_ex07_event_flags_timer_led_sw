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
#include "my_timer.h"

// TODO: insert other definitions and declarations here
extern TX_EVENT_FLAGS_GROUP    event_flags_0;

void TIMER16_0_IRQHandler(void)
{
	UINT    status;

	if (Chip_TIMER_MatchPending(LPC_TIMER16_0, TIMER0)) {
		Chip_TIMER_ClearMatch(LPC_TIMER16_0, TIMER0);
	}

	if (Chip_TIMER_MatchPending(LPC_TIMER16_0, TIMER1)) {
		Chip_TIMER_ClearMatch(LPC_TIMER16_0, TIMER1);

		/* Set event flag 0 to wakeup thread 2.  */
		status =  tx_event_flags_set(&event_flags_0, 0x2, TX_OR);
		/* Check status.  */
		if (status != TX_SUCCESS) while(1);
	}

	if (Chip_TIMER_MatchPending(LPC_TIMER16_0, TIMER2)) {
		Chip_TIMER_ClearMatch(LPC_TIMER16_0, TIMER2);
	}

	if (Chip_TIMER_MatchPending(LPC_TIMER16_0, TIMER3)) {
		Chip_TIMER_ClearMatch(LPC_TIMER16_0, TIMER3);
	}
}

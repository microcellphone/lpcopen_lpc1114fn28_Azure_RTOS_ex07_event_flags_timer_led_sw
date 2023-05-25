#ifndef __MY_TIMER_H__
#define __MY_TIMER_H__
#include "chip.h"

enum MR_NUM {
	MR0 = 0,
	MR1 = 1,
	MR2 = 2,
	MR3 = 3,
};

typedef enum TIMER_NUM {
	TIMER0 = MR0,
	TIMER1 = MR1,
	TIMER2 = MR2,
	TIMER3 = MR3,
} timer_num_t;

typedef enum CAP_NUM {
	CAP0 = 0,
	CAP1 = 1,
} cap_num_t;

extern void TIMER_Config_Request(LPC_TIMER_T *pTMR, timer_num_t timer_id, uint32_t tickrate_hz);
extern void TIMER_Capture_Request(LPC_TIMER_T *pTMR, cap_num_t cap_id, uint32_t tickrate_hz);
//

#endif // __MY_TIMER_H__

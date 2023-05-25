#include "my_timer.h"

void TIMER_Config_Request(LPC_TIMER_T *pTMR, timer_num_t timer_id, uint32_t tickrate_hz)
{
    uint32_t timerFreq;

    /* Enable timer 1 clock */
    Chip_TIMER_Init(pTMR);

    /* Timer rate is system clock rate */
    timerFreq = Chip_Clock_GetSystemClockRate();

    /* Timer setup for match and interrupt at TICKRATE_HZ */
    Chip_TIMER_Reset(pTMR);
    Chip_TIMER_MatchEnableInt(pTMR, timer_id);
    Chip_TIMER_SetMatch(pTMR, timer_id, (timerFreq / tickrate_hz));
    Chip_TIMER_ResetOnMatchEnable(pTMR, timer_id);
    Chip_TIMER_Enable(pTMR);

    /* Enable timer interrupt */
    if(pTMR == LPC_TIMER16_0){
    	NVIC_ClearPendingIRQ(TIMER_16_0_IRQn);
    	NVIC_EnableIRQ(TIMER_16_0_IRQn);
    }
    if(pTMR == LPC_TIMER16_1){
    	NVIC_ClearPendingIRQ(TIMER_16_1_IRQn);
    	NVIC_EnableIRQ(TIMER_16_1_IRQn);
    }
    if(pTMR == LPC_TIMER32_0){
    	NVIC_ClearPendingIRQ(TIMER_32_0_IRQn);
    	NVIC_EnableIRQ(TIMER_32_0_IRQn);
    }
    if(pTMR == LPC_TIMER32_1){
    	NVIC_ClearPendingIRQ(TIMER_32_1_IRQn);
    	NVIC_EnableIRQ(TIMER_32_1_IRQn);
    }
}

void TIMER_Capture_Request(LPC_TIMER_T *pTMR, cap_num_t cap_id, uint32_t tickrate_hz)
{
    Chip_TIMER_Init(pTMR);
    Chip_TIMER_Reset(pTMR);
    Chip_TIMER_PrescaleSet(pTMR, SystemCoreClock / tickrate_hz - 1);

    Chip_TIMER_CaptureFallingEdgeEnable(pTMR, cap_id);
    Chip_TIMER_CaptureEnableInt(pTMR, cap_id);

    if(pTMR == LPC_TIMER16_0){
    	NVIC_ClearPendingIRQ(TIMER_16_0_IRQn);
    	NVIC_EnableIRQ(TIMER_16_0_IRQn);
    }
    if(pTMR == LPC_TIMER16_1){
    	NVIC_ClearPendingIRQ(TIMER_16_1_IRQn);
    	NVIC_EnableIRQ(TIMER_16_1_IRQn);
    }
    if(pTMR == LPC_TIMER32_0){
    	NVIC_ClearPendingIRQ(TIMER_32_0_IRQn);
    	NVIC_EnableIRQ(TIMER_32_0_IRQn);
    }
    if(pTMR == LPC_TIMER32_1){
    	NVIC_ClearPendingIRQ(TIMER_32_1_IRQn);
    	NVIC_EnableIRQ(TIMER_32_1_IRQn);
    }
}

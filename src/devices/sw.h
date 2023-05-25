#ifndef __SW_H__
#define __SW_H__

#include "chip.h"

#define SW_INTERRUPT 1

#define SW1_PORT 1
#define SW1_BIT  8

#define SW2_PORT 1
#define SW2_BIT  9

#define SW3_PORT 0
#define SW3_BIT  1

#define SW4_PORT 0
#define SW4_BIT  3

typedef enum SW_NAME {
	SW1,
	SW2,
	SW3,
	SW4,
	SW_MAX
}sw_name_t;

typedef enum SW_STATUS {
	OFF,
	ON,
} sw_status_t;

extern uint32_t SW_Status_Read_Request(enum SW_NAME sw_num);

void SW1_Config_Request(void);
void SW2_Config_Request(void);
void SW3_Config_Request(void);
void SW4_Config_Request(void);

void SW_interrupt_request(enum SW_NAME sw_num);


#endif // __SW_H__

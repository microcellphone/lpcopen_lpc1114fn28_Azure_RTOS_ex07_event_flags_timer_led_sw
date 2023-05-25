#ifndef __LED_H__
#define __LED_H__

#include "chip.h"

#define LED1_PORT 0
#define LED1_BIT  7

#define LED2_PORT 1
#define LED2_BIT  0

#define LED3_PORT 1
#define LED3_BIT  4

#define LED4_PORT 1
#define LED4_BIT  5

typedef enum LED_NAME {
	LED1,
	LED2,
	LED3,
	LED4,
	LED_MAX
} led_name_t;

extern void LED1_Config_Request(void);
extern void LED2_Config_Request(void);
extern void LED3_Config_Request(void);
extern void LED4_Config_Request(void);
extern void LED_Set_Request(led_name_t led_num, bool state);
extern void LED_on_request(led_name_t led_num);
extern void LED_off_request(led_name_t led_num);

#endif // _LED_H__

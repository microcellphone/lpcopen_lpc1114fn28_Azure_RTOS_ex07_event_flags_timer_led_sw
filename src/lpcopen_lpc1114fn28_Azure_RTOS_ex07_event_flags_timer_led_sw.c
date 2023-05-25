#include "tx_api.h"
#include "led.h"
#include "sw.h"
#include "my_iocon.h"
#include "my_timer.h"

#define TICKRATE_HZ (10) /* 10 ticks per second */

#define DEMO_STACK_SIZE         400
#define DEMO_BYTE_POOL_SIZE     1024
#define DEMO_BLOCK_POOL_SIZE    10
#define DEMO_QUEUE_SIZE         10


/* Define the ThreadX object control blocks...  */

TX_THREAD               thread_1;
TX_THREAD               thread_2;
TX_EVENT_FLAGS_GROUP    event_flags_0;
TX_BYTE_POOL            byte_pool_0;
UCHAR                   memory_area[DEMO_BYTE_POOL_SIZE];


/* Define the counters used in the demo application...  */


/* Define thread prototypes.  */

void    thread_1_entry(ULONG thread_input);
void    thread_2_entry(ULONG thread_input);


/* Define main entry point.  */

int main()
{
    IOCON_Config_Request();
    LED1_Config_Request();
    SW1_Config_Request();
    LED_on_request(LED1);
    TIMER_Config_Request(LPC_TIMER16_0, TIMER1, TICKRATE_HZ);

    /* Enter the ThreadX kernel.  */
    tx_kernel_enter();
}


/* Define what the initial system looks like.  */

void    tx_application_define(void *first_unused_memory)
{
	CHAR    *pointer = TX_NULL;
	UINT status;

    /* Create a byte memory pool from which to allocate the thread stacks.  */
	status = tx_byte_pool_create(&byte_pool_0, "byte pool 0", memory_area, DEMO_BYTE_POOL_SIZE);
    if(status != TX_SUCCESS) while(1);

    /* Put system definition stuff in here, e.g. thread creates and other assorted
       create information.  */

    /* Allocate the stack for thread 1.  */
    status = tx_byte_allocate(&byte_pool_0, (VOID **) &pointer, DEMO_STACK_SIZE, TX_NO_WAIT);
    if(status != TX_SUCCESS) while(1);

    /* Create threads 1 and 2. These threads pass information through a ThreadX 
       message queue.  It is also interesting to note that these threads have a time
       slice.  */
    status = tx_thread_create(&thread_1, "thread 1", thread_1_entry, 1,
            pointer, DEMO_STACK_SIZE, 
            8, 8, TX_NO_TIME_SLICE, TX_AUTO_START);
    if(status != TX_SUCCESS) while(1);

    /* Allocate the stack for thread 2.  */
    status = tx_byte_allocate(&byte_pool_0, (VOID **) &pointer, DEMO_STACK_SIZE, TX_NO_WAIT);
    if(status != TX_SUCCESS) while(1);

    status = tx_thread_create(&thread_2, "thread 2", thread_2_entry, 2,
            pointer, DEMO_STACK_SIZE, 
            8, 8, TX_NO_TIME_SLICE, TX_AUTO_START);
    if(status != TX_SUCCESS) while(1);

    /* Allocate the message queue.  */
    status = tx_byte_allocate(&byte_pool_0, (VOID **) &pointer, DEMO_QUEUE_SIZE*sizeof(ULONG), TX_NO_WAIT);
    if(status != TX_SUCCESS) while(1);

    /* Create the event flags group for threads 1.  */
    status = tx_event_flags_create(&event_flags_0, "event flags 0");
    if(status != TX_SUCCESS) while(1);

    /* Release the block back to the pool.  */
    status = tx_byte_release(pointer);
    if(status != TX_SUCCESS) while(1);
}


void    thread_1_entry(ULONG thread_input)
{
	UINT    status;
	ULONG   actual_flags;

    while(1) {
        /* Wait for event flag 0.  */
        status =  tx_event_flags_get(&event_flags_0, 0x1, TX_OR_CLEAR, &actual_flags, TX_WAIT_FOREVER);
        /* Check status.  */
        if ((status != TX_SUCCESS) || ((actual_flags&0x1) != 0x1)) while(1);

        LED_on_request(LED1);
        status = tx_thread_sleep(1000);
        /* Check status.  */
        if (status != TX_SUCCESS) while(1);
    }
}


void    thread_2_entry(ULONG thread_input)
{
	UINT    status;
	ULONG   actual_flags;


    while(1) {
        /* Wait for event flag 0.  */
        status =  tx_event_flags_get(&event_flags_0, 0x2, TX_OR_CLEAR, &actual_flags, TX_WAIT_FOREVER);
        /* Check status.  */
        if ((status != TX_SUCCESS) || ((actual_flags&0x2) != 0x2)) while(1);

        LED_off_request(LED1);
        status = tx_thread_sleep(1000);
        /* Check status.  */
        if (status != TX_SUCCESS) while(1);
    }
}



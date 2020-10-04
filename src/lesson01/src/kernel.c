#include "uart.h"

void say_hello(unsigned int core_id);
void uart_lock(unsigned int core_id);
void uart_unlock(unsigned int core_id);

static unsigned int master_ready = 0;
static unsigned int uart_semaphor = 0;

void kernel_main(unsigned int core_id)
{
	if(core_id == 0)
	{
		uart_init();
		master_ready = 1;
	}
	else
	{
		//delay(1000 * core_id);
		while(master_ready==0){}
	}

	say_hello(core_id);
	
	while(1)
		;
	/*if(core_id == 0)
	{
		while (1) {
//			uart_lock(core_id);
			uart_send(uart_recv());
//			uart_unlock(core_id);
		}
	}*/
}

void say_hello(unsigned int core_id)
{
	uart_lock(core_id);
	uart_send_string("Hello, world! from processor");
	uart_send(core_id + '0');
	uart_send_string("\r\n");
	uart_unlock(core_id);
}

void uart_lock(unsigned int core_id){
	while(uart_semaphor != 0)
	{
	}
	uart_semaphor= core_id;
}

void uart_unlock(unsigned int core_id)
{
	if(uart_semaphor == core_id)
	{
		uart_semaphor = 0;
	}
}

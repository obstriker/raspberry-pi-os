#include "peripherals/gpio.h"
#include "peripherals/uart.h"
#include "utils.h"

void uart_init(void) {
    unsigned int selector;  // 32 bits

    selector = get32(GPFSEL1);
    selector &= ~(7 << 12);
    selector |= 4 << 12;
    selector &= ~(7 << 15);
    selector |= 4 << 15;
    put32(GPFSEL1, selector);

    put32(GPPUD, 0);
    delay(150);
    put32(GPPUDCLK0, (1 << 14) | (1 << 15));
    delay(150);
    put32(GPPUDCLK0, 0);

    put32(UART_CR, 0); // Disable UART for configuration

    //calculation determined in the manual page 3-10
    put32(UART_IBRD, 26); // 48Mhz / (16 x 115200) = 26.041667
    put32(UART_FBRD, 3) ; // int((0.041667*64)+0.5)) = 3

    put32(UART_LCRH, 0x60);

    put32(UART_CR, 0x301); // Enable uart
    
}

void uart_send(char c){ 
    while(get32(UART_FR) & 0x80){ // while transmit register is not empty
	    put32(UART_DR, c);
	    break;
    }
}

char uart_recv(void) {
	while(1)
	{
	    if(get32(UART_FR) & 0x40)
	    {
		    return get32(UART_DR) & 0xFF;
	    }
	}
}

void uart_send_string(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        uart_send((char)str[i]);
    }
}

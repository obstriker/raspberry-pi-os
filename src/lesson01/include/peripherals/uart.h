#ifndef	_P_MINI_UART_H
#define	_P_MINI_UART_H

#include "peripherals/base.h"

#define AUX_ENABLES     (PBASE+0x00215004)
#define AUX_MU_IO_REG   (PBASE+0x00215040)
#define AUX_MU_IER_REG  (PBASE+0x00215044)
#define AUX_MU_IIR_REG  (PBASE+0x00215048)
#define AUX_MU_LCR_REG  (PBASE+0x0021504C)
#define AUX_MU_MCR_REG  (PBASE+0x00215050)
#define AUX_MU_LSR_REG  (PBASE+0x00215054)
#define AUX_MU_MSR_REG  (PBASE+0x00215058)
#define AUX_MU_SCRATCH  (PBASE+0x0021505C)
#define AUX_MU_CNTL_REG (PBASE+0x00215060)
#define AUX_MU_STAT_REG (PBASE+0x00215064)
#define AUX_MU_BAUD_REG (PBASE+0x00215068)


#define UART_BASE	(PBASE+0x00201000)
#define UART_DR		(UART_BASE+0x0000)
#define UART_RSRECR	(UART_BASE+0x0004)
#define UART_FR		(UART_BASE+0x0018)
#define UART_CR		(UART_BASE+0x0030)
#define UART_IBRD	(UART_BASE+0x0024)
#define UART_FBRD	(UART_BASE+0x0028)
#define UART_LCRH	(UART_BASE+0x002c)

#endif  /*_P_MINI_UART_H */
#include "mm.h"

.section ".text.boot"

.global wakeup_core
.globl _start
_start:
	mrs	x0, mpidr_el1
	and	x0, x0,#0xFF		// Check processor id
	cbz	x0, master		// Hang for all non-primary CPU

	mov	x0, #1000
	bl	delay
	b	init_stack


wakeup_core:
        mov x2, 0xd8
        str x1, [x2, x0, LSL #3]
        sev
        ret

proc_hang:
	b proc_hang

wakeup_cores:
	
	bl	wakeup_core


	ret
	

master:
	adr	x0, bss_begin
	adr	x1, bss_end
	sub	x1, x1, x0
	bl 	memzero

	mov	x0, #1
	adr	x1, _start
	bl	wakeup_core

	add	x0, x0, #1
	bl	wakeup_core

	add	x0, x0, #1
	bl	wakeup_core


	b	init_stack

init_stack:
	mrs	x0, mpidr_el1
	and	x0, x0,#0xFF //check processor id
	mov	x1,#0x1000 // define 4kb stack for each core.
	mul	x1, x1,x0
	mov	x2, #LOW_MEMORY
	add	x1, x1,x2
	mov	sp, x1
	
	bl	kernel_main
	b	proc_hang

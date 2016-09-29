@ crt0.S: Execution startup routine
@
@ Authors: Jiaming XIao <jiamingx@andrew.cmu.edu>
@          Group Member 2 <email address>
@ Date:    The current time & date
#include <bits/swi.h>
	.file	"crt0.S"
	.text

	.global	_start
_start:
	ldr r0, [sp]
        mov r1, sp
        add r1, r1, #4
        bl  main

        swi EXIT_SWI        
        

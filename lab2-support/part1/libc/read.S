@ read.S: read sycall wrapper
@
@ Authors: Jiaming Xiao <jiamingx@andrew.cmu.edu>
@          Group Member 2 <email address>
@ Date:    The current time & date
#include <bits/swi.h>

	.file	"read.S"
	.text
	.global	read
read:
	stmfd sp!, {r1}
        swi READ_SWI
        cmp r0, #0     @ Check error
        bge return

        ldr r1, =_errno  @ Get address of global errno
        mvn r0, r0
        add r0, r0, #1
	str r0, [r1]
        mvn r0, #0 

return:
	ldmfd sp!, {r1}
        mov   pc, lr

_errno:
        .word errno

@ exit.S: exit sycall wrapper
@
@ Authors: Jiaming Xiao <jiamingx@andrew.cmu.edu>
@          Group Member 2 <email address>
@ Date:    The current time & date
#include <bits/swi.h>
	.file	"exit.S"
	.text

	.global	exit
exit:
	mov r0, #0
        swi EXIT_SWI

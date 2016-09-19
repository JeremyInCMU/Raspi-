	.file	"part1-strTable.c"
	.text
	.align	2
	.global	strTable
	.type	strTable, %function
strTable:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, r5}    @ r4 is regarded as counter of loop
	mov	r4, r3
	cmp	r3, #0
	ble	.L11
.L9:
	ldrb	r5, [r1, r4]	@ reversely go through the string stored in r1
	sub	ip, r5, #23
	cmp	ip, #22
	ble	.L13
.L7:
	sub	ip, ip, #23
	cmp	ip, #22
	bgt	.L7
.L13:
	cmp	ip, r2
	bgt	.L4
        ldrb    r3, [r0, ip]
	cmp	r5, r3
	strneb	r5, [r0, ip]
.L4:
	sub	r4, r4, #1   @ replace the add up to loop by counting down one
	cmp	r4, #0
	bgt	.L9
.L11:
	ldmfd	sp!, {r4, r5}
	mov pc, lr
	.size	strTable, .-strTable
	.ident	"GCC: (GNU) 3.4.5"

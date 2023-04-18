.globl main
.text
main:
	li t0, 0
	li t1, 100
	li t2, 0
	la t3, arr
	li t4, 1000

loop:
	li a0, 1
	li a1, 1000
	li a7, 42
	ecall
	sw a0, (t3)
	add t2, t2, a0
	addi t3, t3, 4
	addi t0, t0, 1
	blt t0, t1, loop

	fcvt.s.w f0, t2
	fcvt.s.w f1, t1
	fdiv.s f2, f0, f1

	fcvt.w.s t6, f2
	mv a0, t6

	li a7, 1
	ecall

	li a0, 10
	li a7, 11
	ecall

	li a7, 10
	ecall

	.data
arr:
	.space 500
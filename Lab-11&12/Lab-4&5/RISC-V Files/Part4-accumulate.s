.globl main
.text
main:
	li t0, 1 
	li t1, 101 
	li t2, 0 

loop:
	add t2, t2, t0
	addi t0, t0, 1
	bne t0, t1, loop

	la a0, sum_msg 
	li a7, 4 
	ecall
	
	add a0, t2, x0 
	li a7, 1 
	ecall

	li a0, 10
	li a7, 17
	ecall

	.data
	sum_msg: .asciiz "The sum is: "
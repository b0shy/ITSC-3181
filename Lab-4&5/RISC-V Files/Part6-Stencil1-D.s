.globl main
.data 
.align 2 


randArray: .space 408
stencilArray:   .space 400
arrayL:	   .asciz "Elements of the array::"
elemN:	   .asciz "\nElement number "
colon:	.asciz "::"
stencilL:  .asciz "\n1D Stencil of the random array::"
nothing:   .asciz "\n"

.text
main:
    la t0,randArray
    addi t0,t0,4
    li t1,0 
loop:
    add a0,t1,zero
    addi a1,zero,100
    li a7,42 
    ecall
    sw a0,(t0)
    addi t0,t0,4
    addi t1,t1,1 
    li t5,100
    bne t1,t5,loop
    la a0,arrayL
    la a1,elemN
    la a2,randArray
    addi a2,a2,4
    jal printArray
    la a0,randArray
    addi a0,a0,4
    la a1,stencilArray
    li s0,0
    li s1,2
    li s2,4
stencil:
    li a5,0
    addi t1,s0,-4
    add t1,a0,t1
    lw a2,(t1)
    divu a2,a2,s2
    add a5,a5,a2
    addi t1,t1,4
    lw a3,(t1)
    divu a3,a3,s1
    add a5,a5,a3
    addi t1,t1,4
    lw a4,(t1)
    divu a4,a4,s2
    add a5,a5,a4
    add t1,a1,s0
    sw a5,(t1)
    addi s0,s0,4
    li t5,400   
    bne s0,t5,stencil
    la a0,stencilL
    la a1,nothing
    la a2,stencilArray
    jal printArray
    li a0,0
    li a7,93 
    ecall
printArray:
    add t0,a0,zero
    add t1,a1,zero
    add t2,a2,zero
    li a1,100
    li a7,4
    ecall
    li t3,0
    li t4,1
    li t5,400
printLoop:
    add a0,t1,zero
    li a1,100
    li a7,4
    ecall
    add a0,t4,zero
    li a7,1
    ecall
    la a0,colon
    li a1,100
    li a7,4
    ecall
    add s2,t2,t3
    lw a0,(s2)
    li a7,1
    ecall
    addi t3,t3,4
    addi t4,t4,1
    bne t3,t5,printLoop
    jr ra
# Laboratory Exercise 7, Home Assignment 3
.text
push: 
	addi sp, sp, -4 # adjust the stack pointer
	sw s0, 0(sp) # push s0 to stack
	addi sp, sp, -4
	sw s1, 0(sp) # push s1 to stack
work:
	nop
	nop
	nop
pop: 
	lw s0, 0(sp) # pop from stack to s0
	addi sp, sp, 4
	lw s1, 0(sp) # pop from stack to s1
	addi sp, sp, 4 # adjust the stack pointer
.data
	message: 	.asciz "The sum of "
	message1: 	.asciz " and "
	message2: 	.asciz " is "

.text
	li 	a7, 5
	ecall
	addi 	t1, a0, 0

	
	li 	a7,5
	ecall
	addi 	t2,a0,0
	
	li 	a7, 4
	la 	a0, message
	ecall
	
	li 	a7,1
	addi 	a0,t1,0
	ecall
	
	li 	a7,4
	la 	a0,message1
	ecall
	
	li 	a7,1
	addi 	a0,t2,0
	ecall
	
	li 	a7,4
	la 	a0,message2
	ecall
	
	add 	t3, t1,t2
	li 	a7,1
	addi 	a0,t3,0
	ecall
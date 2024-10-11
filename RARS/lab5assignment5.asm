.data
	X: 	.space 100

.text
main:
	li 	t0,0
	addi 	t1,zero,20
	li 	t2,10
	la 	t3, X
	li 	a3,-1
	
loop:
	li 	a7,12
	ecall
	beq 	a0, t2, end_of_loop
	add 	t4,t3,t0
	sb 	a0, 0(t4)
	addi 	t0,t0,1
	beq 	t0,t1,end_of_loop
	j	loop
end_of_loop: 
string_rev:
	li 	a7,11
	li 	a0, 10
	ecall
loop1:
	add 	s0, t3,t0
	li 	a7, 11
	lb	a0, 0(s0)
	ecall
	addi	t0,t0,-1
	beq	t0,a3, end_of_loop1
	j	loop1
end_of_loop1:
	
	
.data
	x:	.space 100
	y:	.space 100
.text
	li	a7, 8
	la	a0, y
	li	a1, 100
	ecall
	la	a0, x
	la	a1, y
strcpy:
	add	s0, zero, zero
loop:
	add	t1, s0, a1
	lb	t2, 0(t1)
	add	t3, s0, a0
	sb	t2, 0(t3)
	beq	t2, zero, end_of_strcpy
	addi	s0, s0,1
	j	loop
end_of_strcpy:

	li	a7, 4
	la	a0, x
	ecall
	
	

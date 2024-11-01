.data
	x:	.word 0xaaaaffff
	y:	.word 0xaaaaffff
.text
	la	a1, x
	la	a2, y
	lw	s1, 0(a1)
	lw	s2, 0(a2)
	
	li 	t0, 0
	add	s3, s1, s2
	xor	t1, s1, s2
	blt	t1, zero, EXIT
	slt	t2, s3, s1
	blt	s1, zero, NEGATIVE
	beq	t2, zero, EXIT
	
	j	OVERFLOW
NEGATIVE:
	bne	t2, zero, EXIT
OVERFLOW:
	li	t0, 1
EXIT:
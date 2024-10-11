.data
	A:	.word	1, 3, 2, 5, 4, 7, 8, 9, 6
.text
	la	s1, A
	li	s2, 0	#sum
	li	s3, 0	#i
	li	s4, 9	#n
loop:
	blt	s4, s3, endloop
	add	t1, s3, s3
	add	t1, t1, t1
	add	t1, t1, s1
	lw	t0, 0(t1)
	add	s2, s2, t0
	addi	s3, s3, 1
	j loop
endloop:	
.data
	x:	.byte	20
	y:	.byte	-20
.text
	la	t0, x
	la	t1, y
	lb	s0, 0(t0)
	lbu	s1, 0(t0)
	lb	s2, 0(t1)
	lbu	s3, 0(t1)
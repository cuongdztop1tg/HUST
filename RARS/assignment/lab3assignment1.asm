.data
	i:	.word	2
	j:	.word	1
.text
start:
	la	a1, i		
	la	a2, j		
	lw	s1, 0(a1)	#load i to s1
	lw	s2, 0(a2)	#load j to s2
	
	blt	s2, s1, else

then:
	addi	t1, t1, 1	#x = x + 1
	addi	t3, zero, 1	#z = 1
	j	endif
else:
	addi	t2, t2, -1	#y = y - 1
	add	t3, t3, t3	#z = Z * 2
endif:
	
	
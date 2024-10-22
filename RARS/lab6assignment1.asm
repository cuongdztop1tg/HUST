.data
	A:	.word -2, 6, -1, 10, -11, 7, 3, -2
.text
main:
	la	a0, A
	li	a1, 8
	j	prefix
continue:
exit:
	li	a7, 10
	ecall
end_of_main:

prefix:
	li	s0, 0
	li	s1, 0x80000000
	li	t0, 0
	li	t1, 0
loop:
	add 	t2, t0, t0
	add 	t2, t2, t2
	add	t3, t2, a0
	lw	t4, 0(t3)
	add	t1, t1, t4
	blt	s1, t1, modify
	j 	next
modify:
	addi	s0, s0, 1
	addi	s1, t1, 0
next:
	addi 	t0, t0, 1
	blt	t0, a1, loop
done:
	j 	continue
prefix_sum_end:

	
	
.data
	test:	.word 0
.text
	la	s1, test
	lw	s0, 0(s1)
	li	t0, 0
	li	t1, 1
	li	t2, 2
	beq	s0, t0, case_0
	beq	s0, s1, case_1
	beq	s0, s2, case_2
	j	default
case_0:
	addi 	a1, a1, 1
	j continue
case_1:
	addi	a1, a1, -1
	j continue
case_2:
	add	a2, a2, a2
	j continue
default:
continue:
	
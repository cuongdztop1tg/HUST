.data
	x:	.word
.text
	li	s0, 0x12345678
	andi	t0, s0, 0xff
	andi	t1, s0, 0x0400
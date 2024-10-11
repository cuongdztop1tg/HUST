.data
	x:	.space 100
	message1:	.asciz "Nhap xau: "
	message2:	.asciz "Do dai xau la: "	
.text
input_string:
	li	a7, 54
	la	a0, message1
	la	a1, x
	li	a2, 100
	ecall
get_length:
	la	a0, x
	li	t0, 0
check_char:
	add 	t1, a0, t0
	lb	t2, 0(t1)
	beq	t2, zero, end_of_check_char
	addi	t0, t0, 1
	j	check_char
end_of_check_char:
end_of_get_length:
print:
	li	a7, 56
	la	a0, message2
	addi	a1, t0, -1
	ecall
	

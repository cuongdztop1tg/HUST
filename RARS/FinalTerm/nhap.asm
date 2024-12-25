.data
image:
.ascii	"                     \0                   \0 ************* \n"
.ascii	"**************       \0                   \0*3333333333333*\n"
.ascii	"*222222222222222*    \0                   \0*33333******** \n" 
.ascii	"*22222******222222*  \0                   \0*33333*        \n"
.ascii	"*22222*      *22222* \0                   \0*33333******** \n"
.ascii	"*22222*       *22222*\0     ************* \0*3333333333333*\n"
.ascii	"*22222*       *22222*\0   **11111*****111*\0*33333******** \n"
.ascii	"*22222*       *22222*\0 **1111**       ** \0*33333*        \n"
.ascii	"*22222*      *222222*\0 *1111*            \0*33333******** \n"
.ascii	"*22222*******222222* \0*11111*            \0*3333333333333*\n"
.ascii	"*2222222222222222*   \0*11111*            \0 ************* \n"
.ascii	"***************      \0*11111*            \0               \n"
.ascii	"      ---            \0 *1111**           \0               \n"
.ascii	"    / o o \\          \0  *1111****   *****\0               \n"
.ascii	"    \\  >  /          \0   **111111***111* \0               \n"
.ascii	"     -----           \0     ***********   \0dce.hust.edu.vn\n"
image_end:
concak:
.asciz	"CON CAK"
.text
	la	s0, image
	la	s1, image_end
	li	t1, 0	
	li	t2, '\n'
print_line:
	bgt	s0, s1, end
	addi	t1, s0, 42	#start of E
print_E:
	lb	t0, 0(t1)
	beq	t0, t2, print_C
	beqz	t0, print_C
	li	a7, 11
	mv	a0, t0
	ecall
	addi	t1, t1, 1
	j	print_E
print_C:
	li	a7, 11
	li	a0, 32
	ecall
	addi	t1, s0, 23
print_C_loop:
	lb	t0, 0(t1)
	beqz	t0, print_D
	li	a7, 11
	mv	a0, t0
	ecall
	addi	t1, t1, 1
	j	print_C_loop
print_D:
	li	a7, 11
	li	a0, 32
	ecall
	mv	t1, s0
print_D_loop:
	lb	t0, 0(t1)
	beqz	t0, new_line
	li	a7, 11
	mv	a0, t0
	ecall
	addi	t1, t1, 1
	j	print_D_loop
new_line:
	li	a7, 11
	li	a0, 10
	ecall
	addi	s0, s0, 58
	j	print_line
end:

	






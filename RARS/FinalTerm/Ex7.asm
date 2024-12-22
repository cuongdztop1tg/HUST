.data
image:
.ascii	"                                           *************       \n"
.ascii	"**************                            *3333333333333*      \n"
.ascii	"*222222222222222*                         *33333********       \n" 
.ascii	"*22222******222222*                       *33333*              \n"
.ascii	"*22222*      *22222*                      *33333********       \n"
.ascii	"*22222*       *22222*      *************  *3333333333333*      \n"
.ascii	"*22222*       *22222*    **11111*****111* *33333********       \n"
.ascii	"*22222*       *22222*  **1111**       **  *33333*              \n"
.ascii	"*22222*      *222222*  *1111*             *33333********       \n"
.ascii	"*22222*******222222*  *11111*             *3333333333333*      \n"
.ascii	"*2222222222222222*    *11111*              *************       \n"
.ascii	"***************       *11111*                                  \n"
.ascii	"      ---              *1111**                                 \n"
.ascii	"    / o o \             *1111****   *****                      \n"
.ascii	"    \  >  /              **111111***111*                       \n"
.asciz	"     -----                 ***********    dce.hust.edu.vn      \n"
image_end:
command:
.asciz	"1: Print the image\n2: Print the origina image without colour number\n3: Swap order into ECD\n4: Change colour number\n5: Exit\nEnter command: " 
next_command:
.asciz	"Enter next command: "
input_handling:
.asciz	"Unvalid command. Please enter again!\nEnter next command: "
change_colour_D:
.asciz	"Enter new number colour for letter D: "
change_colour_C:
.asciz	"Enter new number colour for letter C: "
change_colour_E:
.asciz	"Enter new number colour for letter E: "
.text
	#load image to register s0
	la	s0, image
	#load command to register
	li 	t1, 1
	li	t2, 2
	li	t3, 3
	li	t4, 4
	li	t5, 5
	#input commnand prompt
	la	a0, command
	li	a7, 4
	ecall
#while loop for input commnand
while:
	#input command (integer from 1 to 5)
	li	a7, 5
	ecall
	#switch case
	beq	a0, t1, case_1
	beq	a0, t2, case_2
	beq	a0, t3, case_3
	beq	a0, t4, case_4
	beq	a0, t5, case_5
	#input handling
	la	a0, input_handling
	li	a7, 4
	ecall
	j 	while
#Case 1: print the original image
case_1:	
	jal	Function_1
	j	continue
case_2:
	jal	Function_2
	j	continue
case_3:
	jal	Function_3
	j	continue
case_4:
	jal	Function_4
	j	continue
case_5:
	j	end_while
continue:
	#prompt next command
	li	a7, 4
	la	a0, next_command
	ecall
	j	while
end_while:
	#terminate
	li	s7, 10
	ecall

#------------------------Functions----------------------------

#Function 1: Print the original image
Function_1:
	li	a7, 4
	la	a0, image
	ecall 
	jr 	ra
	
#Function 2: Print original image without colour number
Function_2:
	#store the content of t1 and t2 in stack
	addi	sp, sp, -8
	sw	t1, 4(sp)
	sw	t2, 0(sp)
	la	s0, image	#store the image to s0
	li	t1, '0'
	li	t2, '9'
Funct2_loop:
	#store the character of s0 to t0
	lb	t0, 0(s0)
	#check loop condition
	beq	t0, zero, Funct2_loop_end
	blt	t0, t1, print_non_numeric
	bgt	t0, t2, print_non_numeric
	#if t0 is a number, print a space instead
	li	a7, 11
	li	a0, 32
	ecall
	j	Funct2_continue
print_non_numeric:
	li	a7, 11
	mv	a0, t0
	ecall
Funct2_continue:
	#continue to the next character
	addi	s0, s0, 1
	j	Funct2_loop
Funct2_loop_end:
	#recover the content of t1 and t2
	lw	t1, 4(sp)
	lw	t2, 0(sp)
	addi	sp, sp, 8
	jr	ra

#Function 3: print ECD
Function_3:
	
#Function 4: Enter new colour for each letter and print
Function_4:
	#use t1, t2, t3 to store the new colour number
	#store the contents of t1, t2, t3 in stack
	addi	sp, sp, -12
	sw	t1, 0(sp)
	sw	t2, 4(sp)
	sw	t3, 8(sp)
	
	#prompt new colour number for letter D
	li	a7, 4
	la	a0, change_colour_D
	ecall
	li	a7, 5
	ecall
	#the new colour for D is store in a0 -> store it in t1
	add	t1, a0, zero
	
	#prompt new colour number for letter C
	li	a7, 4
	la	a0, change_colour_C
	ecall
	li	a7, 5
	ecall
	#the new colour for C is store in a0 -> store it in t2
	add	t2, a0, zero
	
	#prompt new colour number for letter E
	li	a7, 4
	la	a0, change_colour_E
	ecall
	li	a7, 5
	ecall
	#the new colour for E is store in a0 -> store it in t3
	add	t3, a0, zero
	
Funct_4_end:
	jr	ra
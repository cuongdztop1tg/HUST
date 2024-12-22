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
	j	continue
case_3:
	j	continue
case_4:
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
	la	s0, image
	la	s1, image_end
funct1_print_loop:
	beq	s0, s1, funct1_print_loop_end
	#print the line
	li	a7, 4
	mv	a0, s0
	ecall
	#next line
	addi	s0, s0, 64
funct1_print_loop_end:
	jr 	ra
	

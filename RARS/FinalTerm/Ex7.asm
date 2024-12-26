.data
image:
# Barrier position: 23, 42
# Length of each line: 58 characters
# Total: 928 characters
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
.asciz	"     -----           \0     ***********   \0dce.hust.edu.vn\n"
image_end:
command:
.ascii	"1: Print the image\n"
.ascii	"2: Print the original image without colour number\n"
.ascii	"3: Swap order into ECD\n"
.ascii	"4: Change colour number\n"
.ascii	"5: Exit\n"
.asciz	"Enter command: " 
next_command:
.asciz	"Enter next command: "
command_input_handling:
.asciz	"Unvalid command. Please enter again!\nEnter next command: "
change_colour_D:
.asciz	"Enter new number colour for letter D: "
change_colour_C:
.asciz	"Enter new number colour for letter C: "
change_colour_E:
.asciz	"Enter new number colour for letter E: "
new_colour_input_handling:
.asciz	"The colour must be a NUMBER from 0-9. Please enter again!"

.text
#-------------------WORKFLOW-------------------
# The main function is a while loop, allowing the user to enter command (interger from 1 to 4) multiple times
# Each command will be correspond to a Function:
# - Function 1: Print the original image
# - Function 2: Print the original image withour the colour number
# - Function 3: Print ECD instead of DCE
# - Function 4: Enter new color number for each letter and print the new image
# The command 5 will terminate the program
_main_:
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
	la	a0, command_input_handling
	li	a7, 4
	ecall
	j 	while
#Case 1: Print the original image
case_1:	
	jal	Function_1
	j	continue
#Case 2: Print the original image without colour number
case_2:
	jal	Function_2
	j	continue
#Case 3: ECD
case_3:
	jal	Function_3
	j	continue
#Case 4: Change number colour and print
case_4:
	jal	Function_4
	j	continue
#Case 5: Exit
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
_end_main_:

#------------------------Functions----------------------------

#-------------------Function 1: Print the original image-------------------
# Iterate through each character of the image and print it
# If the character is a NULL terminator, print a space instead
Function_1:
	la 	s0, image          # Load address of the image
    	la 	s1, image_end      # Load end of the image
Funct1_print_segment:
    	lb 	t0, 0(s0)          # Load the current character
    	beq 	t0, zero, Funct1_next_segment # If NULL terminator (\0), move to the next segment
	
    	# Print the current character
    	li 	a7, 11             # Syscall for print character
    	mv 	a0, t0             # Load character into a0
    	ecall

    	# Move to the next character
    	addi 	s0, s0, 1
    	j 	Funct1_print_segment      # Continue printing the segment

Funct1_next_segment:
    	# Check if we've reached the end of the image
    	addi 	s0, s0, 1          # Move to the next character after \0
    	bge 	s0, s1, Funct1_end_print  # If at or beyond the end, exit
	
    	# Print a space to separate segments
    	li 	a7, 11             # Syscall for print character
	li 	a0, 32             # ASCII for space
    	ecall

    	# Continue with the next segment
    	j 	Funct1_print_segment

Funct1_end_print:
Function_1_end: 
	jr 	ra
	
#-------------------Function 2: Print original image without colour number-------------------
# Iterate throught each chracter of the image
# If the chracter is not a number, print it
# Else, print a space instead
Function_2:
	#store the content of t1 and t2 in stack
	addi	sp, sp, -8
	sw	t1, 4(sp)
	sw	t2, 0(sp)
	li 	t1, '0'
	li 	t2, '9'
	
	la 	s0, image          # Load address of the image
    	la 	s1, image_end      # Load end of the image
Funct2_print_segment:
    	lb 	t0, 0(s0)          # Load the current character
    	beq 	t0, zero, Funct2_next_segment # If NULL terminator (\0), move to the next segment

	#if t0 is not a number -> print
	blt	t0, t1, Funct2_print_non_numeric
	bgt	t0, t2, Funct2_print_non_numeric
	#if t0 is a number, print a space instead
	li	a7, 11
	li	a0, 32
	ecall
	# Move to the next character
	addi	s0, s0, 1
	j 	Funct2_print_segment
Funct2_print_non_numeric:
    	# Print the current character
    	li 	a7, 11             # Syscall for print character
    	mv 	a0, t0             # Load character into a0
    	ecall

    	# Move to the next character
    	addi 	s0, s0, 1
    	j 	Funct2_print_segment	  # Continue printing the segment

Funct2_next_segment:
    	# Check if we've reached the end of the image
    	addi 	s0, s0, 1          # Move to the next character after \0
    	bge 	s0, s1, Funct2_end_print  # If at or beyond the end, exit
	
    	# Print a space to separate segments
    	li 	a7, 11             # Syscall for print character
	li 	a0, 32             # ASCII for space
    	ecall

    	# Continue with the next segment
    	j 	Funct2_print_segment

Funct2_end_print:
Function_2_end:
	# Recover the content of t1 and t2
	lw	t1, 4(sp)
	lw	t2, 0(sp)
	addi	sp, sp, 8
	jr	ra

#-------------------Function 3: Print ECD-------------------
# Iterate through each line
# Start printing from the E section, then C and finally D
# We will switch to another section if we meet '\n' or '\0'
Function_3:
	la      s0, image        # Load address of the image start into s0
    	addi    s1, s0, 928    	 # s1 is the boundary for s0
    	# Store the contents of t1 and t2 in stack
    	addi	sp, sp, -8
    	sw	t1, 0(sp)
    	sw	t2, 4(sp)
    	li      t1, 0            # Initialize t1 to 0 (loop counter)
    	li      t2, '\n'         

Funct3_print_line:
    	beq     s0, s1, Funct3_end_print      # If s0 > s1, we are past the end of the image, so exit
    	addi    t1, s0, 42       # Set t1 to the address of the start of 'E' (image + 42 bytes)

Funct3_print_E:
    	lb      t0, 0(t1)        # Load byte from address in t1 into t0
    	beq     t0, t2, Funct3_print_C  # If t0 is a newline, jump to print_C
    	# Print the character
    	li      a7, 11           
    	mv      a0, t0           
    	ecall                    
    	addi    t1, t1, 1        # Increment t1 to point to the next byte in the string
    	j       Funct3_print_E          

Funct3_print_C:
	# Space
    	li      a7, 11           
    	li      a0, 32           
    	ecall                    
    	addi    t1, s0, 23       # Set t1 to the start of 'C' (image + 23 bytes)

Funct3_print_C_loop:
    	lb      t0, 0(t1)        # Load byte from address in t1 into t0
    	beqz    t0, Funct3_print_D      # If t0 is zero (null terminator), jump to print_D
    	li      a7, 11           
    	mv      a0, t0          
    	ecall                    
    	addi    t1, t1, 1        # Increment t1 to point to the next byte in the string
    	j       Funct3_print_C_loop     

Funct3_print_D:
	# Space
    	li      a7, 11          
    	li      a0, 32           
    	ecall                    
    	mv      t1, s0           # Set t1 to point back to the start of the image (s0)

Funct3_print_D_loop:
    	lb      t0, 0(t1)        # Load byte from address in t1 to t0
	beqz    t0, Funct3_new_line     # If t0 is zero (null terminator), jump to new_line
    	li      a7, 11           
    	mv      a0, t0           
    	ecall                    
    	addi    t1, t1, 1        # Increment t1 to point to the next byte in the string
    	j       Funct3_print_D_loop     

Funct3_new_line:
    	li      a7, 11           
    	li      a0, 10           
    	ecall                    
    	addi    s0, s0, 58       # Move s0 to the next line (increment address by 58)
    	j       Funct3_print_line       

Funct3_end_print:
Function_3_end:
	# Recover the contents of t1 and t2
    	lw	t1, 0(sp)
    	lw	t2, 4(sp)
    	addi	sp, sp, 8
	jr	ra
	
#-------------------Function 4: Enter new colour for each letter and print-------------------
# Allow the user to enter new colour number for each letter and store it in t1, t2 and t2 register
# Iterdate through each character of the image
# If the character is not a number, print it
# Else, print the new colour number corresponding to the letter 
Function_4:
	# Use t1, t2, t3 to store the new colour number
	# Store the contents of t1, t2, t3, t4, t5 in stack
	addi	sp, sp, -20
	sw	t1, 0(sp)
	sw	t2, 4(sp)
	sw	t3, 8(sp)
	sw	t4, 12(sp)
	sw	t5, 16(sp)
	li 	t4, '0'
	li 	t5, '9'
	
	la 	s0, image          # Load address of the image
    	la 	s1, image_end      # Load end of the image
	
	# Store the old colour of D, C and E in a1, a2, a3 respectively
	li	a1, '2'
	li	a2, '1'
	li	a3, '3'
Funct4_input:
	# Prompt new colour number for letter D
	li	a7, 4
	la	a0, change_colour_D
	ecall
	# Input new colour for D
	li	a7, 12
	ecall
	# If the new colour is not a number 
	blt	a0, t4, Funct4_input_handling
	bgt	a0, t5, Funct4_input_handling
	# The new colour for D is store in a0 -> store it in t1
	add	t1, a0, zero
	# New line
	li	a7, 11
	li	a0, 10
	ecall
	
	# Prompt new colour number for letter C
	li	a7, 4
	la	a0, change_colour_C
	ecall
	# Input new colour for C
	li	a7, 12
	ecall
	# If the new colour is not a number 
	blt	a0, t4, Funct4_input_handling
	bgt	a0, t5, Funct4_input_handling
	# The new colour for C is store in a0 -> store it in t2
	add	t2, a0, zero
	# New line
	li	a7, 11
	li	a0, 10
	ecall
	
	# Prompt new colour number for letter E
	li	a7, 4
	la	a0, change_colour_E
	ecall
	# Input new colour for E
	li	a7, 12
	ecall
	# If the new colour is not a number 
	blt	a0, t4, Funct4_input_handling
	bgt	a0, t5, Funct4_input_handling
	# The new colour for E is store in a0 -> store it in t3
	add	t3, a0, zero
	# New line
	li	a7, 11
	li	a0, 10
	ecall
	
	# If the input valid, continue the function
	j	Funct4_print_segment
	
Funct4_input_handling:
	li	a7, 11
	li	a0, 10	# ASCII for newline
	ecall
	# Promp input handling
	li	a7, 4
	la	a0, new_colour_input_handling
	ecall
	
	li	a7, 11
	li	a0, 10	# ASCII for newline
	ecall
	
	j	Funct4_input

#Start printing
Funct4_print_segment:
    	lb 	t0, 0(s0)          # Load the current character
    	beq 	t0, zero, Funct4_next_segment # If NULL terminator (\0), move to the next segment

	#if t0 is the colour of D -> print the new colour in t1
	beq	t0, a1, Funct4_print_new_colour_D
	#if t0 is the colour of C -> print the new colour in t2
	beq	t0, a2, Funct4_print_new_colour_C
	#if t0 is the colour of E -> print the new colour in t3
	beq	t0, a3, Funct4_print_new_colour_E

	j	Funct4_print_non_numeric
Funct4_print_new_colour_D:
	li	a7, 11
	add	a0, t1, zero
	ecall
	j	Funct4_continue
Funct4_print_new_colour_C:
	li	a7, 11
	add	a0, t2, zero
	ecall
	j	Funct4_continue
Funct4_print_new_colour_E:
	li	a7, 11
	add	a0, t3, zero
	ecall
Funct4_continue:
	addi	s0, s0, 1
	j 	Funct4_print_segment

Funct4_print_non_numeric:
    	# Print the current character
    	li 	a7, 11             # Syscall for print character
    	mv 	a0, t0             # Load character into a0
    	ecall

    	# Move to the next character
    	addi 	s0, s0, 1
    	j 	Funct4_print_segment		# Continue printing the segment

Funct4_next_segment:
    	# Check if we've reached the end of the image
    	addi 	s0, s0, 1         # Move to the next character after \0
    	bge 	s0, s1, Funct4_end_print  # If at or beyond the end, exit
	
    	# Print a space to separate segments
    	li 	a7, 11             # Syscall for print character
	li 	a0, 32             # ASCII for space
    	ecall

    	# Continue with the next segment
    	j 	Funct4_print_segment

Funct4_end_print:
Function_4_end:
	# Recover the contents of t1, t2 and t3
	lw	t1, 0(sp)
	lw	t2, 4(sp)
	lw	t3, 8(sp)
	lw	t4, 12(sp)
	lw	t5, 16(sp)
	addi	sp, sp, 20
	jr	ra

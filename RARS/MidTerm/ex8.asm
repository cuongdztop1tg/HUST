.data
	names:	.space 3200	# array to store students' names
	marks:	.space 400	# array to store students' marks

	message1:	.asciz "Enter number of students: "
	error_msg:	.asciz "Size should be a positive integer, please input again!\n"
	message2:	.asciz "Enter list of students: "
	message3:	.asciz "Students list: "
.text

# Input: Enter the number of students and read each student's name and mark
input:
#input the size of both array, if the input is not correct, tell the user to input again
input_size:
	# Display prompt: "Enter number of students"
	li	a7, 4
	la	a0, message1
	ecall

	# Read the number of students and store in s0
	li	a7, 5
	ecall
	add	s0, a0, zero		# s0 = number of students
	bge 	s0, zero, valid_input    # If s0 >= 0, jump to valid_input
    	j invalid_input            # If s0 < 0, go to invalid_input

invalid_input:
        # Print "Invalid input" error message
        li a7, 4                   # Syscall for printing a string
        la a0, error_msg           # Load address of error message
        ecall                      # Print the error message
        j input_size               # Go back to input prompt
valid_input:
	# Display prompt: "Enter list of students"
	li	a7, 4
	la	a0, message2
	ecall
	
	# New line
	li	a7, 11
	li	a0, 10
	ecall

	# Initialize array pointers and index
	li	t0, 0			# index i = 0
	la	s1, names		# pointer to names array
	la	s2, marks		# pointer to marks array

input_loop:
	slt	t2, t0, s0		# check if i < number of students
	beq	t2, zero, end_input_loop	# exit loop if i >= number of students

	# Read name and store in names array
	li	a7, 8			# syscall for reading a string
	add	a0, s1, zero		# set a0 to current name position
	li	a1, 32			# max length of name
	ecall
	addi	s1, s1, 32		# move to next name slot

	# Read mark and store in marks array (as integer)
	li	a7, 6			# syscall for reading an integer
	ecall
	fsw	fa0, 0(s2)		# store mark in marks array
	addi	s2, s2, 4		# move to next mark slot

	addi	t0, t0, 1		# increment index i
	j	input_loop
end_input_loop:

# Sorting: Sort students based on their marks in descending order using Bubble Sort
sort:
	li	t0, 0			# outer loop index i = 0
	addi	s4, s0, -1		# upper bound for outer loop (size - 1)

outer_loop:
	slt	t2, t0, s4		# check if i < size - 1
	beq	t2, zero, end_outer_loop	# end loop if i >= size - 1

	li	s3, 0			# set swapped flag to 0 (false)

	# Inner loop for each pass of Bubble Sort
	li	t1, 0			# inner loop index j = 0
	la	s1, names		# reset pointer to names array
	la	s2, marks		# reset pointer to marks array
	sub	s5, s4, t0		# upper bound for inner loop (size - i - 1)

inner_loop:
	slt	t2, t1, s5		# check if j < size - i - 1
	beq	t2, zero, end_inner_loop	# end loop if j >= size - i - 1

	# Compare marks[j] with marks[j+1]
	lw	s8, 0(s2)		# s8 = marks[j]
	lw	s9, 4(s2)		# s9 = marks[j+1]

	# Swap if marks[j] < marks[j+1] (for descending order)
	slt	t2, s8, s9
	beq	t2, zero, no_swap	# skip swap if marks[j] >= marks[j+1]

	# Swap marks[j] and marks[j+1]
	sw	s8, 4(s2)
	sw	s9, 0(s2)

	# Swap names[j] and names[j+1] by swapping each byte
	add	t4, s1, zero		# t4 = address of names[j]
	addi	t5, s1, 32		# t5 = address of names[j+1]
	li	t3, 0			# temporary index for name swap
swap_name_loop:
	lb	s10, 0(t4)		# load byte from names[j]
	lb	s11, 0(t5)		# load byte from names[j+1]
	sb	s10, 0(t5)		# store names[j] byte to names[j+1]
	sb	s11, 0(t4)		# store names[j+1] byte to names[j]
	addi	t4, t4, 1		# move to next byte in names[j]
	addi	t5, t5, 1		# move to next byte in names[j+1]
	addi	t3, t3, 1
	li	s11, 32
	bne	t3, s11, swap_name_loop

	# Set swapped flag to true
	li	s3, 1

no_swap:
	addi	t1, t1, 1		# j++
	addi	s2, s2, 4		# move to next mark
	addi	s1, s1, 32		# move to next name
	j	inner_loop

end_inner_loop:
	beq	s3, zero, end_outer_loop	# if no swaps, sorting is complete

	addi	t0, t0, 1		# i++
	j	outer_loop

end_outer_loop:

# Print: Print list of students after sorting
print:
	li	t0, 0			# index i = 0
	la	s1, names		# pointer to names array
	la	s2, marks		# pointer to marks array
	
	# Display prompt: "Student list: "
	li	a7, 4
	la	a0, message3
	ecall
	
	# New line
	li	a7, 11
	li	a0, 10
	ecall

print_loop:
	slt	t2, t0, s0		# check if i < number of students
	beq	t2, zero, end_print_loop	# end loop if i >= number of students

	# Print name
	li	a7, 4			# syscall for printing string
	add	a0, s1, zero		# set a0 to current name position
	ecall
	addi	s1, s1, 32		# move to next name slot

	# Print mark
	li	a7, 2			# syscall for printing integer
	flw	fa0, 0(s2)		# load mark
	ecall
	addi	s2, s2, 4		# move to next mark slot

	# New line
	li	a7, 11
	li	a0, 10
	ecall

	addi	t0, t0, 1		# i++
	j	print_loop

end_print_loop:

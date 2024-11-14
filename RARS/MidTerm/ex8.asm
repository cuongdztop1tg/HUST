.data
	names:	.space 3200	#array to store students' names
				#max name length = 32
	marks:	.space 400	#array to store students' marks

	message1:	.asciz "Enter number of students: "
	message2:	.asciz "Enter list of students: "
.text
#Workflow
#-------------------------------------------------------------
# Step 1: Input the size of 2 arrays and element of each array
# Step 2: Sort students base on their marks
#-------------------------------------------------------------

#Input function: Enter the number of students and read the name
#and mark of each students
input:
	#Enter number of students
	li	a7, 4
	la	a0, message1
	ecall
	#Read number of students 
	li	a7, 5
	ecall
	
	add	s0, a0, zero	#store the number of students in s0
	#Enter list of students
	li	a7, 4
	la	a0, message2
	ecall
	
	li	t0, 0		#index of 2 arrays, i = 0
	la	s1, names	#ste address of names to s1
	la	s2, marks	#set address of marks to s2
input_loop:
	slt	t2, t0, s0	#check loop condition i < size
	beq	t2, zero, end_input_loop	#end loop if i >= size
	
	#read name and store in s1
	li	a7, 8
	add	a0, s1, zero
	li	a1, 32
	ecall
	addi	s1, s1, 32	#move to next element
	
	#read mark and store in s2
	li	a7, 6
	ecall
	fsw	fa0, 0(s2)	#store input mark in s2
	addi	s2, s2, 4	#move to next element
	
	addi	t0, t0, 1	#i = i + 1
	j	input_loop
end_input_loop:		
end_input:

#Sort students base on their marks



#print list of students
print:
	li	t0, 0
	la	s1, names
	la	s2, marks
print_loop:
	slt	t2, t0, s0	#check loop condition i < size
	beq	t2, zero, end_print_loop	#end loop if i >= size
	
	#print name
	li	a7, 4
	add	a0, s1, zero
	ecall
	addi	s1, s1, 32	#move to next element

	#print mark
	li	a7, 2
	flw	fa0, 0(s2)
	ecall
	addi	s2, s2, 4	#move to next element
	
	#new line
	li	a7, 11
	li	a0, 10
	ecall
		
	addi	t0, t0, 1
	j	print_loop
end_print_loop:









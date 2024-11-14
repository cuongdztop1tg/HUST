.data 
	X:	.space 4000	#array to store the elements
	message1:	.asciz "Enter array size: "
	message2:	.asciz "Enter array: "
	message3:	.asciz "Max element of the array: "
	message4:	.asciz "Enter m: "
	message5:	.asciz "Enter M: "
	message6:	.asciz "Number of elements in range (m, M): "
.text
#Workflow
#--------------------------------------------------------------
# Step 1: Input the size of array and the elements of the array
# Step 2: Find the max element of the array
# Step 3: Find the elements in the range (m, M)
#--------------------------------------------------------------

#Input the size of array and the elements of the array
input:
	#Enter array size
	li	a7, 4
	la	a0, message1
	ecall
	#read array size
	li	a7, 5
	ecall
	
	add	s0, a0, zero
	#print message2
	li	a7, 4
	la	a0, message2
	ecall
	#Initialize array pointer and index
	li	t0, 0			#t0 is the index i of the array X, t0 = i = 0
	la	s1, X			#set address of X to s1

	#loop to input the array
input_loop:
	slt	t2, t0, s0		#check loop condition i < size
	beq	t2, zero, end_input_loop	#end loop if i >= size
	li	a7, 5			#input element and store in a0
	ecall
	sw	a0, 0(s1)		#X[i] = a0
	addi	s1, s1, 4		#move to next element
	addi	t0, t0, 1		#i++
	j	input_loop
end_input_loop:
end_input:

#Find max function: find the maximum element of X
#---------------------------------------------------
# Set the value of max to be X[0]
# Iterate through the array
# if X[i] > max, set max = X[i]
# print max
#---------------------------------------------------
find_max:
	la	s1, X			#set s1 to be the base address of X
	lw	s2, 0(s1)		#s2 store the max element of X
					#set s2 = X[0]
	li	t0, 1			#i = 1
find_max_loop:
	slt	t2, t0, s0		#check loop condition i < size
	beq	t2, zero, end_find_max_loop	#end loop if i >= size
	
	addi	s1, s1, 4		#move to next element
	lw	t3, 0(s1)		#t4 = X[i]
	ble	t3, s2, continue	#if t3 <= max, continue
	add	s2, t3, zero		#else, update max = t3
continue:
	addi	t0, t0, 1		#i++
	j	find_max_loop
end_find_max_loop:
	#print the result
	li 	a7, 56
	la	a0, message3
	add	a1, s2, zero
	ecall
end_find_max:

#Find the number of element in range (m, M)
#---------------------------------------------------
# Read input m, M
# initialize count = 0
# Iterate through the array
# If X[i] in the range (m, M), count++
#---------------------------------------------------
num_elements_in_range:
	#Enter m
	li	a7, 4
	la	a0, message4
	ecall
	#read m
	li	a7, 5
	ecall
	add	a4, a0, zero		#store m to a4
	
	#Enter M
	li	a7, 4
	la	a0, message5
	ecall
	#read M
	li	a7, 5
	ecall
	add	a5, a0, zero		#store M to a5
	
	la	s1, X			#s1: pointer to array X
	li	t0, 0			#i = 0
	li	t5, 0			#count = 0
num_elements_in_range_loop:
	slt	t2, t0, s0		#check loop condition i < size
	beq	t2, zero, end_num_elements_in_range_loop	#end loop if i >= size
	
	lw	t3, 0(s1)
	blt	t3, a5, check_larger_than_m	#if X[i] < M, then
	j	cont
check_larger_than_m:
	ble	t3, a4, cont		#if X[i] <= m => skip
	addi	t5, t5, 1		#else, count += 1
cont:
	addi	s1, s1, 4		#move to next element
	addi	t0, t0, 1		#i = i + 1
	j	num_elements_in_range_loop
end_num_elements_in_range_loop:
	#print the result
	li 	a7, 56
	la	a0, message6
	add	a1, t5, zero
	ecall
end_num_elements_in_range:
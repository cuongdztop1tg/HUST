.eqv MONITOR_SCREEN 0x10010000 # Start address of the bitmap display
.eqv RED 0x00FF0000 # Common color values
.eqv GREEN 0x0000FF00
.eqv BLUE 0x000000FF
.eqv WHITE 0x00FFFFFF
.eqv YELLOW 0x00FFFF00
.eqv GREY 0xA9A9A9A9
.text
	li 	a0, MONITOR_SCREEN # Load address of the display
#draw chess board
	li	s0, 8	#num of rows && row size
	li	s1, 2	#check condition
	li	t4, 0 	#row
loop:
	li	t1, 0	#row index
	rem	t3, t4, s1	#check if row is even or odd
	beq	t3, zero, even_loop
#odd row loop
odd_loop:
	rem	t3, t1, s1
	bne	t3, zero, draw_odd_white
	j	continue_odd
draw_odd_white:
	li 	t0, WHITE
	sw	t0, 0(a0)
continue_odd:
	addi	t1, t1, 1
	addi	a0, a0, 4
	beq	t1, s0, end_even_loop
	j 	odd_loop
end_odd_loop:
	j	next_row
	
#even row loop
even_loop:
	rem	t3, t1, s1
	beq	t3, zero, draw_even_white
	j	continue_even
draw_even_white:
	li 	t0, WHITE
	sw	t0, 0(a0)
continue_even:
	addi	t1, t1, 1
	addi	a0, a0, 4
	beq	t1, s0, end_even_loop
	j 	even_loop
end_even_loop:
#move to next row
next_row:
	addi	t4, t4, 1
	beq	t4, s0, end_loop
	j	loop
end_loop:
	
	

# ------------------------------------------------------
# 	    col 0x1 	0x2	0x4 	0x8 
# row 0x1 	 0 	 1 	 2 	 3 
# 		0x11	0x21 	0x41	0x81 
# row 0x2 	 4	 5	 6	 7
# 		0x12 	0x22 	0x42 	0x82
# row 0x4 	 8	 9	 a	 b 
# 		0x14 	0x24 	0x44 	0x84
# row 0x8 	 c	 d	 e	 f
# 		0x18 	0x28 	0x48 	0x88
# ------------------------------------------------------
# Command row number of hexadecimal keyboard (bit 0 to 3)
# Eg. assign 0x1, to get key button 0,1,2,3
# assign 0x2, to get key button 4,5,6,7
# NOTE must reassign value for this address before reading,
# eventhough you only want to scan 1 row
.eqv IN_ADDRESS_HEXA_KEYBOARD 0xFFFF0012
# Receive row and column of the key pressed, 0 if not key pressed 
# Eg. equal 0x11, means that key button 0 pressed.
# Eg. equal 0x28, means that key button D pressed.
.eqv OUT_ADDRESS_HEXA_KEYBOARD 0xFFFF0014
.text
main:
	li t1, IN_ADDRESS_HEXA_KEYBOARD
	li t2, OUT_ADDRESS_HEXA_KEYBOARD
	li t3, 0x01 # check row 4 with key C, D, E, F 
	li t4, 0x02
	li t5, 0x04
	li t5, 0x08
polling:
#first row
	sb t3, 0(t1) # must reassign expected row
	lb a0, 0(t2) # read scan code of key button
print1:
	li a7, 34 # print integer (hexa)
	ecall
sleep1:
	li a0, 1000 # sleep 100ms
	li a7, 32
	ecall
#second row
	sb t4, 0(t1) # must reassign expected row
	lb a0, 0(t2) # read scan code of key button
print2:
	li a7, 34 # print integer (hexa)
	ecall
sleep2:
	li a0, 1000 # sleep 100ms
	li a7, 32
	ecall
#third row
	sb t5, 0(t1) # must reassign expected row
	lb a0, 0(t2) # read scan code of key button
print3:
	li a7, 34 # print integer (hexa)
	ecall
sleep3:
	li a0, 1000 # sleep 100ms
	li a7, 32
	ecall
#fourth row
	sb t6, 0(t1) # must reassign expected row
	lb a0, 0(t2) # read scan code of key button
print4:
	li a7, 34 # print integer (hexa)
	ecall
sleep4:
	li a0, 1000 # sleep 100ms
	li a7, 32
	ecall
back_to_polling:
	j polling # continue polling

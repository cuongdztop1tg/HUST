# ------------------------------------------------------
# col 0x1 col 0x2 col 0x4 col 0x8
# row 0x1 0 1 2 3
# 0x11 0x21 0x41 0x81
# row 0x2 4 5 6 7
# 0x12 0x22 0x42 0x82
# row 0x4 8 9 a b
# 0x14 0x24 0x44 0x84
# row 0x8 c d e f
# 0x18 0x28 0x48 0x88
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
	li t3, 0x01 # check row (start from row 1)
polling:
	sb t3, 0(t1) # reassign expected row -> sb t to tell the program which row to check
	lb a0, 0(t2) # read scan code of key button on the current row
	beqz a0, next_row #if not the row (a0 = 0) next_row
print:
	li a7, 34 # print integer (hexa)
	ecall
sleep:
	li a0, 100 # sleep 100ms
	li a7, 32
	ecall
back:
	li t3, 0x01 #scan again from row 1
	j polling
next_row:
	slli t3, t3, 1 #t3 * 2 to increase to the next row
	li t6, 0x8
	ble t3, t6, polling #if t3 <= row 4 -> keep scanning
	j back #else back from row 1 and so on

csrrsi 

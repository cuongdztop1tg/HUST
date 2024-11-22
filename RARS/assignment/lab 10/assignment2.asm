.data
SEGMENT_MAP: .word 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F
.eqv SEVENSEG_LEFT 0xFFFF0011 # Address of the LED on the left
# Bit 0 = segment a
# Bit 1 = segment b
# ...
# Bit 7 = dot sign
.eqv SEVENSEG_RIGHT 0xFFFF0010 # Address of the LED on the right
.text
main:
la s3, SEGMENT_MAP #s3 is an array
li a1,10
li a7,12
ecall
add s1,a0,zero
remu a2,s1,a1
sub s1,s1,a2
div s1,s1,a1

add s1,s1,s1
add s1,s1,s1
add s6,s3,s1
lw a0, 0(s6) # Set value for 7 segments
jal SHOW_7SEG_LEFT # Show the result
add a2,a2,a2
add a2,a2,a2
add s6,s3,a2
lw a0,0(s6) # Set value for 7 segments
jal SHOW_7SEG_RIGHT # Show the result
exit:
li a7, 10
ecall
end_main:
# ---------------------------------------------------------------
# Function SHOW_7SEG_LEFT : Turn on/off the 7seg
# param[in] a0 value to shown
# remark t0 changed
# ---------------------------------------------------------------
SHOW_7SEG_LEFT:
li t0, SEVENSEG_LEFT # Assign port's address
sb a0, 0(t0) # Assign new value
jr ra
# ---------------------------------------------------------------
# Function SHOW_7SEG_RIGHT : Turn on/off the 7seg
# param[in] a0 value to shown
# remark t0 changed
# ---------------------------------------------------------------
SHOW_7SEG_RIGHT:
li t0, SEVENSEG_RIGHT # Assign port's address
sb a0, 0(t0) # Assign new value
jr ra
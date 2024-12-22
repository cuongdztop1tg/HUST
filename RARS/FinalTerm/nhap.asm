.data
###############################################################################
# SEGMENT_MAP: Patterns for 0..9 on a 7-segment display (each .word = 4 bytes).
# (Used to look up the LED pattern based on digit index.)
###############################################################################
SEGMENT_MAP: 
    .word 0x3F, 0x06, 0x5B, 0x4F, 0x66, 
           0x6D, 0x7D, 0x07, 0x7F, 0x6F

###############################################################################
# Memory-mapped 7-segment LED addresses
###############################################################################
.eqv SEVENSEG_RIGHT 0xFFFF0010
.eqv SEVENSEG_LEFT  0xFFFF0011

.text

###############################################################################
# Set up pointers & registers for the calculator
#   - la s10, SEGMENT_MAP: Loads the base address for accessing SEGMENT_MAP
#   - li s2, 0          : Initialize total sum (s2) to 0
#   - li s3, 0          : Initialize current operation code (s3) to 0
###############################################################################
la s10, SEGMENT_MAP    
li s2, 0               
li s3, 0               

###############################################################################
# main: 
#   1) Initialize temp registers (t0) and ASCII thresholds (t1, t2).
#   2) Jump to inputnum to start reading characters.
###############################################################################
main :
    li t0, 0       # the temporary sum
    li t1, 58      # ASCII ':' boundary
    li t2, 48      # ASCII '0' boundary
    li s0, 10      # decimal base (10)
    j  inputnum

###############################################################################
# inputnum:
#   1) Reads a character from the user (via ecall).
#   2) Checks if it's a digit; if yes, convert & accumulate in t0.
#   3) Updates the 7-segment display with partial number.
#   4) If not a digit, jump to calculate1 to handle operator or else.
###############################################################################
inputnum:
    li   a7, 12       # syscall: read character
    ecall
    bgeu a0, t1, calculate1      # if >= ':' => not digit => handle operator
    blt  a0, t2, handling_input  # if < '0' => invalid => handle error
    sub  a0, a0, t2              # convert ASCII to integer
    mul  t0, t0, s0              # shift old t0 in decimal
    add  t0, t0, a0              # accumulate new digit
    jal  SHOW_7SEG               # display partial number
    j    inputnum

###############################################################################
# calculate1:
#   - If s2 == 0, it means no total sum yet, so initialize s2 with t0.
#   - Otherwise, go to output to see which operation to perform.
###############################################################################
calculate1:
    beq s2, zero, init
    j   output  # finish current operation & get next

init :
    add s2, s2, t0  
    j   output

###############################################################################
# calculate2:
#   - After an operation is performed, we read the next character (operator/digit).
#   - If it's '=' (ASCII 102), we go to printandreset.
#   - Otherwise, see if it's one of +, -, *, /, %; if yes, set operation & go main.
#   - If not, might be another digit or invalid (call handling_input).
###############################################################################
calculate2:
    addi s1,a0,-102
    beq s1, zero, printandreset
    addi s1, a0, -97
    beq s1, zero, sum         # operation is +
    addi s1, a0, -98
    beq s1, zero, minus       # operation is -
    addi s1, a0, -99
    beq s1, zero, multiply    # operation is *
    addi s1, a0, -100
    beq s1, zero, division    # operation is /
    addi s1, a0, -101
    beq s1, zero, remainder   # operation is %

handling_input:
    # This label can handle any unexpected or invalid input
    # (Left blank in your code.)

###############################################################################
# SHOW_7SEG:
#   Displays the number currently in t0 on the 7-segment LEDs:
#     - Computes the units digit for the right LED
#     - Computes the tens digit for the left LED
###############################################################################
SHOW_7SEG:
    li a2, SEVENSEG_LEFT
    li a1, SEVENSEG_RIGHT

    # Right digit (units)
    rem s5, t0, s0
    slli s9, s5, 2
    add s9, s10, s9
    lw s9, 0(s9)
    sb s9, 0(a1)

    # Left digit (tens)
    div s5, t0, s0
    rem s5, s5, s0
    slli s9, s5, 2
    add s9, s10, s9
    lw s9, 0(s9)
    sb s9, 0(a2)

    jr ra

###############################################################################
# output:
#   Checks s3 to figure out which arithmetic operation was selected (1..5).
#   Then branches to the corresponding calsum/calminus/etc.
###############################################################################
output:
    li a2, SEVENSEG_LEFT
    li a1, SEVENSEG_RIGHT
    addi s4,s3,-1
    beq s4, zero, calsum
    addi s4,s3,-2
    beq s4, zero, calminus
    addi s4,s3,-3
    beq s4, zero, calmultiply
    addi s4,s3,-4
    beq s4, zero, caldivision
    addi s4,s3,-5
    beq s4, zero, calremainder
    j   calculate2

###############################################################################
# The next 5 labels (sum, minus, multiply, division, remainder) 
# just set s3 to the corresponding "operation code" and go back to main.
###############################################################################
# sum:    s3=1 -> calsum
# minus:  s3=2 -> calminus
# multiply: s3=3 -> calmultiply
# division: s3=4 -> caldivision
# remainder: s3=5 -> calremainder
###############################################################################
sum:
    addi s3,zero,1
    j main

minus:
    addi s3,zero,2
    j main

multiply:
    addi s3,zero,3
    j main

division:
    addi s3,zero,4
    j main

remainder:
    addi s3,zero,5
    j main

###############################################################################
# calsum, calminus, calmultiply, caldivision, calremainder:
#   - These perform the arithmetic on (s2, t0).
#   - Then call SHOW_7SEG2 to display the new sum in s2.
#   - Finally jump to calculate2 to await the next input.
###############################################################################
calsum:
    add s2,s2,t0
    jal SHOW_7SEG2
    j calculate2

calminus:
    sub s2,s2,t0
    jal SHOW_7SEG2
    j calculate2

calmultiply:
    mul s2,s2,t0
    jal SHOW_7SEG2
    j calculate2

caldivision:
    div s2,s2,t0
    jal SHOW_7SEG2
    j calculate2

calremainder:
    rem s2,s2,t0
    jal SHOW_7SEG2
    j calculate2

###############################################################################
# printandreset:
#   If user typed '=', we reset s2 and s3, then jump back to main to restart.
###############################################################################
printandreset:
    sub s2,s2,s2
    li s3,0
    j main

###############################################################################
# SHOW_7SEG2:
#   Similar to SHOW_7SEG, but displays s2 instead of t0 
#   (i.e. the current total sum).
###############################################################################
SHOW_7SEG2:
    li a2, SEVENSEG_LEFT
    li a1, SEVENSEG_RIGHT
    rem s5, s2, s0
    slli s9,s5,2
    add s9, s10,s9 
    lw s9,0(s9)
    sb s9, 0(a1) 

    div s5,s2,s0
    rem s5,s5,s0
    slli s9,s5,2
    add s9, s10,s9
    lw s9,0(s9)
    sb s9, 0(a2)
    jr ra

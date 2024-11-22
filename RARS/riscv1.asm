li s0, DISPLAY_CODE
li s1, DISPLAY_READY
loop: 
WaitForKey:
lw t1, 0(a1) # t1 = [a1] = KEY_READY
beq t1, zero, WaitForKey # if t1 == 0 then Polling
ReadKey:
lw t0, 0(a0) # t0 = [a0] = KEY_CODE
WaitForDis:
lw t2, 0(s1) # t2 = [s1] = DISPLAY_READY
beq t2, zero, WaitForDis # if t2 == 0 then polling 
Encrypt:
addi t0, t0, 1 # change input key
ShowKey:
sw t0, 0(s0) # show key 
j loop
li t0, BLUE
sw t0, 8(a0)
li t0, WHITE
sw t0, 12(a0)
li t0, YELLOW
sw t0, 32(a0)
li t0, WHITE
lb t0, 42(a0)
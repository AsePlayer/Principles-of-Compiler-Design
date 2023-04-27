.text
main:
# -----------------------
li $t1,0
li $t2,1
beq $zero, $zero, ifTrue_0
li $t1,1
li $t2,1
beq $zero, $zero, ifTrue_1
li $t1,25
li $t2,20
bgt $t1, $t2, ifTrue_2
li $t1,1
li $t2,1
beq $zero, $zero, ifTrue_3
li $t1,5
li $t2,5
beq $t1, $t2, ifTrue_4
li $t1,5
li $t2,6
bne $t1, $t2, ifTrue_5
li $t1,5
li $t2,4
bgt $t1, $t2, ifTrue_6
li $t1,5
li $t2,5
bge $t1, $t2, ifTrue_7
li $t1,5
li $t2,6
blt $t1, $t2, ifTrue_8
li $t1,5
li $t2,5
ble $t1, $t2, ifTrue_9
# -----------------
#  Done, terminate program.

li $a0,0     # flush print value with 0
li $v0,1     # call code for terminate
syscall      # system call (terminate)
li $v0,10    # call code for terminate
syscall      # system call (terminate)
.end main
# -----------------

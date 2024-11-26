.text
main:
# -----------------------
li $t1,66
li $t2,66
beq $t1, $t2, ifTrue_0
li $t1,1
li $t2,1
beq $zero, $zero, ifTrue_1
li $t1,1
li $t2,1
beq $zero, $zero, ifTrue_2
li $t1,1
li $t2,1
beq $zero, $zero, ifTrue_3
li $a0,10
li $v0,11
syscall
li $a0,5
li $v0,1
syscall
jal callThis
# -----------------
#  Done, terminate program.

li $a0,0     # flush print value with 0
li $v0,1     # call code for terminate
syscall      # system call (terminate)
li $v0,10    # call code for terminate
syscall      # system call (terminate)
.end main
# -----------------

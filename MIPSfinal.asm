.data
	ten: .word 10
	five: .word 5
	twenty: .word 20
	eight: .word 8
	result: .word 0
	x: .word 12
	y: .word 7
	statement: .word 0
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
ifTrue_0:
li $a0,10
li $v0,11
syscall
li $a0,1
li $v0,1
syscall
ifTrue_1:
li $a0,10
li $v0,11
syscall
li $a0,2
li $v0,1
syscall
la $a0, result
li $a1, 17
sw $a1, 0($a0)
ifTrue_2:
li $a0,10
li $v0,11
syscall
li $a0,3
li $v0,1
syscall
ifTrue_3:
li $a0,10
li $v0,11
syscall
li $a0,4
li $v0,1
syscall
callThis:
la $a0, statement
li $a1, 6
sw $a1, 0($a0)
li $a0,10
li $v0,11
syscall
li $a0,6
li $v0,1
syscall
jr $ra
jr $ra

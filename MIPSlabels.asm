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

trueFunction:
li $a0,10
li $v0,11
syscall
li $a0,1
li $v0,1
syscall
jr $ra
falseFunction:
li $a0,10
li $v0,11
syscall
li $a0,0
li $v0,1
syscall
jr $ra

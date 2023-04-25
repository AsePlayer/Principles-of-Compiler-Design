.data
	value: .word 1
	tuff: .word 0
	rff: .word 0
.text
main:
# -----------------------
la $a0, tuff
li $a1, 5
sw $a1, 0($a0)
li $t1,1
li $t2,5
ble $t1, $t2, ifTrue
# -----------------
#  Done, terminate program.

li $a0,0     # flush print value with 0
li $v0,1     # call code for terminate
syscall      # system call (terminate)
li $v0,10    # call code for terminate
syscall      # system call (terminate)
.end main
# -----------------
ifTrue:
li $a0,5
li $v0,1
syscall
li $a0,10
li $v0,11
syscall
li $a0,10
li $v0,11
syscall
li $a0,9
li $v0,1
syscall
jr $ra

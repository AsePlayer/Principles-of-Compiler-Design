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

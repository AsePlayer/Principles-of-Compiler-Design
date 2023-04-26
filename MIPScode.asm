.text
main:
# -----------------------
li $a0,10
li $v0,11
syscall
li $a0,30
li $v0,1
syscall
li $a0,10
li $v0,11
syscall
li $a0,3628800
li $v0,1
syscall
li $a0,10
li $v0,11
syscall
li $a0,-94
li $v0,1
syscall
jal trueFunction
jal falseFunction
# -----------------
#  Done, terminate program.

li $a0,0     # flush print value with 0
li $v0,1     # call code for terminate
syscall      # system call (terminate)
li $v0,10    # call code for terminate
syscall      # system call (terminate)
.end main
# -----------------

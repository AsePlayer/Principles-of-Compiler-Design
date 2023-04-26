#include <string.h>
// Set of functions to emit MIPS code
FILE * MIPScode;
FILE * MIPSdata;
FILE * MIPSlabels;
FILE * MIPSfinal;

int ifCounter = 0;
int whileCounter = 0;

void  initAssemblyFile(){
    // Creates a MIPS file with a generic header that needs to be in every file
    // make the text file blank
    MIPScode = fopen("MIPScode.asm", "w");
    fclose(MIPScode);
    MIPSdata = fopen("MIPSvariables.asm", "w");
    fclose(MIPSdata);
    MIPSlabels = fopen("MIPSlabels.asm", "w");
    fclose(MIPSlabels);
    MIPSfinal = fopen("MIPSfinal.asm", "w");
    fclose(MIPSfinal);

    initAssemblyDataFile();

    // open the file again to append
    MIPScode = fopen("MIPScode.asm", "a");
    fprintf(MIPScode, ".text\n");
    fprintf(MIPScode, "main:\n");
    fprintf(MIPScode, "# -----------------------\n");

}

void initAssemblyDataFile(){
    // Creates a MIPS file with a generic header that needs to be in every file
    // make the text file blank
    MIPSdata = fopen("MIPSvariables.asm", "w");
    fclose(MIPSdata);
    // open the file again to append

    MIPSdata = fopen("MIPSvariables.asm", "a");
    fprintf(MIPSdata, ".data\n");
    // fprintf(MIPScode, "# -----------------------\n");

}

void emitMIPSVariableDeclaration(char* id, char* type, char* value){
    // Write the variable declaration to the MIPScode file
    // check type of variable
    if(strcmp(type, "string") == 0) {
        fprintf(MIPSdata, "\t%s: .asciiz \"%s\"\n", id, value);
	}
    else {
        fprintf(MIPSdata, "\t%s: .word %s\n", id, value);
    }
}

void emitMIPSVariableUpdate(char* id, char* value){
    // Write the variable update to the MIPScode file
    // fprintf(MIPScode, "\tli $t0, %s\n", value);
    // fprintf(MIPScode, "\tsw $t0, %s\n", id);

    fprintf(MIPScode, "la $a0, %s\n", id);
    fprintf(MIPScode, "li $a1, %s\n", value);
    fprintf(MIPScode, "sw $a1, 0($a0)\n");
}

void emitMIPSAssignment(char * id1, char * id2){
  // This is the temporary approach, until register management is implemented

  fprintf(MIPScode, "li $t1, %s\n", id1);
  fprintf(MIPScode, "li $t2, %s\n", id2);
  fprintf(MIPScode, "li $t2, $t1\n");
}

void emitMIPSAddition(char * id1, char * id2){
  // This is the temporary approach, until register management is implemented

  fprintf(MIPScode, "li $t1,%s\n", id1);
  fprintf(MIPScode, "li $t2,%s\n", id2);
  fprintf(MIPScode, "add $t3, $t1, $t2\n");
}

void emitMIPSConstantIntAssignment (char id1[50], char id2[50]){
     // This is the temporary approach, until register management is implemented
     // The parameters of this function should inform about registers
     // For now, this is "improvised" to illustrate the idea of what needs to 
     // be emitted in MIPS

     // nextRegister = allocateRegister(id1);  // This is conceptual to inform what needs to be done later

    fprintf(MIPScode, "li $t0,%s\n", id2);
}

void emitMIPSWriteId(char * id){
    // This is what needs to be printed, but must manage registers
    // $a0 is the register through which everything is printed in MIPS
    
    fprintf(MIPScode, "li $a0,%s\n", id);
    fprintf(MIPScode, "li $v0,1\n");
    fprintf(MIPScode, "syscall\n");
}

void emitMIPSNewLine() {
    // This is what needs to be printed, but must manage registers
    // $a0 is the register through which everything is printed in MIPS
    
    fprintf(MIPScode, "li $a0,10\n");
    fprintf(MIPScode, "li $v0,11\n");
    fprintf(MIPScode, "syscall\n");
}

void emitMIPSFunctionDeclaration(char* functionName, char* returnValue) {
    // Write the function declaration to the MIPScode file
    fprintf(MIPSlabels, "%s:\n", functionName);
}

void emitMIPSIfStatement(char id1[50], char condition[50], char id2[50], char boolean[50]) {
    fclose(MIPScode);
    MIPScode = fopen("MIPScode.asm", "a");
    // Write the if statement to the MIPScode file
    fprintf(MIPScode, "li $t1,%s\n", id1);
    fprintf(MIPScode, "li $t2,%s\n", id2);

    // check if condition is ==, !=, <, >, <=, >=
    if        (strcmp(condition, "==") == 0) {
        fprintf(MIPScode, "beq $t1, $t2, ifTrue_%d\n", ifCounter);
    } else if (strcmp(condition, "!=") == 0) {
        fprintf(MIPScode, "bne $t1, $t2, ifTrue_%d\n", ifCounter);
    } else if (strcmp(condition, "<") == 0) {
        fprintf(MIPScode, "blt $t1, $t2, ifTrue_%d\n", ifCounter);
    } else if (strcmp(condition, ">") == 0) {
        fprintf(MIPScode, "bgt $t1, $t2, ifTrue_%d\n", ifCounter);
    } else if (strcmp(condition, "<=") == 0) {
        fprintf(MIPScode, "ble $t1, $t2, ifTrue_%d\n", ifCounter);
    } else if (strcmp(condition, ">=") == 0) {
        fprintf(MIPScode, "bge $t1, $t2, ifTrue_%d\n", ifCounter);
    } else if (atoi(boolean) == 1) {
        fprintf(MIPScode, "beq $zero, $zero, ifTrue_%d\n", ifCounter);
    }
      
    fclose(MIPScode);
    MIPScode = fopen("MIPSlabels.asm", "a");
    fprintf(MIPScode, "ifTrue_%d:\n", ifCounter);
    ifCounter++;
    // fprintf(MIPScode, "j ifFalse\n");

}

void emitMIPSElseStatement(char boolean[50]) {
    fclose(MIPScode);
    MIPScode = fopen("MIPScode.asm", "a");
    if(atoi(boolean) == 0) {
        fprintf(MIPScode, "beq $zero, $zero, ifTrue_%d\n", ifCounter);
    }

    fclose(MIPScode);
    MIPScode = fopen("MIPSlabels.asm", "a");
    fprintf(MIPScode, "ifTrue_%d:\n", ifCounter);

}

void emitMIPSIfElseStatement(char id1[50], char condition[50], char id2[50], char boolean[50]) {
    fclose(MIPScode);
    MIPScode = fopen("MIPSlabels.asm", "a");
    if(atoi(boolean) == 1) {
        fprintf(MIPScode, "beq $zero, $zero, ifFalse_%d\n", ifCounter);
    }
    else {
        emitMIPSIfStatement(id1, condition, id2, boolean);
    }
}

void emitMIPSEndIfStatement() {
    // Write the end if statement to the MIPScode file
    // fprintf(MIPScode, "jr $ra\n");

    fclose(MIPScode);
    MIPScode = fopen("MIPScode.asm", "a");
}

void emitEndOfAssemblyCode(){
    fprintf(MIPScode, "# -----------------\n");
    fprintf(MIPScode, "#  Done, terminate program.\n\n");
    fprintf(MIPScode, "li $a0,0     # flush print value with 0\n");
    fprintf(MIPScode, "li $v0,1     # call code for terminate\n");
    fprintf(MIPScode, "syscall      # system call (terminate)\n");
    fprintf(MIPScode, "li $v0,10    # call code for terminate\n");
    fprintf(MIPScode, "syscall      # system call (terminate)\n");
    fprintf(MIPScode, ".end main\n");
    fprintf(MIPScode, "# -----------------\n");
}

void combineMIPSFiles(){
    // This function combines the MIPScode.asm and MIPSvariables.asm files into one file
    // This is done by appending the MIPSvariables.asm file to the end of the MIPScode.asm file
    // The MIPSvariables.asm file is then deleted
    printf("Combining MIPS files...\n");
    fclose(MIPScode);
    fclose(MIPSdata);
    
    // open the files
    MIPScode = fopen("MIPScode.asm", "r");
    MIPSdata = fopen("MIPSvariables.asm", "r");
    MIPSlabels = fopen("MIPSlabels.asm", "r");
    MIPSfinal = fopen("MIPSfinal.asm", "w");

    // copy the contents of MIPSdata to MIPSfinal
    char c;
    while ((c = fgetc(MIPSdata)) != EOF) {
        fputc(c, MIPSfinal);
    }

    // copy the contents of MIPScode to MIPSfinal
    while ((c = fgetc(MIPScode)) != EOF) {
        fputc(c, MIPSfinal);
    }


    // copy the contents of MIPSlabels to MIPSfinal
    while ((c = fgetc(MIPSlabels)) != EOF) {
        fputc(c, MIPSfinal);
    }

    fprintf(MIPSfinal, "jr $ra\n");

    // close the files
    fclose(MIPScode);
    fclose(MIPSdata);
    fclose(MIPSlabels);
    fclose(MIPSfinal);

    // delete the MIPSvariables.asm file
    // remove("MIPSvariables.asm");
}
    
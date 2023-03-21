FILE * IRactive; // This is the active file that is being written to
FILE * IRcode;
FILE * IRcodefunctions;
// ---- Functions to handle IR code emissions ---- //

void initIRcodeFile(){
    IRcode = fopen("IRcode.ir", "a");
    IRcodefunctions = fopen("IRcodefunctions.ir", "a");
    IRactive = IRcode;
    fprintf(IRactive, "\n\n#### IR Code ####\n\n");
}

emitVariableDeclaration(char* scope, char* type, char* id, char* value){
    setIRActive(scope);
    fprintf(IRactive, "VAR: %s -> %s = %s\n", id, type, value);
}

void emitBinaryOperation(const char* scope, char op[1], const char* id1, const char* id2){
    // fprintf(IRactive, "T1 = %s %s %s", id1, op, id2);
    setIRActive(scope);
    fprintf(IRactive, "BINARY: %s %s %s\n", id1, op, id2);
}

void emitAssignment(char* scope, char * id1, char * id2){
  // This is the temporary approach, until temporary variables management is implemented

//   fprintf(IRactive, "T0 = %s\n", id1);
//   fprintf(IRactive, "T1 = %s\n", id2);
//   fprintf(IRactive, "T1 = T0\n");
    
      fprintf(IRactive, "EQUAL: %s = %s\n", id1, id2);
}


void emitConstantIntAssignment (char scope, char id1[50], char id2[50]){
    fprintf(IRactive, "%s = %s\n", id1, id2);
}

void emitWriteId(char * id){
    fprintf (IRactive, "output %s\n", id); // This is the intent... :)

    // This is what needs to be printed, but must manage temporary variables
    // We hardcode T2 for now, but you must implement a mechanism to tell you which one...
    // fprintf (IRcode, "output %s\n", "T2");
}

// create emitFunctionDeclaration which will create a new label with the 

// create function that switches the active file depending on what is passed in

void emitFunctionDeclaration(char* scope, char* functionName, char* returnValue) {
    // Write the function declaration to the IRcode file
    setIRActive(scope);
    fprintf(IRactive, "FUN: %s -> %s:\n", functionName, returnValue);

    //print paramterlist
    // fprintf(IRcode, "%s", parameterList);
}

void emitFunctionParameter(char* scope, char* parameterName, char* parameterType) {
    setIRActive(scope);
    fprintf(IRactive, "PARAM: %s_%s -> %s\n", scope, parameterName, parameterType);
}

void emitFunctionBlockStart() {
    IRactive = IRcodefunctions;
    fprintf(IRactive, "BLOCK START\n");
}

void emitFunctionBlockEnd() {
    IRactive = IRcodefunctions;
    fprintf(IRactive, "BLOCK END\n");
}

void setIRActive(char* scope) {
    if (strcmp(scope, "global") == 0) {
        IRactive = IRcode;
    } else {
        IRactive = IRcodefunctions;
    }
}
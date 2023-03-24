%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symbolTable.h"
#include "AST.h"
#include "IRcode.h"
#include "Assembly.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin; 

FILE * IRcode;
FILE * MIPScode;


void yyerror(const char* s);
char currentScope[50] = "global"; // "global" or the name of the function
int semanticCheckPassed = 1; // flags to record correctness of semantic checks
%}
 
%union {
	int number;
	char character;
	char* string;
	struct AST* ast;
}
 
%token <string> TYPE
%token <string> INT FLOAT CHAR BOOL STRING VOID 
%token <string> ID
%token <string> RETURN
%token <character> SEMICOLON
%token <character> COMMA
%token <character> EQUAL
%token <character> PLUS MINUS MULTIPLY DIVIDE
%token <character> LEFTPARENTHESIS
%token <character> RIGHTPARENTHESIS
%token <character> LEFTCURLYBRACKET
%token <character> RIGHCURLYBRACKET
%token <character> LEFTBRACKET
%token <character> RIGHTBRACKET
%token <character> UNARYNOT
%token <string> LOGICALAND
%token <string> LOGICALOR
%token <string> NUMBER
%token <string> WRITE
%token <string> FUN
%token <string> IF WHILE 
%token <string> LESS_THAN GREATER_THAN LESS_THAN_OR_EQUAL_TO GREATER_THAN_OR_EQUAL_TO EQUAL_TO NOT_EQUAL_TO

%printer { fprintf(yyoutput, "%s", $$); } ID;
%printer { fprintf(yyoutput, "%d", $$); } NUMBER;

%left PLUS MINUS
%left MULTIPLY DIVIDE
%left UNARYNOT

%left LOGICALAND
%left LOGICALOR

%type <ast> Program DeclList Decl VarDecl Stmt StmtList Expr FunDecl Block ParamList Param Type

%start Program

%%

Program: DeclList  { $$ = $1;
					 printf("\n--- Abstract Syntax Tree ---\n\n");
					 printAST($$,0);
					}

;

DeclList:	Decl DeclList	{ $1->left = $2;
							  $$ = $1;
							}
	| Decl	{ $$ = $1; }
;

Decl:	FunDecl 
	| VarDecl 
	| StmtList
; 

StmtList:	
	| Stmt StmtList { $1->left = $2;
					  $$ = $1;
					}
;

Stmt:	SEMICOLON	{}
	| Expr SEMICOLON	{$$ = $1;}
	| ReturnStmt SEMICOLON {  }
	| FunCall SEMICOLON { }
; 

Type: INT { strcpy($$->nodeType, "int"); strcpy($$->value, "0");}			// int default value is 0
	| FLOAT { strcpy($$->nodeType, "float"); strcpy($$->value, "0.0");}		// float default value is 0.0
	| BOOL { strcpy($$->nodeType, "bool"); strcpy($$->value, "0");}			// bool default value is 0
	| CHAR { strcpy($$->nodeType, "char"); strcpy($$->value, "");}			// char default value is ""
	| STRING { strcpy($$->nodeType, "string"); strcpy($$->value, "");} 		// string default value is ""
	| VOID { strcpy($$->nodeType, "void"); strcpy($$->value, "");}			// void default value is ""
;

ParamList:	
	| Type ID COMMA ParamList { printf("\n RECOGNIZED RULE: Parameter list %s\n", $2); 
	  	emitFunctionParameter(currentScope, $2, $1);
	}
	| Type ID {	printf("\n RECOGNIZED RULE: Parameter %s\n", $2); 
		emitFunctionParameter(currentScope, $2, $1);
	}
;

Param: Type ID COMMA Param
	| Type ID { }
	|
;

ReturnStmt:	RETURN Expr {
	printf("\n RECOGNIZED RULE: Return statement: %s with value:%s\n", $2, $2->value);
	// Symbol Table 
	symTabAccess();
	int inSymTab = found($2, currentScope);
	
	// currently this code has a problem, not every Expr will be in the symbol table

	// get value from symbol table if inSymTab
	if(inSymTab != -1) {
		// get the value from the symbol table
		char value[50];
		sprintf(value, "%s", getValue(inSymTab));
		printf("value: %s\n", value);
	}
	else {
		printf("not found %s in symtab - semantic error", $2);
	}
}
;

FunCall:	ID LEFTPARENTHESIS Param RIGHTPARENTHESIS { 
	printf("\n RECOGNIZED RULE: Function call %s\n", $1);
	// Symbol Table
 
}
| 
;


FunDecl:	FUN Type ID {
printf("\n RECOGNIZED RULE: Function declaration %s\n", $3);
																// Symbol Table
																symTabAccess();
																int inSymTab = found($3, currentScope);
																//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
																// turn $2 into string
																char funScope[50];
																sprintf(funScope, "%s", $3);
																// set current scope to function name
																strcpy(currentScope, funScope);
																
																// print the current scope
																if (inSymTab == -1) 
																	addItem($3, "Fun", $2, "Fun", 0, "global");
																else
																	printf("SEMANTIC ERROR: Fun %s is already in the symbol table", funScope);
																showSymTable();
																emitFunctionDeclaration(currentScope, $3, $2); 

																// ---- SEMANTIC ACTIONS by PARSER ----	
																// $$ = AST_Fun("Fun", $2, $3);
																
																//printf("-----------> %s", $$->LHS);
																
}  
LEFTPARENTHESIS ParamList RIGHTPARENTHESIS {emitFunctionBlockStart();}  Block	{  
											// change current scope back to global
											
											$$ = AST_Fun("Fun", $2, $3);
											// $$->right = AST_Block("Block", $8, $8); 
											// $$->left = AST_Block("Params", $2, $3);
											// add the block to the right hand side of the function
											// maybe if the scope is not global, don't run the code and update the symbol table
											// the code should really only run on a function call

											// implement emitFunctionDeclaration(char* functionName, char** parameterList, int numParameters)
											
											// print ParamList
											
											// print the entire parameter list 
											// emit function name
											emitFunctionBlockEnd();
											strcpy(currentScope, "global"); 
										} 
; 
 
Block: LEFTCURLYBRACKET DeclList StmtList RIGHCURLYBRACKET {
	$$ = AST_Block("Block", $2, $3); 
	// print the AST
	printf("\n--- Abstract Syntax Tree 2 ---\n\n");
	printAST($$,0);
	while($2->left != NULL) {
		printf("DeclList: %s\n", $2->left->LHS);
		printf("Value: %s\n", $2->left->RHS);  
		 
		$2 = $2->left;
		$$ = $2; 
	}
	// while($3->left != NULL) {
	// 	printf("StmtList: %s\n", $3->left->LHS);
	// 	printf("Value: %s\n", $3->left->RHS);
		
	// 	$3 = $3->left;
	// 	$$ = $3;
	// } 

	// loop through the statement list and look for return statements
	
}
;

 
VarDecl:	Type ID SEMICOLON	{ printf("\n RECOGNIZED RULE: Variable declaration %s\n", $2);
									// Symbol Table
									symTabAccess();
									int inSymTab = found($2, currentScope);
									//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
									
									if (inSymTab == -1)  
										addItem($2, "Var", $1->nodeType, $1->value, 0, currentScope);
									else
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", $2);
									showSymTable();
									
								  // ---- SEMANTIC ACTIONS by PARSER ----
								    $$ = AST_Type("Type",$1->nodeType, $1->value);
									printf("-----------> %s\n", $$->LHS);

									emitVariableDeclaration(currentScope, $1, $2, "0");
								}
| Type ID EQUAL Expr SEMICOLON { printf("\n RECOGNIZED RULE: Variable declaration %s\n", $2);
									// Symbol Table 
									symTabAccess();
									int inSymTab = found($2, currentScope);
									//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
									
									if (inSymTab == -1)  
										addItem($2, "Var", $1, $4->value, 0, currentScope); 
									else
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", $2);
									showSymTable();
									
								  // ---- SEMANTIC ACTIONS by PARSER ----
								    $$ = AST_Type("Type",$1,$2);
									printf("-----------> %s", $$->LHS);

									emitVariableDeclaration(currentScope, $1, $2, $4->value);
								}
| Type ID LEFTBRACKET Expr RIGHTBRACKET SEMICOLON { 
    // Symbol Table
    symTabAccess();
    int inSymTab = found($2, currentScope);
    if (inSymTab == -1) {
        // Add the array name to the symbol table
		// turn $4 into number
        addItem($2, "Arr", $1, "", atoi($4->value), currentScope);
    } else {
        printf("SEMANTIC ERROR: Array %s is already in the symbol table\n", $2);
    }
	// for loop that makes empty entries as many times as the number in $4
	int i;
	char defaultVal[3];
	if(strcmp($1, "int") == 0)
		strcpy(defaultVal, "0");
	else if(strcmp($1, "float") == 0)
		strcpy(defaultVal, "0.0");	// if I don't do this, the default value is corrupted (0.!)
	else if(strcmp($1, "char") == 0)
		strcpy(defaultVal, "");
	
	for (i = 0; i < atoi($4->value); i++) {
		// add i char to the end of $2
		char *arrName = malloc(strlen($2) + 2);
		strcpy(arrName, $2);
		char iChar[2];
		sprintf(iChar, "%d", i);
		strcat(arrName, iChar);
		printf("the value of $$ is %s\n", $$->value);
		addItem($2, "ArrVar", $1, defaultVal, 0, currentScope);
		$$ = AST_Type("[]",$1,$2);
	}
    showSymTable();

    // ---- SEMANTIC ACTIONS by PARSER ----
    $$ = AST_Type("[]", $1, $2);
    //printf("-----------> %s", $$->LHS);
}; 



Primary: ID 
	| NUMBER
	| LEFTPARENTHESIS Expr RIGHTPARENTHESIS
	| ID LEFTBRACKET Expr RIGHTBRACKET 
;

 

Expr: NUMBER            { $$ = $1; sprintf($$->value, "%s", $1); sprintf($$->nodeType, "%s", "number"); } 
	| MINUS NUMBER       { $$ = $2; sprintf($$->value, "-%s", $2); sprintf($$->nodeType, "%s", "number"); }
	| ID                { $$ = $1; sprintf($$->value, "%s", $1); }
	| LEFTPARENTHESIS Expr RIGHTPARENTHESIS %prec UNARYNOT   {$$ = $2; sprintf($$->value, "%s", $2->value);}
	| ID LEFTBRACKET Expr RIGHTBRACKET 
	{
		int inSymTab = found($1, currentScope);

		if(inSymTab == 1) {
			printf("SEMANTIC ERROR: Array %s is not in the symbol table\n", $1);
		} 
		else {
			int size = getArraySize($1, currentScope);
			int index = atoi($3->value);  

				if (index >= size) {
					printf("SEMANTIC ERROR: Index out of bounds for array %s\n", $1);
					semanticCheckPassed = 0;
				} else { 
					// Construct the AST for the array indexing
					// $$ = AST_BinaryExpression($1, $3);
					sprintf($$->value, "%s", getValue(inSymTab + index));
					sprintf($$->nodeType, "%s", "[]"); 
					printf("Setting value of %s to %s" , $1, getValue(inSymTab + index));
					// printf("hey guy, I am actually updating the symbol table here with %s\n", $3->value);
					// updateItemByID(inSymTab + index, $$->value);

					// sprintf($$->nodeType, "%s", "Arr"); 
					// turn $3 into number 
				} 
		} 
	}
    | ID EQUAL Expr   {
        // Update the value of the variable in the symbol table
		int inSymTab = found($1, currentScope);  

		// check if Expr nodeType is a number
		if($3->nodeType == "number") { 
			// Numbers don't exist in the symbol table. Skip this check.
				
		}
		else if (inSymTab == -1) {
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", $3->value);
			semanticCheckPassed = 0;
		}
  
		// else if(getVariableType($1, currentScope) == "Arr") {
		// 	// $1 is an array's index, not the id.
		// 	int size = getArraySize($1, currentScope);
		// 		if (atoi($3) >= size) {
		// 			printf("SEMANTIC ERROR: Index out of bounds for array %s\n", $1);
		// 			semanticCheckPassed = 0;
		// 		} else {
		// 			char* value = getValue(inSymTab + atoi($3));
		// 			// Create a new node for the array element
		// 			sprintf($3->value, "%s", value);
		// 			printf("hey guys, I am actually updating the symbol table here with %s\n", $1);
 
		// 			// print the Expr
		// 			updateItemByID(inSymTab + atoi($3->value), $3->value);
		// 			// $$ = AST_BinaryExpression("=", $1, value); 
		// 		}
		// }
		else {
			// print the Expr
			printf( "Expr: %s", $3->value);
            updateItem($1, $3->value, currentScope);
            $$ = AST_BinaryExpression("=", $1, $3->value);
        }

		emitAssignment(currentScope, $1, $3->value);
	 
     }
	 | ID LEFTBRACKET Expr RIGHTBRACKET EQUAL Expr {
		 // Update the value of the variable in the symbol table
		int inSymTab = found($1, currentScope);  

		// check if Expr nodeType is a number
		if (inSymTab == -1) {
			printf("SEMANTIC ERROR: Array %s is not in the symbol table\n", $1);
			semanticCheckPassed = 0;
		}
		else {  
			// $1 is an array's index, not the id.

			int size = getArraySize($1, currentScope);
				if (atoi($3) >= size) {
					printf("SEMANTIC ERROR: Index out of bounds for array %s\n", $1);
					semanticCheckPassed = 0;
				} else {
					char* value = getValue(inSymTab + atoi($3));
					// Create a new node for the array element
					printf("hey guys, I am actually updating the symbol table here with %s\n", $1);
 
					// print the Expr
					updateItemByID(inSymTab + atoi($3->value), $6->value);
					
					$$ = AST_BinaryExpression("[]", $1, value); 
				}
		}

		emitAssignment(currentScope, $1, $3->value);
		
	 }
     | Expr PLUS Expr   { 
		// Check if the variables are in the symbol table
		int inSymTab1 = found($1, currentScope);
		int inSymTab2 = found($3, currentScope);

		// Check if Expr $1's nodeType is a number or a variable
		if(strcmp($1->nodeType, "number") == 0) {
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if(inSymTab1 == -1) {
			// Variable is not in the symbol table
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", $1->value);
			semanticCheckPassed = 0;
		}
		// Variable is in the symbol table
		else if(inSymTab1 != -1) {
			// Update the value according to the symbol table
			sprintf($1->value, "%s", getValue(inSymTab1));
		}

		// check if Expr $3's nodeType is a number
		if(strcmp($3->nodeType, "number") == 0) { 
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if (inSymTab2 == -1) {
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", $3->value);
			semanticCheckPassed = 0; 
		} 
		// Variable is in the symbol table
		else if(inSymTab2 != -1) {  
			// Update the value according to the symbol table
			sprintf($3->value, "%s", getValue(inSymTab2));
		}
		// Generate AST for the addition
		$$ = AST_BinaryExpression("+", $1, $3); 

		// Perform the addition, and update the value of the expression
		char stringVal[50];
		sprintf(stringVal, "%d", atoi($1->value) + atoi($3->value));
		sprintf($$->value, "%s", stringVal);

		// IR time
		emitBinaryOperation(currentScope, "+", $1->value, $3->value);
		}
     | Expr MINUS Expr  { 
		// Check if the variables are in the symbol table
		int inSymTab1 = found($1, currentScope);
		int inSymTab2 = found($3, currentScope);

		// Check if Expr $1's nodeType is a number or a variable
		if(strcmp($1->nodeType, "number") == 0) {
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if(inSymTab1 == -1) {
			// Variable is not in the symbol table
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", $1->value);
			semanticCheckPassed = 0;
		}
		// Variable is in the symbol table
		else if(inSymTab1 != -1) {
			// Update the value according to the symbol table
			sprintf($1->value, "%s", getValue(inSymTab1));
		}

		// check if Expr $3's nodeType is a number
		if(strcmp($3->nodeType, "number") == 0) { 
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if (inSymTab2 == -1) {
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", $3->value);
			semanticCheckPassed = 0; 
		}  
		// Variable is in the symbol table
		else if(inSymTab2 != -1) {  
			// Update the value according to the symbol table
			sprintf($3->value, "%s", getValue(inSymTab2));
		}
		char stringVal[50];
		// Perform the addition
		sprintf(stringVal, "%d", atoi($1->value) - atoi($3->value));
		// Generate AST for the multiplication
		$$ = AST_BinaryExpression("-", $1, $3); 
		// Update the value of the expression
		sprintf($$->value, "%s", stringVal);

		// IR time
		emitBinaryOperation(currentScope, "-", $1->value, $3->value);
	 }
     | Expr MULTIPLY Expr  {
		printf("EXPR1 is %s", $1->nodeType);
		printf("EXPR2 is %s", $3->nodeType); 
		// Check if the variables are in the symbol table
		int inSymTab1 = found($1, currentScope);
		int inSymTab2 = found($3, currentScope);
		
		printf("inSymTab1: %d" , inSymTab1);
		printf("inSymTab2: %d" , inSymTab2);

		// Check if Expr $1's nodeType is a number or a variable
		if(strcmp($1->nodeType, "number") == 0) {
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if(inSymTab1 == -1) {
			// Variable is not in the symbol table
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", $1->value);
			semanticCheckPassed = 0;
		}
		// Variable is in the symbol table
		else if(inSymTab1 != -1) {
			// Update the value according to the symbol table
			sprintf($1->value, "%s", getValue(inSymTab1));
		}

		// check if Expr $3's nodeType is a number
		if(strcmp($3->nodeType, "number") == 0) { 
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if (inSymTab2 == -1) {
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", $3->value);
			semanticCheckPassed = 0; 
		} 
		// Variable is in the symbol table
		else if(inSymTab2 != -1) {  
			// Update the value according to the symbol table
			sprintf($3->value, "%s", getValue(inSymTab2));
		}
 
		char stringVal[50];
		// Perform the addition
		sprintf(stringVal, "%d", atoi($1->value) * atoi($3->value));
		// Generate AST for the multiplication
		$$ = AST_BinaryExpression("*", $1, $3); 
		// Update the value of the expression
		sprintf($$->value, "%s", stringVal);

		// IR time
		emitBinaryOperation(currentScope, "*", $1->value, $3->value);

	 }
     | Expr DIVIDE Expr { 
		// Check if the variables are in the symbol table
		int inSymTab1 = found($1, currentScope);
		int inSymTab2 = found($3, currentScope);

		// Check if Expr $1's nodeType is a number or a variable
		if(strcmp($1->nodeType, "number") == 0) {
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if(inSymTab1 == -1) {
			// Variable is not in the symbol table
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", $1->value);
			semanticCheckPassed = 0;
		}
		// Variable is in the symbol table
		else if(inSymTab1 != -1) {
			// Update the value according to the symbol table
			sprintf($1->value, "%s", getValue(inSymTab1));
		}

		// check if Expr $3's nodeType is a number
		if(strcmp($3->nodeType, "number") == 0) { 
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if (inSymTab2 == -1) {
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", $3->value);
			semanticCheckPassed = 0; 
		} 
		// Variable is in the symbol table
		else if(inSymTab2 != -1) {  
			// Update the value according to the symbol table
			sprintf($3->value, "%s", getValue(inSymTab2));
		}

		// Perform the addition, and update the value of the expression
		char stringVal[50];
		if(atoi($3->value) == 0) {
			printf("SEMANTIC ERROR: Cannot divide by 0!\n");
			exit(1);
			semanticCheckPassed = 0;
		}
		else {
			sprintf(stringVal, "%d", atoi($1->value) / atoi($3->value));
			// Generate AST for the addition
			$$ = AST_BinaryExpression("/", $1, $3);  
			sprintf($$->value, "%s", stringVal);
		}

		// IR time
		emitBinaryOperation(currentScope, "/", $1->value, $3->value);
     }
	 | Expr EQUAL_TO Expr {
		// Check if the variables are in the symbol table
		int inSymTab1 = found($1, currentScope);
		int inSymTab2 = found($3, currentScope);

		// Check if Expr $1's nodeType is a number or a variable
		if(strcmp($1->nodeType, "number") == 0) {
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if(inSymTab1 == -1) {
			// Variable is not in the symbol table
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", $1->value);
			semanticCheckPassed = 0;
		}
		// Variable is in the symbol table
		else if(inSymTab1 != -1) {
			// Update the value according to the symbol table
			sprintf($1->value, "%s", getValue(inSymTab1));
		}

		// check if Expr $3's nodeType is a number
		if(strcmp($3->nodeType, "number") == 0) { 
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if (inSymTab2 == -1) {
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", $3->value);
			semanticCheckPassed = 0; 
		}
		// Variable is in the symbol table
		else if(inSymTab2 != -1) {  
			// Update the value according to the symbol table
			sprintf($3->value, "%s", getValue(inSymTab2));
		}

		// Check if the expression is true or false
		char stringVal[50];
		if(atoi($1->value) == atoi($3->value)) {
			sprintf(stringVal, "%d", 1);
			printf("TRUE\n"); 
		}
		else {
			sprintf(stringVal, "%d", 0);
			printf("FALSE\n");  
		}

		// Generate AST for the less than expression
		$$ = AST_BinaryExpression("==", $1, $3);
		sprintf($$->value, "%s", stringVal);
	 }
	 | Expr NOT_EQUAL_TO Expr {
		// Check if the variables are in the symbol table
		int inSymTab1 = found($1, currentScope);
		int inSymTab2 = found($3, currentScope);

		// Check if Expr $1's nodeType is a number or a variable
		if(strcmp($1->nodeType, "number") == 0) {
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if(inSymTab1 == -1) {
			// Variable is not in the symbol table
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", $1->value);
			semanticCheckPassed = 0;
		}
		// Variable is in the symbol table
		else if(inSymTab1 != -1) {
			// Update the value according to the symbol table
			sprintf($1->value, "%s", getValue(inSymTab1));
		}

		// check if Expr $3's nodeType is a number
		if(strcmp($3->nodeType, "number") == 0) { 
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if (inSymTab2 == -1) {
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", $3->value);
			semanticCheckPassed = 0; 
		}
		// Variable is in the symbol table
		else if(inSymTab2 != -1) {  
			// Update the value according to the symbol table
			sprintf($3->value, "%s", getValue(inSymTab2));
		}

		// Check if the expression is true or false
		char stringVal[50];
		if(atoi($1->value) != atoi($3->value)) {
			sprintf(stringVal, "%d", 1);
			printf("TRUE\n");
		}
		else {
			sprintf(stringVal, "%d", 0);
			printf("FALSE\n");  
		}

		// Generate AST for the less than expression
		$$ = AST_BinaryExpression("!=", $1, $3);
		sprintf($$->value, "%s", stringVal);
	 }
	 | Expr LESS_THAN Expr {
		// Check if the variables are in the symbol table
		int inSymTab1 = found($1, currentScope);
		int inSymTab2 = found($3, currentScope);

		// Check if Expr $1's nodeType is a number or a variable
		if(strcmp($1->nodeType, "number") == 0) {
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if(inSymTab1 == -1) {
			// Variable is not in the symbol table
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", $1->value);
			semanticCheckPassed = 0;
		}
		// Variable is in the symbol table
		else if(inSymTab1 != -1) {
			// Update the value according to the symbol table
			sprintf($1->value, "%s", getValue(inSymTab1));
		}

		// check if Expr $3's nodeType is a number
		if(strcmp($3->nodeType, "number") == 0) { 
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if (inSymTab2 == -1) {
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", $3->value);
			semanticCheckPassed = 0; 
		}
		// Variable is in the symbol table
		else if(inSymTab2 != -1) {  
			// Update the value according to the symbol table  
			sprintf($3->value, "%s", getValue(inSymTab2));
		}

		// Check if the expression is true or false
		char stringVal[50];
		if(atoi($1->value) < atoi($3->value)) {
			sprintf(stringVal, "%d", 1);
			printf("TRUE\n");
		}
		else {
			sprintf(stringVal, "%d", 0);
			printf("FALSE\n");  
		}

		// Generate AST for the less than expression
		$$ = AST_BinaryExpression("<", $1, $3);
		sprintf($$->value, "%s", stringVal);
	 }
	 | Expr LESS_THAN_OR_EQUAL_TO Expr {
		// Check if the variables are in the symbol table
		int inSymTab1 = found($1, currentScope);
		int inSymTab2 = found($3, currentScope);

		// Check if Expr $1's nodeType is a number or a variable
		if(strcmp($1->nodeType, "number") == 0) {
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if(inSymTab1 == -1) {
			// Variable is not in the symbol table
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", $1->value);
			semanticCheckPassed = 0;
		}
		// Variable is in the symbol table
		else if(inSymTab1 != -1) {
			// Update the value according to the symbol table
			sprintf($1->value, "%s", getValue(inSymTab1));
		}

		// check if Expr $3's nodeType is a number
		if(strcmp($3->nodeType, "number") == 0) { 
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if (inSymTab2 == -1) {
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", $3->value);
			semanticCheckPassed = 0; 
		}
		// Variable is in the symbol table
		else if(inSymTab2 != -1) {  
			// Update the value according to the symbol table
			sprintf($3->value, "%s", getValue(inSymTab2));
		}

		// Check if the expression is true or false
		char stringVal[50];
		if(atoi($1->value) <= atoi($3->value)) {
			sprintf(stringVal, "%d", 1);
			printf("TRUE\n");
		}
		else {
			sprintf(stringVal, "%d", 0);
			printf("FALSE\n");  
		}

		// Generate AST for the less than expression
		$$ = AST_BinaryExpression("<=", $1, $3);
		sprintf($$->value, "%s", stringVal);
	 }
	 | Expr GREATER_THAN Expr {
		// Check if the variables are in the symbol table
		int inSymTab1 = found($1, currentScope);
		int inSymTab2 = found($3, currentScope);

		// Check if Expr $1's nodeType is a number or a variable
		if(strcmp($1->nodeType, "number") == 0) {
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if(inSymTab1 == -1) {
			// Variable is not in the symbol table
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", $1->value);
			semanticCheckPassed = 0;
		}
		// Variable is in the symbol table
		else if(inSymTab1 != -1) {
			// Update the value according to the symbol table
			sprintf($1->value, "%s", getValue(inSymTab1));
		}

		// check if Expr $3's nodeType is a number
		if(strcmp($3->nodeType, "number") == 0) { 
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if (inSymTab2 == -1) {
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", $3->value);
			semanticCheckPassed = 0; 
		}
		// Variable is in the symbol table
		else if(inSymTab2 != -1) {  
			// Update the value according to the symbol table
			sprintf($3->value, "%s", getValue(inSymTab2));
		}

		// Check if the expression is true or false
		char stringVal[50];
		if(atoi($1->value) > atoi($3->value)) {
			sprintf(stringVal, "%d", 1);
			printf("TRUE\n");
		}
		else {
			sprintf(stringVal, "%d", 0);
			printf("FALSE\n");  
		}

		// Generate AST for the less than expression
		$$ = AST_BinaryExpression(">", $1, $3);
		sprintf($$->value, "%s", stringVal);
	 }
	 | Expr GREATER_THAN_OR_EQUAL_TO Expr {
		// Check if the variables are in the symbol table
		int inSymTab1 = found($1, currentScope);
		int inSymTab2 = found($3, currentScope);

		// Check if Expr $1's nodeType is a number or a variable
		if(strcmp($1->nodeType, "number") == 0) {
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if(inSymTab1 == -1) {
			// Variable is not in the symbol table
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", $1->value);
			semanticCheckPassed = 0;
		}
		// Variable is in the symbol table
		else if(inSymTab1 != -1) {
			// Update the value according to the symbol table
			sprintf($1->value, "%s", getValue(inSymTab1));
		}

		// check if Expr $3's nodeType is a number
		if(strcmp($3->nodeType, "number") == 0) { 
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if (inSymTab2 == -1) {
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", $3->value);
			semanticCheckPassed = 0; 
		}
		// Variable is in the symbol table
		else if(inSymTab2 != -1) {  
			// Update the value according to the symbol table
			sprintf($3->value, "%s", getValue(inSymTab2));
		}

		// Check if the expression is true or false
		char stringVal[50];
		if(atoi($1->value) >= atoi($3->value)) {
			sprintf(stringVal, "%d", 1);
			printf("TRUE\n");
		}
		else {
			sprintf(stringVal, "%d", 0);
			printf("FALSE\n");  
		}

		// Generate AST for the less than expression
		$$ = AST_BinaryExpression(">=", $1, $3);
		sprintf($$->value, "%s", stringVal);
	 }
;

UnaryOp: MINUS
	| UNARYNOT
;

BinaryOp: PLUS
	| MINUS
	| MULTIPLY
	| DIVIDE
	| LOGICALAND
	| LOGICALOR
;

%%

int main(int argc, char**argv)
{
	strcpy(currentScope, "global");
/*
	#ifdef YYDEBUG
		yydebug = 1;
	#endif
*/
	printf("\n\n##### COMPILER STARTED #####\n\n");
	 
	if (argc > 1){
	  if(!(yyin = fopen(argv[1], "r")))
          {
		perror(argv[1]);
		return(1);
	  }
	} 

	// Initialize IR and MIPS files
	initIRcodeFile(); 
	initAssemblyFile();

	// Start parser
	yyparse();

	// Add the closing part required for any MIPS file
	emitEndOfAssemblyCode();
	showSymTable();
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}


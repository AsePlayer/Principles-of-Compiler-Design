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
%token <character> UNARYNOT
%token <string> LOGICALAND
%token <string> LOGICALOR
%token <string> NUMBER
%token <string> WRITE
%token <string> FUN

%printer { fprintf(yyoutput, "%s", $$); } ID;
%printer { fprintf(yyoutput, "%d", $$); } NUMBER;

%type <ast> Program DeclList Decl VarDecl Stmt StmtList Expr FunDecl

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
	| Stmt StmtList
;

Stmt:	SEMICOLON	{}
	| Expr SEMICOLON	{$$ = $1;}
;

FunDecl:	FUN TYPE ID {
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

																// ---- SEMANTIC ACTIONS by PARSER ----	
																AST_Fun("Fun", $2, $3);
																//printf("-----------> %s", $$->LHS);
} 
LEFTPARENTHESIS RIGHTPARENTHESIS Block	{ 
											// change current scope back to global
											strcpy(currentScope, "global");
										}
;

Block: LEFTCURLYBRACKET DeclList StmtList RIGHCURLYBRACKET 
;
 
VarDecl:	TYPE ID SEMICOLON	{ printf("\n RECOGNIZED RULE: Variable declaration %s\n", $2);
									// Symbol Table
									symTabAccess();
									int inSymTab = found($2, currentScope);
									//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
									
									if (inSymTab == -1)  
										addItem($2, "Var", $1, "", 0, currentScope);
									else
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", $2);
									showSymTable();
									
								  // ---- SEMANTIC ACTIONS by PARSER ----
								    $$ = AST_Type("Type",$1,$2);
									printf("-----------> %s", $$->LHS);
								}
;



Primary: ID
	| NUMBER
	| LEFTPARENTHESIS Expr RIGHTPARENTHESIS
;
 

Expr: NUMBER            { $$ = $1; sprintf($$->value, "%s", $1); } 
     | ID EQUAL Expr   {
        // Update the value of the variable in the symbol table
        int inSymTab = found($1, currentScope);
        if (inSymTab == -1) {
            printf("SEMANTIC ERROR: Variable '%s' is not in the symbol table\n", $1);
            semanticCheckPassed = 0; 
        } else {
			// print the Expr
			printf( "Expr: %s", $3->value);
            updateItem($1, $3->value, currentScope);
            $$ = AST_BinaryExpression("=", $1, $3->value);
        }
     }   
     | Expr PLUS Expr   { 
		// calculate the value of the expression
		int total = atoi($1->value) + atoi($3->value);  
		$$ = AST_BinaryExpression("+", $1, $3); 
		// convert value to string
		char stringVal[50];
		sprintf(stringVal, "%d", total);
		// set the value of the expression
		sprintf($$->value, "%s", stringVal);
		// printf("Expr PLUS: %d", total);
		printf( "Expr: %s ", $$->value);
		}
     | Expr MINUS Expr  { 
		// calculate the value of the expression
		int total = atoi($1->value) - atoi($3->value); 
		$$ = AST_BinaryExpression("-", $1, $3);
		// convert value to string
		char stringVal[50];
		sprintf(stringVal, "%d", total);
		// set the value of the expression
		sprintf($$->value, "%s", stringVal);
	 }
     | Expr MULTIPLY Expr  {
		// calculate the value of the expression
		int total = atoi($1->value) * atoi($3->value);
		$$ = AST_BinaryExpression("*", $1, $3);
		// convert value to string
		char stringVal[50];
		sprintf(stringVal, "%d", total);
		// set the value of the expression
		sprintf($$->value, "%s", stringVal);
	 }
     | Expr DIVIDE Expr { 

     }
     | LEFTPARENTHESIS Expr RIGHTPARENTHESIS    {  }
     ;

/* Expr: Primary 
    | Expr PLUS Expr {
        $$ = AST_BinaryExpression("+", $1, $3);
		// calculate the value of the expression
		// $$->value = $1->value + $3->value;
		printf("\n--- Abstract Syntax Tree ---\n\n");
		printAST($$,0);

		//printf("PLUSPLUS val1: %s val2: %s \n", val1, val2);
    } // addition
    | Expr MINUS Expr {
        $$ = AST_BinaryExpression("-", $1, $3);
				printf("\n--- Abstract Syntax Tree ---\n\n");
		printAST($$,0);
    } // subtraction
    | Expr MULTIPLY Expr {
        $$ = AST_BinaryExpression("*", $1, $3);
				printf("\n--- Abstract Syntax Tree ---\n\n");
		printAST($$,0);
    } // multiplication
    | Expr DIVIDE Expr {
        $$ = AST_BinaryExpression("/", $1, $3);
				printf("\n--- Abstract Syntax Tree ---\n\n");
		printAST($$,0);
    } // division
    | UnaryOp Expr {
        printf("\n RECOGNIZED RULE: Unary expression\n");
    } // unary minus
    | ID EQUAL Expr {
        printf("\n RECOGNIZED RULE: Assignment statement\n");		
		// turn $2 and $3 into strings
		char var[50];
		sprintf(var, "%s", $1);
		char val[50];
		sprintf(val, "%s", $3);
		printf("var: %s val: %s \n", var, val);

		// check if val is a number
		if (isdigit(val[0])) {
			// update symbol table 
			updateItem($1, $3, currentScope);
			$$ = AST_assignment("=", $3, var, val);
		}
		else {

		sprintf(val, "%s",  $3->value);
		}

		// get the value of the expression

		// print identifier and value
		printf(" =LOOKIN FOR WOW var: %s val: %s \n", var, val);


		// update symbol table 
		updateItem($1, $3, currentScope);
        $$ = AST_assignment("=", $3, var, val);		

		showSymTable();
		// print the AST
		printf("\n--- Abstract Syntax Tree ---\n\n");
		

		// printAST($$,0);
    } // assignment statement 
; */
	/* | ID EQUAL Expr 	{ printf("\n RECOGNIZED RULE: Assignment statement\n"); 
						// ---- SEMANTIC ACTIONS by PARSER ---- //
						  $$ = AST_assignment("=",$1,$3);

						// ---- SEMANTIC ANALYSIS ACTIONS ---- //  

						// Check if identifiers have been declared

						    if(found($1, currentScope) == -1) {
								printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $1, currentScope);
								semanticCheckPassed = 0;
							}
						    if(found($3, currentScope) == -1){
								printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $1, currentScope);
								semanticCheckPassed = 0;
							}

						// Check types

							printf("\nChecking types: \n");
							// int typeMatch = compareTypes ($1, $3, currentScope);
							// if (typeMatch == -1){
							// 	printf("SEMANTIC ERROR: Type mismatch for variables %s and %s \n", $1, $3);
							// 	semanticCheckPassed = 0;
							// }
							

						if (semanticCheckPassed != -1) {
							printf("\n\n>>> AssignStmt Rule is SEMANTICALLY CORRECT");
						}
						
						// ---- END OF SEMANTIC ANALYSIS ACTIONS ---- //
						updateItem($1, $3, currentScope); 
	}
; */

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

/* Body: LCURL RCURL	{ $$ = AST_Body("Body", $1, $2); }
	| LCURL StmtList RCURL	{ $$ = AST_Body("Body", $1, $2, $3); }
	; */
  
/* Expr:	ID { printf("\n RECOGNIZED RULE: Simplest expression\n"); //E.g. function call
		   }
	| ID EQUAL ID 	{ printf("\n RECOGNIZED RULE: Assignment statement\n"); 
					// ---- SEMANTIC ACTIONS by PARSER ---- //
					  $$ = AST_assignment("=",$1,$3);

					// ---- SEMANTIC ANALYSIS ACTIONS ---- //  

					// Check if identifiers have been declared

					    if(found($1, currentScope) == -1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $1, currentScope);
							semanticCheckPassed = 0;
						}
					    if(found($3, currentScope) == -1){
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $1, currentScope);
							semanticCheckPassed = 0;
						}

					// Check types

						printf("\nChecking types: \n");
						int typeMatch = compareTypes ($1, $3, currentScope);
						if (typeMatch == -1){
							printf("SEMANTIC ERROR: Type mismatch for variables %s and %s \n", $1, $3);
							semanticCheckPassed = 0;
						}
						

					if (semanticCheckPassed != -1) {
						printf("\n\n>>> AssignStmt Rule is SEMANTICALLY correct and IR code is emitted! <<<\n\n");

						// ---- EMIT IR 3-ADDRESS CODE ---- //
						
						// The IR code is printed to a separate file

						// Temporary variables management will eventually go in here
						// and the paramaters of the function below will change
						// to using T0, ..., T9 variables

						emitAssignment($1, $3);

						// ----     EMIT MIPS CODE   ----  //

						// The MIPS code is printed to a separate file

						// MIPS registers management will eventually go in here
						// and the paramaters of the function below will change
						// to using $t0, ..., $t9 registers

						emitMIPSAssignment($1, $3);



					}
					

				}

	| ID EQUAL NUMBER 	{ printf("\n RECOGNIZED RULE: Constant Assignment statement\n"); 
					   // ---- SEMANTIC ACTIONS by PARSER ----
					   char str[50];
					   sprintf(str, "%s", $3); // convert $3 from int to string
					   $$ = AST_assignment("=",$1, str);
					   

 
					   // set $3 variable type to "number" in symbol table using addItem function
					  


						// ---- SEMANTIC ANALYSIS ACTIONS ---- //  

						// Check if identifiers have been declared
 
					    if(found($1, currentScope) == -1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $1, currentScope);
							semanticCheckPassed = 0; 
									
							printf("scope: %s\n", currentScope);
							
						}
			
						
						// Check types

						printf("\nChecking types: \n");

						printf("%s = %s\n", getVariableType($1, currentScope), "int");
						
						// printf("%s = %s\n", "int", "number");  // This temporary for now, until the line above is debugged and uncommented
						
						if (semanticCheckPassed == 1) {
							printf("\n\nRule is semantically correct!\n\n");

							// ---- EMIT IR 3-ADDRESS CODE ---- //
							
							// The IR code is printed to a separate file

							// Temporary variables management will eventually go in here
							// and the paramaters of the function below will change
							// to using T0, ..., T9 variables
							// set it in the symbol table using updateItem function
					   		 

							char id1[50], id2[50];
							sprintf(id1, "%s", $1);
							sprintf(id2, "%s", $3);

							updateItem($1, currentScope, id2);

							// Temporary variables management will eventually go in here
							// and the paramaters of the function below will change
							// to using T0, ..., T9 variables

							emitConstantIntAssignment(id1, id2);

							 // ----     EMIT MIPS CODE   ----  //

							// The MIPS code is printed to a separate file

							// MIPS registers management will eventually go in here
							// and the paramaters of the function below will change
							// to using $t0, ..., $t9 registers

							emitMIPSConstantIntAssignment(id1, id2);
 
						}
					}
					| ID EQUAL NUMBER PLUS NUMBER { printf("\n RECOGNIZED RULE: Constant Addition statement\n"); 
					   // ---- SEMANTIC ACTIONS by PARSER ----
					   char str1[50];
					   char str2[50];
					   sprintf(str1, "%s", $3); // convert $3 from int to string
					   sprintf(str2, "%s", $5); // convert $5 from int to string
					   $$ = AST_assignment("+",str1, str2);

					   emitMIPSAddition(str1, str2);

					   // update value in symbol table
					   char str3[50];
					   sprintf(str3, "%d", atoi(str1) + atoi(str2));
					   updateItem($1, currentScope, str3);
 
					   // set $3 variable type to "number" in symbol table using addItem function
					   
					   // TODO: EMIT ON TREE AND IR CODE
					}
	
	| WRITE ID 	{ printf("\n RECOGNIZED RULE: WRITE statement\n");
					$$ = AST_Write("write",$2,"");
					
					// ---- SEMANTIC ANALYSIS ACTIONS ---- //  

					// Check if identifiers have been declared
					    if(found($2, currentScope) == -1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $2, currentScope);
							semanticCheckPassed = 0;
						}

					if (semanticCheckPassed == 1) {
							printf("\n\nRule is semantically correct!\n\n");

							// ---- EMIT IR 3-ADDRESS CODE ---- //
							
							// The IR code is printed to a separate file
							
							emitWriteId($2);

							// ----     EMIT MIPS CODE   ----  //

							// The MIPS code is printed to a separate file

							// MIPS registers management will eventually go in here
							// and the paramaters of the function below will change
							// to using $t0, ..., $t9 registers

							emitMIPSWriteId($2);
						}
				}
; */

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
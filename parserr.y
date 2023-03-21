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
%token <character> LEFTBRACKET
%token <character> RIGHTBRACKET
%token <character> UNARYNOT
%token <string> LOGICALAND
%token <string> LOGICALOR
%token <string> NUMBER
%token <string> WRITE
%token <string> FUN

%printer { fprintf(yyoutput, "%s", $$); } ID;
%printer { fprintf(yyoutput, "%d", $$); } NUMBER;

%left PLUS MINUS
%left MULTIPLY DIVIDE
%right UNARYNOT
%left LOGICALAND
%left LOGICALOR

%type <ast> Program DeclList Decl VarDecl Stmt StmtList Expr FunDecl Block 

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

ParamList:	TYPE ID COMMA ParamList	
	| TYPE ID 
	|
;

Params: Primary COMMA Params
	| Primary 
	|
;

ReturnStmt:	RETURN Expr {
	printf("\n RECOGNIZED RULE: Return statement: %s with value:%s\n", $2, $2->value);
	// Symbol Table 
	symTabAccess();
	int inSymTab = found($2, currentScope);
	//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
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

FunCall:	ID LEFTPARENTHESIS Params RIGHTPARENTHESIS {
	printf("\n RECOGNIZED RULE: Function call %s\n", $1);
	// Symbol Table
 
}
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
																// $$ = AST_Fun("Fun", $2, $3);
																
																//printf("-----------> %s", $$->LHS);
} 
LEFTPARENTHESIS ParamList RIGHTPARENTHESIS Block	{ 
											// change current scope back to global
											
											$$ = AST_Fun("Fun", $2, $3);
											$$->right = AST_Block("Block", $8, $8); 
											// $$->left = AST_Block("Params", $2, $3);
											// add the block to the right hand side of the function
											// maybe if the scope is not global, don't run the code and update the symbol table
											// the code should really only run on a function call

											// implement emitFunctionDeclaration(char* functionName, char** parameterList, int numParameters)
											char *parameterList[50];
											int numParameters = 0;

											// loop through the parameter list and add them to the parameterList
											// print paramlist
											// while($8->left != NULL) {
											// 	printf("ParamList: %s\n", $8->left->LHS);
											// 	printf("Value: %s\n", $8->left->RHS);
											// 	// printf("Value: %s\n", $8->left->RHS);  
											// 	// add the parameter to the parameter list
											// 	parameterList[numParameters] = $8->left->RHS;
											// 	numParameters++;
											// 	$8 = $8->left;
											// }

											// print the entire parameter list 
											emitFunctionDeclaration($3, parameterList, numParameters);
											strcpy(currentScope, "global"); 
										}
; 
 
Block: LEFTCURLYBRACKET DeclList StmtList RIGHCURLYBRACKET {
	$$ = AST_Block("Block", $2, $3); 
	// print the AST
	printf("\n--- Abstract Syntax Tree 2 ---\n\n");
	printAST($$,0);
	// while($2->left != NULL) {
	// 	printf("DeclList: %s\n", $2->left->LHS);
	// 	printf("Value: %s\n", $2->left->RHS);  
		 
	// 	$2 = $2->left;
	// 	$$ = $2;
	// }
	// while($3->left != NULL) {
	// 	printf("StmtList: %s\n", $3->left->LHS);
	// 	printf("Value: %s\n", $3->left->RHS);
		
	// 	$3 = $3->left;
	// 	$$ = $3;
	// } 

	// loop through the statement list and look for return statements
	
}
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
| TYPE ID LEFTBRACKET NUMBER RIGHTBRACKET SEMICOLON { 
    // Symbol Table
    symTabAccess();
    int inSymTab = found($2, currentScope);
    if (inSymTab == -1) {
        // Add the array name to the symbol table
		// turn $4 into number
        addItem($2, "Arr", $1, "", atoi($4), currentScope);
    } else {
        printf("SEMANTIC ERROR: Array %s is already in the symbol table\n", $2);
    }
	// for loop that makes empty entries as many times as the number in $4
	int i;
	for (i = 0; i < atoi($4); i++) {
		// add i char to the end of $2
		char *arrName = malloc(strlen($2) + 2);
		strcpy(arrName, $2);
		char iChar[2];
		sprintf(iChar, "%d", i);
		strcat(arrName, iChar);
		addItem($2, "Var", $1, "", 0, currentScope);
	}
    showSymTable();

    // ---- SEMANTIC ACTIONS by PARSER ----
    $$ = AST_Type("Type", $1, $2);
    printf("-----------> %s", $$->LHS);
}; 



Primary: ID 
	| NUMBER
	| LEFTPARENTHESIS Expr RIGHTPARENTHESIS 
	| ID LEFTBRACKET Expr RIGHTBRACKET 
;
 

Expr: NUMBER            { $$ = $1; sprintf($$->value, "%s", $1); } 
	| ID                { $$ = $1; sprintf($$->value, "%s", $1); }
	| ID LEFTBRACKET Expr RIGHTBRACKET { $$ = $1; sprintf($$->value, "%s", $1); }
     | ID EQUAL Expr   {
        // Update the value of the variable in the symbol table
		int inSymTab = found($1, currentScope);
        if (inSymTab == -1) {
            printf("SEMANTIC ERROR: Variable '%s' is not in the symbol table\n", $1);
            semanticCheckPassed = 0; 
        } 
		else if(getVariableType($1, currentScope) == "Arr") {
			int size = getArraySize($1, currentScope);
				if (atoi($3) >= size) {
					printf("SEMANTIC ERROR: Index out of bounds for array %s\n", $1);
					semanticCheckPassed = 0;
				} else {
					char* value = getValue(inSymTab + atoi($3));
					// Create a new node for the array element
					sprintf($3->value, "%s", value);
 
					// print the Expr
					updateItem(value, $3, currentScope);
					// $$ = AST_BinaryExpression("=", $1, value);
				}
		}
		else {
			// print the Expr
			printf( "Expr: %s", $3->value);
            updateItem($1, $3->value, currentScope);
            $$ = AST_BinaryExpression("=", $1, $3->value);
        }
     }   
	 | ID LEFTBRACKET NUMBER RIGHTBRACKET EQUAL Expr {
		// Update the value of the variable in the symbol table
		int inSymTab = found($1, currentScope);
		if (inSymTab == -1) {
        printf("SEMANTIC ERROR: Array %s is not in the symbol table\n", $1);
        semanticCheckPassed = 0;
		} else {
			// Get the type of the array from the symbol table
			// char* type = getType($1, currentScope);
			if (strcmp("Arr", "Arr") != 0) {
				printf("SEMANTIC ERROR: %s is not an array\n", $1);
				semanticCheckPassed = 0;
			} else {
				// Check if the index is within bounds
				int size = getArraySize($1, currentScope);
				if (atoi($3) >= size) {
					printf("SEMANTIC ERROR: Index out of bounds for array %s\n", $1);
					semanticCheckPassed = 0;
				} else { 
					// Construct the AST for the array indexing
					// $$ = AST_ArrayIndex($1, $3);
					// updateItemByID 
					
					// turn $3 into number
					int index = atoi($3);
					updateItemByID(inSymTab + index, $6);
					// print updating id (inSymTab + index)
					printf("Updating id: %d", inSymTab + index);
				}
			}
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
		// print what is being subtracted
		printf( "Expr: %s - %s ", $1->value, $3->value);
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
		// calculate the value of the expression
		int total = atoi($1->value) / atoi($3->value);
		$$ = AST_BinaryExpression("/", $1, $3);
		// convert value to string
		char stringVal[50];
		sprintf(stringVal, "%d", total);
		// set the value of the expression
		sprintf($$->value, "%s", stringVal);
     }
     | LEFTPARENTHESIS Expr RIGHTPARENTHESIS    {$$ = $2; sprintf($$->value, "%s", $2->value); }
	 | ID LEFTBRACKET NUMBER RIGHTBRACKET {
		// check if ID is in the symbol table and if itemKind is "Arr"
		int inSymTab = found($1, currentScope);
		if (inSymTab == -1) {
			printf("SEMANTIC ERROR: Array %s is not in the symbol table\n", $1);
			semanticCheckPassed = 0;
		} else {
			// Get the type of the array from the symbol table
			if (strcmp("Arr", "Arr") != 0) {
				printf("SEMANTIC ERROR: %s is not an array\n", $1);
				semanticCheckPassed = 0;
			} else {
				// Check if the index is within bounds
				int size = getArraySize($1, currentScope);
				if (atoi($3) >= size) {
					printf("SEMANTIC ERROR: Index out of bounds for array %s\n", $1);
					semanticCheckPassed = 0;
				} else {
					// Get the value of the array element from the symbol table
					// call const char * getValue(int itemID)
					// print the inSymTab + atoi($3)
					printf("inSymTab + atoi($3): %d", inSymTab + atoi($3));
					char* value = getValue(inSymTab + atoi($3));
					// Create a new node for the array element
					$$ = AST_BinaryExpression("[]", $1, $3);
					sprintf($$->value, "%s", value);
					// "value of array is "
					printf("value of array %s is %s", $1, $$->value); 
				}
			}
		}
	 }
	 | ID LEFTBRACKET NUMBER RIGHTBRACKET EQUAL Expr {
    // Check if the array is in the symbol table
    int inSymTab = found($1, currentScope);
    if (inSymTab == -1) {
        printf("SEMANTIC ERROR: Array %s is not in the symbol table\n", $1);
        semanticCheckPassed = 0;
    } else {
        // Get the type of the array from the symbol table
        // char* type = getType($1, currentScope);
        if (strcmp("Arr", "Arr") != 0) {
            printf("SEMANTIC ERROR: %s is not an array\n", $1);
            semanticCheckPassed = 0;
        } else {
            // Check if the index is within bounds
            int size = getArraySize($1, currentScope);
            if (atoi($3) >= size) {
                printf("SEMANTIC ERROR: Index out of bounds for array %s\n", $1);
                semanticCheckPassed = 0;
            } else { 
                // Construct the AST for the array indexing
                // $$ = AST_ArrayIndex($1, $3);
				// updateItemByID
				
				// turn $3 into number
				int index = atoi($3);
				updateItemByID(inSymTab + index, $6);
				// print updating id (inSymTab + index)
				printf("Updating id: %d", inSymTab + index);
            }
        }
    }
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


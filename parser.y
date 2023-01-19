%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symbolTable.h"
#include "AST.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int words;
extern int chars;
extern int lines;

void yyerror(const char* s);
char currentScope[50] = "global";
%}

%union {
	int number;
	char character;
	char* string;
	struct AST* ast;
}

%token <string> TYPE
%token <string> ID
%token <character> SEMICOLON
%token <character> EQUAL
%token <number> NUMBER
%token WRITE

%printer { fprintf(yyoutput, "%s", $$); } ID;
%printer { fprintf(yyoutput, "%d", $$); } NUMBER;

%type <ast> Program DeclList Decl VarDecl Stmt StmtList Expr

%start Program

%%

Program: DeclList StmtList { $$ = 1; 
					 printf("\n--- Abstract Syntax Tree ---\n");
					 // printAST($$, 0);
					}
;

DeclList:	Decl DeclList	{ }
	| Decl	{ }
;


Decl:	TYPE ID SEMICOLON	{ printf("\n RECOGNIZED RULE: Variable declaration %s\n", $2);
							  symTabAccess();
							  int inSymTab = found($2, currentScope);
							  printf("Looking for %s in symtab - Found: %d\n", $2, inSymTab);

							  if(inSymTab == 0)
								  addItem($2, "Var", $1, 0, currentScope);
							  else
								  printf("ERROR: Variable %s already declared in scope %s\n", $2, currentScope);
								  showSymTable();

							  // ---- SEMANTIC ACTIONS by PARSER ----
							  $$ = AST_Type("Type", $1, $2);
								}
;

StmtList:	Stmt
	| Stmt StmtList
;

Stmt:	 ID EQUAL ID SEMICOLON 	{ printf("\n RECOGNIZED RULE: Assignment statement\n"); 
					// ---- SEMANTIC ACTIONS by PARSER ----
				}
	| ID EQUAL NUMBER SEMICOLON 	{ printf("\n RECOGNIZED RULE: Assignment statement\n"); 
					   // ---- SEMANTIC ACTIONS by PARSER ----
					}
	| WRITE ID SEMICOLON 	{ printf("\n RECOGNIZED RULE: WRITE statement\n");
				}
;
%%

int main(int argc, char**argv)
{
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
	yyparse();
}

void yyerror(const char* s) {
	// fprintf(stderr, "Parse error: %s\n", s);
	printf("%s : Parse error at line %d char %d\n", s,lines,chars);
	exit(1);
}

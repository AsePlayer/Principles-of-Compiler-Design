%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include "symbolTable.h"
// #include "AST.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int words;
extern int chars;
extern int lines;

void yyerror(const char* s);
char currentScope[50]; // global or the name of the function
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
%token <character> EQ
%token <number> NUMBER
%token WRITE

%printer { fprintf(yyoutput, "%s", $$); } ID;
%printer { fprintf(yyoutput, "%d", $$); } NUMBER;

%start Program

%%

Program: DeclList StmtList  { 
					}
;

DeclList:	Decl DeclList	{ }
	| Decl	{ }
;


Decl:	TYPE ID SEMICOLON	{ printf("\n RECOGNIZED RULE: Variable declaration %s\n", $2);
									
								}
;

StmtList:	
	| Stmt StmtList
;

Stmt:	 ID EQ ID SEMICOLON 	{ printf("\n RECOGNIZED RULE: Assignment statement\n"); 
					// ---- SEMANTIC ACTIONS by PARSER ----
				}
	| ID EQ NUMBER SEMICOLON 	{ printf("\n RECOGNIZED RULE: Assignment statement\n"); 
					   // ---- SEMANTIC ACTIONS by PARSER ----
					}
	| WRITE ID SEMICOLON 	{ printf("\n RECOGNIZED RULE: WRITE statement\n");
				}

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
	// -1 makes it accurate for now ig
	printf("%s : Parse error at line %d char %d\n", s,lines-1,chars);
	exit(1);
}

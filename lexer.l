%option noyywrap

%{
#include <stdio.h>
#include <string.h>
#include "parser.tab.h"

#define YY_DECL int yylex()
extern YYSTYPE yylval;

int words = 0;
int chars = 0;
int lines = 0;

%}

letter      [a-zA-Z]
string		'"' ((char - ["\"\\"]) | ('\\' ["\"\\nt"]))* '"'
digit       [0-9]
ID          {letter}({letter}|{digit})*
delim       [ \t\n]
NUMBER      {digit}+(\.{digit}+)?(E[+\-]?(digit)+)?
ws          {delim}+

%%
"/*"    				{
							int c;
							while((c = input()) != 0) {
								if(c == '*') {
									if((c = input()) == '/')
										break;
									else
										unput(c);
								}
							}
						}

"//".*    {
                chars += strlen(yytext);
                printf("%s : COMMENT\n", yytext);
                // Ignore the rest of the line
            }

						
"void"	{words++; chars += strlen(yytext);
		 printf("%s : TYPE\n", yytext);
		 yylval.string = strdup(yytext);
		 return VOID;
		}

"int"	{words++; chars += strlen(yytext);
		 printf("%s : TYPE\n", yytext);
		 yylval.string = strdup(yytext);
		 return INT;
		}

"string"	{words++; chars += strlen(yytext);
		 printf("%s : TYPE\n", yytext);
		 yylval.string = strdup(yytext);
		 return STRING;
		}

"bool"	{words++; chars += strlen(yytext);
		 printf("%s : TYPE\n", yytext);
		 yylval.string = strdup(yytext);
		 return BOOL;
		}

"char"	{words++; chars += strlen(yytext);
		 printf("%s : TYPE\n", yytext);
		 yylval.string = strdup(yytext);
		 return CHAR;
		}

"float"	{words++; chars += strlen(yytext);
		 printf("%s : TYPE\n", yytext);
		 yylval.string = strdup(yytext);
		 return FLOAT;
		}

"fun"	{words++; chars += strlen(yytext);
		 printf("%s : FUN\n", yytext);
		 yylval.string = strdup(yytext);
		 return FUN;
		}

"write" {words++; 
		 chars += strlen(yytext);
		 printf("%s : KEYWORD\n", yytext);
		 return WRITE;
		}

"writeln" {words++; 
		 chars += strlen(yytext);
		 printf("%s : KEYWORD\n", yytext);
		 return WRITELN;
		}

"if" 	{words++; 
		 chars += strlen(yytext);
		 printf("%s : IF\n", yytext);
		 return IF;
		}

"else" 	{words++; 
		 chars += strlen(yytext);
		 printf("%s : ELSE\n", yytext);
		 return ELSE;
		}

"while"	{words++; 
		 chars += strlen(yytext);
		 printf("%s : WHILE\n", yytext);
		 return WHILE;
		}

"putc" 	{words++; 
		 chars += strlen(yytext);
		 printf("%s : PUTC\n", yytext);
		}

"return"	{words++;
			 chars += strlen(yytext);
		 	 printf("%s : RETURN\n", yytext);
		 	 return RETURN;
			}

		
{ID}	{words++; chars += strlen(yytext);
		 printf("%s : IDENTIFIER\n",yytext);
		 yylval.string = strdup(yytext);
		 return ID;
		}
			
{NUMBER}	{words++; chars += strlen(yytext);
			  printf("%s : NUMBER\n",yytext);
			  yylval.string = strdup(yytext);
		 	  return NUMBER;
			}
			
";"		{chars++;
		 printf("%s : SEMICOLON\n", yytext);
		 yylval.string = strdup(yytext);
		 return SEMICOLON;
		}
		
"="		{chars++;
		 printf("%s : EQUAL\n", yytext);
		 yylval.string = strdup(yytext);
		 return EQUAL;
		}

"+"		{chars++;
		 printf("%s : PLUS\n", yytext);
		 	yylval.string = strdup(yytext);
		 	return PLUS;
		}

"-"		{chars++;
		 printf("%s : MINUS\n", yytext);
		 	yylval.string = strdup(yytext);
		 	return MINUS;
		}


"*"		{chars++;
		 printf("%s : MULTIPLY\n", yytext);
		 	yylval.string = strdup(yytext);
			return MULTIPLY;
		}

"/"		{chars++;
		 printf("%s : DIVIDE\n", yytext);
		 	yylval.string = strdup(yytext);
		 	return DIVIDE;
		}

"%"		{chars++;
		 printf("%s : MOD\n", yytext);
		}

"<"		{chars++;
		 printf("%s : LESS THAN\n", yytext);
			yylval.string = strdup(yytext);
		 	return LESS_THAN;
		}

"<="	{chars++; chars++;
		 printf("%s : LESS THAN OR EQUAL\n", yytext);
		 	yylval.string = strdup(yytext);
		 	return LESS_THAN_OR_EQUAL_TO;
		}

">"		{chars++;
		 printf("%s : GREATER THAN\n", yytext);
		 	yylval.string = strdup(yytext);
		 	return GREATER_THAN;
		}

">="	{chars++; chars++;
		 printf("%s : GREATER THAN OR EQUAL\n", yytext);
		 	yylval.string = strdup(yytext);
		 	return GREATER_THAN_OR_EQUAL_TO;
		}

"=="	{chars++; chars++;
		 printf("%s : EQUAL\n", yytext);
		 	yylval.string = strdup(yytext);
		 	return EQUAL_TO;
		}

"!="	{chars++; chars++;
		 printf("%s : NOT EQUAL\n", yytext);
		 	yylval.string = strdup(yytext);
		 	return NOT_EQUAL_TO;
		}

"!"		{chars++;
		 printf("%s : UNARY NOT\n", yytext);
		 	yylval.string = strdup(yytext);
		 	return UNARYNOT;
		}

"&&"	{chars++; chars++;
		 printf("%s : LOGICAL AND\n", yytext);
		 	yylval.string = strdup(yytext);
		 	return LOGICALAND;
		}

"||"	{chars++; chars++;
		 printf("%s : LOGICAL OR\n", yytext);
		 	yylval.string = strdup(yytext);
		 	return LOGICALOR;
		}


"("		{chars++;
		 printf("%s : LEFT PARENTHESIS\n", yytext);
		 	yylval.string = strdup(yytext);
		 	return LEFTPARENTHESIS;
		}

")"		{chars++;
		 printf("%s : RIGHT PARENTHESIS\n", yytext);
		 	yylval.string = strdup(yytext);
		 	return RIGHTPARENTHESIS;
		}

"["		{chars++;
		 printf("%s : LEFT BRACKET\n", yytext);
		 	yylval.string = strdup(yytext);
		 	return LEFTBRACKET;
		}

"]"		{chars++;
		 printf("%s : RIGHT BRACKET\n", yytext);
		 	yylval.string = strdup(yytext);
		 	return RIGHTBRACKET;
		}

"{"		{chars++;
		 printf("%s : LEFT CURLY BRACKET\n", yytext);
		 	yylval.string = strdup(yytext);
		 	return LEFTCURLYBRACKET;
		}

"}"		{chars++;
		 printf("%s : RIGHT CURLY BRACKET\n", yytext);
		 	yylval.string = strdup(yytext);
		 	return RIGHCURLYBRACKET;
		}

","		{chars++;
		 printf("%s : COMMA\n", yytext);
		 	yylval.string = strdup(yytext);
		 	return COMMA;
		}

[(\n\r)|(\n)|(\r)|(\r\n)]		{lines++; chars=0;}
[ \t]	{chars++;}
.		{chars++;
         printf("%s : Unrecognized symbol at line %d char %d\n", yytext,lines,chars);
		}

%%


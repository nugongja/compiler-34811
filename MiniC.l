%{
#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
extern int process_sym_table(char*);
extern void print_error(int errno);
%}

%%
"const"						return(TCONST);
"else"							return(TELSE);
"if"							return(TIF);
"int"							return(TINT);
"return"						return(TRETURN);
"void"							return(TVOID);
"while"						return(TWHILE);
"=="							return(TEQUAL);
"!="							return(TNOTEQU);
"<="							return(TLESSE);
">="							return(TGREATE);
"&&"							return(TAND);
"||"							return(TOR);
"++"							return(TINC);
"--"							return(TDEC);
"+="							return(TADDASSIGN);
"-="							return(TSUBASSIGN);
"*="							return(TMULASSIGN);
"/="							return(TDIVASSIGN);
"%="							return(TMODASSIGN);
[0-9]+[A-Za-z0-9_]+				print_error(1);
[A-Za-z_][A-Za-z0-9_]*				process_sym_table(yytext);
							return(TIDENT);
[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]*)?		return(TNUMBER);
"/*"([^*]|\*+[^*/])*\**"*"				;
"//".*							;
[ \t\n] 						;
.							return(yytext[0]);
%%

int yywrap() {
	printf("=== End of Lex ===\n");
	return 1;
}
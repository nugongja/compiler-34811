%{
#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
extern int process_sym_table(char*);
extern void print_error(int error_num, char* identifier);
extern int lineNumber;
%}

%%
"const"						return(TCONST);
"else"							return(TELSE);
"if"							return(TIF);
"int"							return(TINT);
"return"						return(TRETURN);
"void"							return(TVOID);
"while"						return(TWHILE);
"char"							return(TCHAR);
"float"							return(TFLOAT);
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
"("      						return(TLPAREN);
")"      						return(TRPAREN);
"{"      						return(TLBRACE);
"}"      						return(TRBRACE);
[0-9]+[A-Za-z0-9_]+				print_error(1, yytext);
[A-Za-z_][A-Za-z0-9_]*				{// process_sym_table(yytext);
							return(TIDENT);}
[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]*)?		return(TNUMBER);
"/*"([^*]|\*+[^*/])*\*+"/"			{
							// 주석 내 줄 개수 세기
							for (int i=0; yytext[i] != '\0'; i++) {
								if (yytext[i] == '\n') lineNumber++;
							}
							}
"//".*							;
[ \t] 							;
\n							lineNumber++;
";"							return(TSEMI);
\"([^\\\n]|(\\.))*?\"    			return(TSTRING);	
.							print_error(3, yytext);
%%

int yywrap() {
	printf("=== End of Lex ===\n");
	return 1;
}
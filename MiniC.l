%{
#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
extern int process_sym_table(char*);
extern void print_error(int error_num, char* identifier);
extern int lineNumber;
%}

%%
"const"								return(TCONST);
"else"									return(TELSE);
"if"									return(TIF);
"int"									return(TINT);
"return"								return(TRETURN);
"void"								return(TVOID);
"while"								return(TWHILE);
"char"								return(TCHAR);
"float"								return(TFLOAT);

"=="									return(TEQUAL);
"!="									return(TNOTEQU);
"<="									return(TLESSE);
">="									return(TGREATE);
"&&"									return(TAND);
"||"									return(TOR);
"++"									return(TINC);
"--"									return(TDEC);
"+="									return(TADDASSIGN);
"-="									return(TSUBASSIGN);
"*="									return(TMULASSIGN);
"/="									return(TDIVASSIGN);
"%="									return(TMODASSIGN);
"("      								return(TLPAREN);
")"      								return(TRPAREN);
"{"      								return(TLBRACE);
"}"      								return(TRBRACE);
"="									return(TASSIGN);
"*"									return(TSTAR);
"+"									return(TPLUS);
"%"									return(TMOD);
"-"									return(TMINUS);
"/"									return(TSLASH);

\n									lineNumber++;

"/*"([^*]|\*+[^*/])*\*+"/"					{
									// 주석 내 줄 개수 세기
									for (int i=0; yytext[i] != '\0'; i++) {
										if (yytext[i] == '\n') lineNumber++;
									}
									}
"//".*									;

[ \t] 									;

";"									return(TSEMI);
\"([^\\\n]|(\\.))*?\"    					return(TSTRING);	

[+-]?[0-9]+\.[0-9]+([eE][-+]?[0-9]+)?			return(TFLOATNUM);
[+-]?0([0-7]+|(x|X)[0-9A-Fa-f]+)				return(TNUMBER);
[+-]?[1-9][0-9]*|0							return(TINTNUM);
\'(\\.|[^\\'\n])\'    						return TCHARCONST;
[A-Za-z_][A-Za-z0-9_]*						return(TIDENT);

[+-]?0[xX]([0-9a-fA-F]*[^0-9a-fA-F \t\n\r\);}\]])+ 	{print_error(7, yytext); return(TERROR);}
[+-]?0[89][0-9]*							{print_error(8, yytext); return(TERROR);}
[+-]?0[0-7]*[89]+							{print_error(8, yytext); return(TERROR);}

\'([^\\']{2,}|\\[^'ntvbrfa\\"])\'				{print_error(9, yytext); return(TERROR);}

[0-9]+[A-Za-z0-9_]+						{print_error(1, yytext); return(TERROR);}

"."									return(TDOT);

.									{print_error(3, yytext); return(TERROR);}
%%

int yywrap() {
	return 1;
}
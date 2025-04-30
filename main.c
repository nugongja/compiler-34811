#include "tn.h"
#include <stdio.h>
#include <stdlib.h>

#define _CRT_NONSTDC_NO_WARNINGS

extern char* yytext;
extern yylex();
extern void init_sym_table(void);
extern void init_hash_table(void);
extern void printSymbolTable(void);
extern void printHashTable(void);

void main()
{
	enum tnumber tn;  // token number

	init_sym_table();	
	init_hash_table();
	printf("=== Start of Lex ===\n");

	while ((tn = yylex()) != TEOF) {
		switch (tn) {
		case TCONST:			printf("const"); break;
		case TELSE:      		printf("else"); break;
		case TIF:        		printf("if"); break;
		case TINT:      	 	printf("int"); break;
		case TRETURN:  			printf("return"); break;
		case TVOID:      		printf("void"); break;
		case TWHILE:   	 		printf("while"); break;
		case TEQUAL:    	 	printf("=="); break;
		case TNOTEQU:  			printf("!="); break;
		case TLESSE:     		printf("<="); break;
		case TGREATE:   		printf(">="); break;
		case TAND:      		printf("&&"); break;
		case TOR:        		printf("||"); break;
		case TINC:       		printf("++"); break;
		case TDEC:       		printf("--"); break;
		case TADDASSIGN: 		printf("+="); break;
		case TSUBASSIGN: 		printf("-="); break;
		case TMULASSIGN: 		printf("*="); break;
		case TDIVASSIGN: 		printf("/="); break;
		case TMODASSIGN: 		printf("%="); break;
		case TIDENT:     		printf("identifier (%s)\n", yytext); break;
		case TNUMBER:    		printf("number (%s)\n", yytext); break;
		default:         		printf("%s", yytext); break;
		}
		printf("\n");
	}

	printSymbolTable();
	printHashTable();

}
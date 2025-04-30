#include "tn.h"
#include <stdio.h>
#include <stdlib.h>


extern char* yytext;
extern yylex();
extern void init_sym_table(void);
extern void init_hash_table(void);
extern void printSymbolTable(void);
extern void printHashTable(void);
int lineNumber = 1;
int ST_index;

void main()
{
	enum tnumber tn;  // token number

	init_sym_table();	
	init_hash_table();
	printf("Line\tToken type\tST-index\ttoken\n");

	while ((tn = yylex()) != TEOF) {
		switch (tn) {
		case TCONST:			printf("%d\t%s\t\t\t\t%s", lineNumber, "TCONST", yytext); break;
		case TELSE:      		printf("%d\t%s\t\t\t\t%s", lineNumber, "TELSE", yytext); break;
		case TIF:        		printf("%d\t%s\t\t\t\t%s", lineNumber, "TIF", yytext); break;
		case TINT:      	 	printf("%d\t%s\t\t\t\t%s", lineNumber, "TINT", yytext); break;
		case TRETURN:  			printf("%d\t%s\t\t\t\t%s", lineNumber, "TRETURN", yytext); break;
		case TVOID:      		printf("%d\t%s\t\t\t\t%s", lineNumber, "TVOID", yytext); break;
		case TWHILE:   	 		printf("%d\t%s\t\t\t\t%s", lineNumber, "TWHILE", yytext); break;
		case TCHAR:				printf("%d\t%s\t\t\t\t%s", lineNumber, "TCHAR", yytext); break;
		case TFLOAT:			printf("%d\t%s\t\t\t\t%s", lineNumber, "TFLOAT", yytext); break;
		case TEQUAL:    	 	printf("%d\t%s\t\t\t\t%s", lineNumber, "TEQUAL", yytext); break;
		case TNOTEQU:  			printf("%d\t%s\t\t\t\t%s", lineNumber, "TNOTEQU", yytext); break;
		case TLESSE:     		printf("%d\t%s\t\t\t\t%s", lineNumber, "TLESSE", yytext); break;
		case TGREATE:   		printf("%d\t%s\t\t\t\t%s", lineNumber, "TGREATE", yytext); break;
		case TAND:      		printf("%d\t%s\t\t\t\t%s", lineNumber, "TAND", yytext); break;
		case TOR:        		printf("%d\t%s\t\t\t\t%s", lineNumber, "TOR", yytext); break;
		case TINC:       		printf("%d\t%s\t\t\t\t%s", lineNumber, "TINC", yytext); break;
		case TDEC:       		printf("%d\t%s\t\t\t\t%s", lineNumber, "TDEC", yytext); break;
		case TADDASSIGN: 		printf("%d\t%s\t\t\t\t%s", lineNumber, "TADDASSIGN", yytext); break;
		case TSUBASSIGN: 		printf("%d\t%s\t\t\t\t%s", lineNumber, "TSUBASSIGN", yytext); break;
		case TMULASSIGN: 		printf("%d\t%s\t\t\t\t%s", lineNumber, "TMULASSIGN", yytext); break;
		case TDIVASSIGN: 		printf("%d\t%s\t\t\t\t%s", lineNumber, "TDIVASSIGN", yytext); break;
		case TMODASSIGN: 		printf("%d\t%s\t\t\t\t%s", lineNumber, "TMODASSIGN", yytext); break;
		case TLPAREN:     		printf("%d\t%s\t\t\t\t%s", lineNumber, "TLPAREN", yytext); break;
		case TRPAREN:     		printf("%d\t%s\t\t\t\t%s", lineNumber, "TRPAREN", yytext); break;
		case TLBRACE:     		printf("%d\t%s\t\t\t\t%s", lineNumber, "TLBRACE", yytext); break;
		case TRBRACE:     		printf("%d\t%s\t\t\t\t%s", lineNumber, "TRBRACE", yytext); break;
		case TASSIGN:			printf("%d\t%s\t\t\t\t%s", lineNumber, "TASSIGN", yytext); break;
		case TIDENT:			{ 
								ST_index = process_sym_table(yytext);
								if (ST_index != -1) {printf("%d\t%s\t\t%d\t\t%s", lineNumber, "TIDENT", ST_index, yytext);}
								}
								break;
		case TNUMBER:    		printf("%d\t%s\t\t\t\t%s", lineNumber, "TNUMBER", yytext); break;
		case TSEMI:				printf("%d\t%s\t\t\t\t%s", lineNumber, "TSEMI", yytext); break;
		case TSTRING:			printf("%d\t%s\t\t\t\t%s", lineNumber, "TSTRING", yytext); break;
		case TFLOATNUM:			printf("%d\t%s\t\t\t%s", lineNumber, "TFLOATNUM", yytext); break;
		case TMUL:				printf("%d\t%s\t\t\t\t%s", lineNumber, "TMUL", yytext); break;
		case TINTNUM:			printf("%d\t%s\t\t\t\t%s", lineNumber, "TINTNUM", yytext); break;
		default:         		printf("%d\t%s\t\t\t\t%s", lineNumber, "?", yytext); break;
		}
		printf("\n");
	}

	printSymbolTable();
	printHashTable();

}
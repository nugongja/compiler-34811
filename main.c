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
		case TELSE:      		printf("%-7d %-15s %-15s %s", lineNumber, "TELSE", "", yytext); break;
		case TIF:        		printf("%-7d %-15s %-15s %s", lineNumber, "TIF", "", yytext); break;
		case TINT:      	 	printf("%-7d %-15s %-15s %s", lineNumber, "TINT", "", yytext); break;
		case TRETURN:  			printf("%-7d %-15s %-15s %s", lineNumber, "TRETURN", "", yytext); break;
		case TVOID:      		printf("%-7d %-15s %-15s %s", lineNumber, "TVOID", "", yytext); break;
		case TWHILE:   	 		printf("%-7d %-15s %-15s %s", lineNumber, "TWHILE", "", yytext); break;
		case TCHAR:				printf("%-7d %-15s %-15s %s", lineNumber, "TCHAR", "", yytext); break;
		case TFLOAT:			printf("%-7d %-15s %-15s %s", lineNumber, "TFLOAT", "", yytext); break;
		case TEQUAL:    	 	printf("%-7d %-15s %-15s %s", lineNumber, "TEQUAL", "", yytext); break;
		case TNOTEQU:  			printf("%-7d %-15s %-15s %s", lineNumber, "TNOTEQU", "", yytext); break;
		case TCONST:			printf("%-7d %-15s %-15s %s", lineNumber, "TCONST", "", yytext); break;
		case TLESSE:     		printf("%-7d %-15s %-15s %s", lineNumber, "TLESSE", "", yytext); break;
		case TGREATE:   		printf("%-7d %-15s %-15s %s", lineNumber, "TGREATE", "", yytext); break;
		case TAND:      		printf("%-7d %-15s %-15s %s", lineNumber, "TAND", "", yytext); break;
		case TOR:        		printf("%-7d %-15s %-15s %s", lineNumber, "TOR", "", yytext); break;
		case TINC:       		printf("%-7d %-15s %-15s %s", lineNumber, "TINC", "", yytext); break;
		case TDEC:       		printf("%-7d %-15s %-15s %s", lineNumber, "TDEC", "", yytext); break;
		case TADDASSIGN: 		printf("%-7d %-15s %-15s %s", lineNumber, "TADDASSIGN", "", yytext); break;
		case TSUBASSIGN: 		printf("%-7d %-15s %-15s %s", lineNumber, "TSUBASSIGN", "", yytext); break;
		case TMULASSIGN: 		printf("%-7d %-15s %-15s %s", lineNumber, "TMULASSIGN", "", yytext); break;
		case TDIVASSIGN: 		printf("%-7d %-15s %-15s %s", lineNumber, "TDIVASSIGN", "", yytext); break;
		case TMODASSIGN: 		printf("%-7d %-15s %-15s %s", lineNumber, "TMODASSIGN", "", yytext); break;
		case TLPAREN:     		printf("%-7d %-15s %-15s %s", lineNumber, "TLPAREN", "", yytext); break;
		case TRPAREN:     		printf("%-7d %-15s %-15s %s", lineNumber, "TRPAREN", "", yytext); break;
		case TLBRACE:     		printf("%-7d %-15s %-15s %s", lineNumber, "TLBRACE", "", yytext); break;
		case TRBRACE:     		printf("%-7d %-15s %-15s %s", lineNumber, "TRBRACE", "", yytext); break;
		case TASSIGN:			printf("%-7d %-15s %-15s %s", lineNumber, "TASSIGN", "", yytext); break;
		case TIDENT:			{ 
								ST_index = process_sym_table(yytext);
								if (ST_index != -1) {printf("%-7d %-15s %-15d %s", lineNumber, "TIDENT", ST_index, yytext);}
								}
								break;
		case TNUMBER:    		printf("%-7d %-15s %-15s %s", lineNumber, "TNUMBER", "", yytext); break;
		case TSEMI:				printf("%-7d %-15s %-15s %s", lineNumber, "TSEMI", "", yytext); break;
		case TSTRING:			printf("%-7d %-15s %-15s %s", lineNumber, "TSTRING", "", yytext); break;
		case TFLOATNUM:			printf("%-7d %-15s %-15s %s", lineNumber, "TFLOATNUM", "", yytext); break;
		case TSTAR:				printf("%-7d %-15s %-15s %s", lineNumber, "TSTAR", "", yytext); break;
		case TINTNUM:			printf("%-7d %-15s %-15s %s", lineNumber, "TINTNUM", "", yytext); break;
		case TPLUS:				printf("%-7d %-15s %-15s %s", lineNumber, "TPLUS", "", yytext); break;
		case TMOD:				printf("%-7d %-15s %-15s %s", lineNumber, "TMOD", "", yytext); break;
		case TMINUS:			printf("%-7d %-15s %-15s %s", lineNumber, "TMINUS", "", yytext); break;
		case TSLASH:			printf("%-7d %-15s %-15s %s", lineNumber, "TSLASH", "", yytext); break;
		case TDOT:				printf("%-7d %-15s %-15s %s", lineNumber, "TDOT", "", yytext); break;
		default:         		printf("%-7d %-15s %-15s %s", lineNumber, "?", "", yytext); break;
		}
		printf("\n");
	}

	printSymbolTable();
	printHashTable();

}
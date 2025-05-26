#include "parser_tab.h"
#include "SymbolInfo.h"
#include <stdio.h>
#include <stdlib.h>


extern char* yytext;
extern yyparse();
extern void init_sym_table(void);
extern void init_hash_table(void);
extern void printSymbolTable(void);
extern void printHashTable(void);
extern int process_sym_table(char* identifier);
int line_num = 1;
//int ST_index;


void main()
{
	enum tnumber tn;  // token number

	init_sym_table();	
	init_hash_table();

	yyparse();  // parse the input file

	printSymbolTable();
	printHashTable();

}
#include <stdio.h>
#include <stdlib.h>

yyerror(char* s) 
{
	printf("%s\n", s);
}

void print_error(int error_num, char* identifier)
{
	switch (error_num)
	{
	case 1:
		/* start with digit */
		printf("Error - %s (%s)\n", "Start with digit", identifier);
		break;
	case 2:
		/* long identifier*/
		printf("Error - %s (%s)\n", "Long identifier", identifier);
		break;
	case 3:
		/* Invalid symbol */
		printf("Error - %s (%s)\n", "Invalid Symbol", identifier);
		break;
	case 4:
		/* symbol table overflow */
		printf("Error - %s (%s)\n", "Symbol table overflow. Cannot store", identifier);
		break;
	case 5:
		/* string pool overflow*/
		printf("Error - %s (%s)\n", "String pool overflow. Cannot store", identifier);
		break;
	case 6:
		/* hash table overflow */
		printf("Error - %s (%s)\n", "Hash table overflow. Cannot store", identifier);
		break;
	case 7:
		/* haxadecimal error */
		printf("Error - %s (%s)\n", "Invalid Hex", identifier);
		break;
	case 8:
		/* octal error */
		printf("Error - %s (%s)\n", "Invalid Octal", identifier);
		break;
	case 9:
		/* invalid charconst error */
		printf("Error - %s (%s)\n", "Invalid character", identifier);
		break;
	default:
		/* unknown error */
		printf("Error - %s (%s)\n", "Unknown", identifier);
		break;
	}
}
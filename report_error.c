#include <stdio.h>
#include <stdlib.h>

void print_error(int error_num, char* identifier)
{
	switch (error_num)
	{
	case 1:
		/* start with digit */
		printf("Error - Start with digit (%s)", identifier);
		break;
	case 2:
		/* long identifier*/
		printf("Error - Long identifier (%s)", identifier);
		break;
	case 3:
		/* illegal identifier */
		printf("Error - Invalid character (%s)", identifier);
		break;
	case 4:
		/* symbol table overflow */
		printf("Error - Symbol table overflow. Cannot store (%s)", identifier);
		break;
	case 5:
		/* string pool overflow*/
		printf("Error - String pool overflow. Cannot store (%s)", identifier);
		break;
	case 6:
		/* hash table overflow */
		printf("Error - Hash table overflow. Cannot store (%s)", identifier);
		break;
	case 7:
		printf("Error - Invalid Hex (%s)", identifier);
		break;
	case 8:
		printf("Error - Invalid Octal (%s)", identifier);
		break;
	case 9:
		printf("Error - Invalid character (%s)", identifier);
		break;
	default:
		printf("Error - Unknown (%s)", identifier);
		break;
	}
}
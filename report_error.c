#include <stdio.h>
#include <stdlib.h>

void print_error(int error_num)
{
	switch (error_num)
	{
	case 1:
		/* start with digit */
		printf("Error - Start with digit\n");
		break;
	case 2:
		/* */
		printf("Error - long identifier\n");
		break;
	default:
		printf("Error - Unknown\n");
		break;
	}
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{   
	short a, b;
	while (1)
	{
		scanf("%hd%hd", &a, &b);
		
		if (a == 0 && b == 0)
			break;
		
		if (b % a == 0)
			printf("factor\n");
		else if (a % b == 0)
			printf("multiple\n");
		else
			printf("neither\n");
	}
}
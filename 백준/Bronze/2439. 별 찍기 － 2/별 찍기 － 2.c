#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int count = 0;
	scanf("%d", &count);

	for (int i = 1; i <= count; i++)
	{
		for(int j = count; j > i; j--)
			printf(" ");
		for (int k = 1; k <= i; k++)
			printf("*");
		printf("\n");
	}
}
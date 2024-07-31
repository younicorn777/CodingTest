#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	short count;
	scanf("%hd", &count);

	for (short i = 0; i < count; i++)
	{
		for (short j = 0; j <= i; j++)
			printf("*");
		puts("");
	}
}
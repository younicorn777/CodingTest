#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int count;
	scanf("%d", &count);

	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j <= i; j++)
			printf("*");
		puts("");
	}
}
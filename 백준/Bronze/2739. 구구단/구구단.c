#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	short n = 0;
	scanf("%hd", &n);

	for (short i = 1; i < 10; i++)
		printf("%hd * %hd = %hd\n", n, i, n * i);
	
	return 0;
}
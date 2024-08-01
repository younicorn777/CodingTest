#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	short a = 0, b = 0;

	do
	{
		scanf("%hd%hd", &a, &b);
		
		if ((a == 0) && (b == 0))
			break;

	} while (printf("%hd\n", a + b));
}
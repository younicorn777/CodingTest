#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int t;
	scanf("%d", &t);

	for (int i = 0, c, remain; i < t; i++) 
	{
		scanf("%d", &c);
		printf("%d ", c / 25);
		remain = c % 25;
		printf("%d ", remain / 10);
		remain %= 10;
		printf("%d ", remain / 5);
		remain %= 5;
		printf("%d\n", remain);
	}
}
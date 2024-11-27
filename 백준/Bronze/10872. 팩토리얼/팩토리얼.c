#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Factorial(int a)
{
	if (a == 0)
		return 1;
	else
		return a * Factorial(a - 1);
}

int main()
{
	int data;
	scanf("%d", &data);
	printf("%d", Factorial(data));
}
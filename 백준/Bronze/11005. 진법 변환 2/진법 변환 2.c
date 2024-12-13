#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void What(int temp)
{
	if (temp >= 10)
		printf("%c", temp + 55);
	else
		printf("%d", temp);
}

void Convert(int target, int base)
{
	int remain;

	if (target < base)
		What(target);
	else
	{
		remain = target % base;
		target /= base;
		
		Convert(target, base);
		What(remain);
	}
}

int main()
{
	int n, b;
	scanf("%d%d", &n, &b);
	Convert(n, b);
}
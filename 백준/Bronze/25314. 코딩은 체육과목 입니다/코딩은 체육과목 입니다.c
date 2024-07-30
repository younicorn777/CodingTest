#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	short n; // n바이트 정수
	scanf("%hd", &n);

	for (short i = 0; i < (n / 4); i++)
		printf("long ");
	printf("int");
}
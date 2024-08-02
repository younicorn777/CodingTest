#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	short num[100] = { 0 };
	short n = 0, v = 0, count = 0; // 정수의 개수, 찾고자 하는 정수 및 그 개수
	scanf("%hd", &n);

	for (int i = 0; i < n; i++)
		scanf("%hd", &num[i]);

	scanf("%hd", &v);

	for (int i = 0; i < n; i++)
		if (v == num[i])
			++count;

	printf("%hd", count);
}
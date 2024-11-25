#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

double ConcatToNum(char str1[], char str2[])
{
	int n = 0;
	int size1 = strlen(str1);
	int size2 = strlen(str2);
	double result = 0.0;

	for (int i = size2 - 1; i >= 0; i--)
		result += ((str2[i] - 48.0) * pow(10.0, n++));

	for (int i = size1 - 1; i >= 0; i--)
		result += ((str1[i] - 48.0) * pow(10.0, n++));

	return result;
}

int main(void)
{
	char str1[8], str2[8], str3[8], str4[8];

	scanf("%s", str1);
	scanf("%s", str2);
	scanf("%s", str3);
	scanf("%s", str4);

	printf("%.0lf", ConcatToNum(str1, str2) + ConcatToNum(str3, str4));
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	char str[33];
	double b, sum = 0.0;

	scanf("%s%lf", str, &b);

	int size = strlen(str) - 1;

	for (int i = size, temp; i >= 0; i--)
	{
		if (str[size - i] >= 65)
			temp = str[size - i] - 55;
		else
			temp = str[size - i] - 48;

		sum += (temp * pow(b, i));
	}

	printf("%.0lf", sum);
}
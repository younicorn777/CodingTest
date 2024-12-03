#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, count2 = 0, count5 = 0;
	scanf("%d", &a);

	for (int i = a, temp; i >= 2; i--)
	{
		temp = i;

		while (temp % 2 == 0)
		{
			count2++;
			temp /= 2;
		}

		while (temp % 5 == 0)
		{
			count5++;
			temp /= 5;
		}
	}

	if (count2 > count5)
		printf("%d", count5);
	else
		printf("%d", count2);
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int t, divided, divisor, remain;
	scanf("%d", &t);

	for (int i = 0, a, b; i < t; i++)
	{
		scanf("%d%d", &a, &b);
		divided = a;
		divisor = b;
		
		if (b > a)
		{
			divided = b;
			divisor = a;
		}

		remain = divided % divisor;

		if (remain == 0)
			printf("%d\n", divided);
		else 
		{
			while (remain != 0)
			{
				divided = divisor;
				divisor = remain;
				remain = divided % divisor;
			}

			printf("%d\n",  (a * b) / divisor);
		}
	}
}
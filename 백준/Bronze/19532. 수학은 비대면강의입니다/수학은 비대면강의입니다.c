#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void findtrue(int a, int b, int c, int d, int e, int f)
{
	for (int x = -999; x <= 999; x++)
	{
		for (int y = -999; y <= 999; y++)
		{
			if ((a * x + b * y == c) && (d * x + e * y == f))
			{
				printf("%d %d", x, y);
				return;
			}
		}
	}
}

int main(void)
{
	int a, b, c, d, e, f;
	scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f); 
	findtrue(a,b,c,d,e,f);
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int gcd(int a, int b) 
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main() 
{
	int a, b, c, d, numer, denomi, divide;
	scanf("%d%d", &a, &b);
	scanf("%d%d", &c, &d);

	numer = (a * d) + (b * c);
	denomi = (b * d);
	divide = gcd(numer, denomi);

	printf("%d %d", numer / divide, denomi / divide);
}
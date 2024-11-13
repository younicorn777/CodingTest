#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

long long int gcd(long long int a, long long int b) 
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main() 
{
	long long int a, b, c, d, numer, denomi, result;
	scanf("%lld%lld", &a, &b);
	scanf("%lld%lld", &c, &d);

	denomi = (b * d) / gcd(b, d);
	numer = (a * denomi / b) + (c * denomi / d);
	
	result = gcd(numer, denomi);

	if (result == 1)
		printf("%lld %lld", numer, denomi);
	else
		printf("%lld %lld", numer / result, denomi / result);
}
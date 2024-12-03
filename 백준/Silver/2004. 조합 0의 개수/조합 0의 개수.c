#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Count2And5(long long a, long long *pcount2, long long *pcount5)
{
	long long i;
	for (i = 2; i <= a; i *= 2)
		*pcount2 += (a / i);

	for (i = 5; i <= a; i *= 5)
		*pcount5 += (a / i);
}

int main()
{
	long long n, m;
	long long ncount2 = 0, ncount5 = 0; // 분자
	long long mcount2 = 0, mcount5 = 0; // 분모
	long long result2, result5;
	
	scanf("%lld%lld", &n, &m);

	Count2And5(n, &ncount2, &ncount5);
	Count2And5(m, &mcount2, &mcount5);
	Count2And5(n - m, &mcount2, &mcount5);

	result2 = ncount2 - mcount2;
	result5 = ncount5 - mcount5;
	
	if (result2 > result5)
		printf("%lld", result5);
	else
		printf("%lld", result2);
}
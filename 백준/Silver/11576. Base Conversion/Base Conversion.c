#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void Convert(int target, int base)
{
	int remain;

	if (target < base)
		printf("%d ", target);
	else
	{
		remain = target % base;
		target /= base;

		Convert(target, base);
		printf("%d ", remain);
	}
}

int main()
{
	int a, b, m;
	double sum = 0.0;
	scanf("%d%d%d", &a, &b, &m);

	for (int i = m - 1, data; i >= 0; i--)
	{
		scanf("%d", &data);
		sum += (data * pow(a, i));
	}
	Convert((int)sum, b);
}
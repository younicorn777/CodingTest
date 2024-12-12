#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void findme(long long target)
{
	int remain;

	if (target == 1 || target == 0)
	{
		printf("%lld", target);
		return;
	}
	else
	{
		remain = target % -2;
		target /= -2;

		if (remain == -1)
		{
			target += 1;
			remain = 1;
		}

		findme(target);
		printf("%d", remain);
		return;
	}
}

int main() 
{
	long long a;
	scanf("%lld", &a);
	findme(a);
}
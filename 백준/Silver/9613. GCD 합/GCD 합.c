#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main()
{
	int t;
	int arr[100];
	scanf("%d", &t);

	for (int i = 0, n, data1, data2; i < t; i++)
	{
		long long result = 0;
		scanf("%d", &n);
		
		for (int j = 0; j < n; j++)
			scanf("%d", arr + j);

		for (int j = 0; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				data1 = arr[j];
				data2 = arr[k];
				
				if(data1 != 0 && data2 != 0)
					result += gcd(data1, data2);
			}
		}
		printf("%lld\n", result);
	}
}
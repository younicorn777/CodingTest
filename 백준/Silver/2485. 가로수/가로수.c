#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[100000];

int gcd(int a, int b) 
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main() 
{
	int n, num = 1, idx = 1, result, count = 0;
	scanf("%d", &n);

	for (int i = 0, temp; i < n; i++)
	{
		scanf("%d", &arr[i]);

		if (i == 0)
			temp = arr[i];
	
		arr[i] -= temp;
	}

	result = gcd(arr[1], arr[2]);

	for (int i = 3; i < n; i++)
	{
		if (result == 1)
			break;

		result = gcd(result, arr[i]);
	}

	while (idx < n)
	{
		if (arr[idx] == result * (num++))
			idx++;
		else
			count++;
	}

	printf("%d", count);
}
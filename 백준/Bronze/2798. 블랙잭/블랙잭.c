#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, m; 
	int sum = 0, max = 0; // m에 최대한 가까운 합
	
	scanf("%d%d", &n, &m);
	int* pa = (int*)malloc(sizeof(int) * n);  

	for (int i = 0; i < n; i++)
		scanf("%d", &pa[i]);

	for(int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				sum = pa[i] + pa[j] + pa[k];
				if (m >= sum && sum > max)
					max = sum;
			}
		}
	}
	printf("%d", max);
}
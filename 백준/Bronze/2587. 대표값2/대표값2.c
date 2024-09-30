#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int sum = 0;
	int* pa = (int*)malloc(sizeof(int) * 5);
	
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", pa + i);
		sum += pa[i];
	}

	for(int i = 0; i < 4; i++)
	{
		for (int j = 0, temp; j < (4 - i); j++)
		{
			if (pa[j] > pa[j + 1])
			{
				temp = pa[j];
				pa[j] = pa[j + 1];
				pa[j + 1] = temp;
			}
		}
	}

	printf("%d\n%d", sum / 5, pa[2]);
}
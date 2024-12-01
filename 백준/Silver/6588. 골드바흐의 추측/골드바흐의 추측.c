#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[1000001] = { 0 };

void SieveOfEratos()
{
	for (int i = 2; i <= 1000000; i++)
		arr[i] = i;

	for (int i = 2; i <= 1000000; i++)
	{
		if (arr[i] != 0)
		{
			for (int j = 2; i * j <= 1000000; j++)
				arr[i * j] = 0;
		}
	}

	arr[2] = 0;
}

int main()
{
	int data, op1, op2, i;
	SieveOfEratos();

	while (1)
	{
		scanf("%d", &data);
		
		if (data == 0)
			break;

		for (i = 3; i <= data; i += 2)
		{
			op1 = arr[i];
			op2 = arr[data - op1];

			if (op1 != 0 && op2 != 0)
			{
				printf("%d = %d + %d\n", op1 + op2, op1, op2);
				break;
			}
		}

		if(op2 == 0)
			printf("Goldbach's conjecture is wrong.");
	}
}
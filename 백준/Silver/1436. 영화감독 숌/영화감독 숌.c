#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n, count = 0;
	int arr[13];
	scanf("%d", &n); 

	int i = 666;
	while (1)
	{
		int k = 0;

		for (int j = i; j != 0; j /= 10) // 거꾸로 저장된다. 그러나 검사하는데 상관없음
			arr[k++] = (j % 10);		
	
		for (int j = 0; j <= (k - 3); j++)
		{
			if ((arr[j] == 6 && arr[j + 1] == 6) && (arr[j] == 6 && arr[j + 2] == 6))
			{
				count++;
				break;
			}
		}
		
		if (n == count)
			break;
		i++;
	}
	printf("%d", i);
}
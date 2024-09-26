#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void findmin(char arr[][51], int a, int b, char fchar, int* pcount)
{ 
	*pcount = 0;
	char evenchar, oddchar; // 짝수번째 문자, 홀수번째 문자
	if ((a + b) % 2 == 0)
	{
		evenchar = fchar;
		oddchar = (evenchar == 'B') ? 'W' : 'B';
	}
	else
	{
		oddchar = fchar;
		evenchar = (oddchar == 'B') ? 'W' : 'B';
	}

	for (int i = a; i < (a + 8); i++)
	{
		for (int j = b; j < (b + 8); j++)
		{
			if (((i + j) % 2 == 0) && arr[i][j] != evenchar)
				(*pcount)++;
			else if(((i + j) % 2 != 0) && arr[i][j] != oddchar)
				(*pcount)++;
		}
	}
}

int main(void)
{
	int n, m, count = 0, min = 9999;
	char arr[51][51];
	char fchar;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", arr[i]);

	for (int i = 0; i <= (n - 8); i++)
	{
		for (int j = 0; j <= (m - 8); j++)
		{
			fchar = arr[i][j];
			findmin(arr, i, j, fchar, &count); 
			min = (min > count) ? count : min;

			fchar = (fchar == 'B') ? 'W' : 'B';
			findmin(arr, i, j, fchar, &count); // 두번 돌린다. (why? 첫번째 문자를 바꿨을 때 최소일 수 있으므로)
			min = (min > count) ? count : min;
		}
	}
	printf("%d", min);
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char target[501];
char str[10000][501];
char SortArr[10000][501];

void MergeTwoArea(char arr[][501], int left, int mid, int right)
{
	int fIdx = left; 
	int rIdx = mid + 1;
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right)
	{
		if (strcmp(arr[fIdx], arr[rIdx]) <= 0)
			strcpy(SortArr[sIdx], arr[fIdx++]);
		else
			strcpy(SortArr[sIdx], arr[rIdx++]);

		sIdx++;
	}

	if (fIdx > mid)
	{
		for (int i = rIdx; i <= right; i++)
			strcpy(SortArr[sIdx++], arr[i]);
	}
	else
	{
		for (int i = fIdx; i <= mid; i++)
			strcpy(SortArr[sIdx++], arr[i]);
	}

	for (int i = left; i <= right; i++)
		strcpy(arr[i], SortArr[i]);
}

void MergeSort(char arr[][501], int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		MergeTwoArea(arr, left, mid, right);
	}
}

int BinarySearch(char str[][501], int left, int right, char target[])
{
	if (left > right)
		return 0;
	
	int	mid = (left + right) / 2;
	int result = strcmp(str[mid], target);

	if (!result)
		return 1;
	else if (result > 0)
		return BinarySearch(str, left, mid - 1, target);
	else
		return BinarySearch(str, mid + 1, right, target);
}

int main()
{
	int n, m, count = 0;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%s", str[i]);

	MergeSort(str, 0, n - 1);

	for (int i = 0; i < m; i++)
	{
		scanf("%s", target);
		if (BinarySearch(str, 0, n - 1, target))
			count++;
	}

	printf("%d", count);
}
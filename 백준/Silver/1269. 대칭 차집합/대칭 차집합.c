#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int fidx = left;
	int ridx = mid + 1;
	int* SortArr = (int*)malloc(sizeof(int) * (right + 1));
	int sidx = left;

	while (fidx <= mid && ridx <= right)
	{
		if (arr[fidx] <= arr[ridx])
			SortArr[sidx++] = arr[fidx++];
		else
			SortArr[sidx++] = arr[ridx++];
	}

	if (fidx > mid)
	{
		for (int i = ridx; i <= right; i++)
			SortArr[sidx++] = arr[i];
	}
	else
	{
		for (int i = fidx; i <= mid; i++)
			SortArr[sidx++] = arr[i];
	}

	for (int i = left; i <= right; i++)
		arr[i] = SortArr[i];

	free(SortArr);
}

void MergeSort(int arr[], int left, int right)
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

int arr[400000];

int main()
{
	int a, b, i, common = 0;

	scanf("%d%d", &a, &b);

	for (i = 0; i < (a + b); i++)
		scanf("%d", &arr[i]);

	MergeSort(arr, 0, (a + b - 1));

	for (i = 1; i < (a + b); i++)
	{
		if (arr[i - 1] == arr[i])
			common++;
	}

	printf("%d", a + b - (2 * common));
}
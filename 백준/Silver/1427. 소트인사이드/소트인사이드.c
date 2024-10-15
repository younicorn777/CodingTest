#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void MergeTwoArr(char arr[], int left, int mid, int right)
{
	int fidx = left;
	int ridx = mid + 1;
	char* SortArr = (char*)malloc(sizeof(char) * (right + 1));
	int sidx = left;

	while (fidx <= mid && ridx <= right)
	{
		if (arr[fidx] > arr[ridx])
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

void MergeSort(char arr[], int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		MergeTwoArr(arr, left, mid, right);
	}
}

int main(void)
{
	char arr[11];
	int n, size = 0; 
	scanf("%d", &n);

	for (int i = n; i > 0; i /= 10)
		arr[size++] = i % 10 - '0';

	MergeSort(arr, 0, size - 1);

	for (int i = 0; i < size; i++)
		printf("%d", arr[i] + '0');
}
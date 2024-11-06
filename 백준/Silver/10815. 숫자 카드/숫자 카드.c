#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid + 1;

	int* sortArr = (int*)malloc(sizeof(int) * (right + 1));
	int sIdx = left;
	
	while (fIdx <= mid && rIdx <= right)
	{
		if (arr[fIdx] > arr[rIdx])
			sortArr[sIdx] = arr[rIdx++];
		else
			sortArr[sIdx] = arr[fIdx++];

		sIdx++;
	}

	if (fIdx > mid)
	{
		for(int i = rIdx; i <= right; i++)
			sortArr[sIdx++] = arr[i];
	}
	else
	{
		for(int i = fIdx; i <= mid; i++)
			sortArr[sIdx++] = arr[i];
	}

	for (int i = left; i <= right; i++)
		arr[i] = sortArr[i];
	
	free(sortArr);
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

int BinarySearch(int arr[], int first, int last, int target)
{
	if (first > last)
		return 0;

	int mid = (first + last) / 2;

	if (arr[mid] == target)
		return 1;
	else if (arr[mid] > target)
		return BinarySearch(arr, first, mid - 1, target);
	else
		return BinarySearch(arr, mid + 1, last, target);

}

int main(void)
{
	int n, m;
	scanf("%d", &n);
	int* parr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		scanf("%d", parr + i);

	MergeSort(parr, 0, n - 1);

	scanf("%d", &m);
	int* presult = (int*)malloc(sizeof(int) * m);
	
	for (int i = 0; i < m; i++)
	{
		scanf("%d", presult + i);
		presult[i] = BinarySearch(parr, 0, n - 1, presult[i]);
	}

	for (int i = 0; i < m; i++)
		printf("%d ", presult[i]);

	free(parr);
	free(presult);
}
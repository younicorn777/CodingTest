#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _position
{
	int x;
	int y;
}Pos;

void MergeTwoArea(Pos arr[], int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid + 1;

	Pos* sortArr = (Pos*)malloc(sizeof(Pos) * (right + 1));
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right)
	{
		if (arr[fIdx].x < arr[rIdx].x)
			sortArr[sIdx] = arr[fIdx++];
		
		else if (arr[fIdx].x == arr[rIdx].x)
		{
			if (arr[fIdx].y < arr[rIdx].y)
				sortArr[sIdx] = arr[fIdx++];
			else
				sortArr[sIdx] = arr[rIdx++];
		}
	
		else
			sortArr[sIdx] = arr[rIdx++];

		sIdx++;
	}

	if (fIdx > mid)
	{
		for (int i = rIdx; i <= right; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}
	else
	{
		for (int i = fIdx; i <= mid; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}

	for (int i = left; i <= right; i++)
		arr[i] = sortArr[i];

	free(sortArr);
}

void MergeSort(Pos arr[], int left, int right)
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

int main(void)
{
	int n;
	scanf("%d", &n);
	Pos* parr = (Pos*)malloc(sizeof(Pos) * n);

	for (int i = 0; i < n; i++)
		scanf("%d%d", &(parr[i].x), &(parr[i].y));

	MergeSort(parr, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%d %d\n", parr[i].x, parr[i].y);
	
	free(parr);
}
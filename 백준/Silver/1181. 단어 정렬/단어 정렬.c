#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _StrInfo
{
	int size; 
	char str[51];
}Str;

void MergeTwoArea(Str *arr, int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid + 1;

	Str* sortArr = (Str*)malloc(sizeof(Str) * (right + 1));
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right)
	{
		if (arr[fIdx].size < arr[rIdx].size)
			sortArr[sIdx] = arr[fIdx++];
		
		else if (arr[fIdx].size == arr[rIdx].size)
		{
			if(strcmp(arr[fIdx].str, arr[rIdx].str) <= 0)
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

void MergeSort(Str *arr, int left, int right)
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
	
	Str* parr = (Str*)malloc(sizeof(Str) * n);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%s", parr[i].str);
		parr[i].size = strlen(parr[i].str);
	}
	
	MergeSort(parr, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		if ((i < (n - 1)) && strcmp(parr[i].str, parr[i + 1].str) == 0)
			continue;
		printf("%s\n", parr[i].str);
	}
	free(parr);
}
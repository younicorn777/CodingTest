#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MergeTwoArea(char **parr, int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid + 1;
	int i;

	char** SortArr = (char**)malloc(sizeof(char*) * (right + 1));
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right)
	{
		if (strlen(parr[fIdx]) > strlen(parr[rIdx]))
			SortArr[sIdx] = parr[rIdx++];
		
		else if (strlen(parr[fIdx]) == strlen(parr[rIdx]))
		{
			if(strcmp(parr[fIdx], parr[rIdx]) >= 0)
				SortArr[sIdx] = parr[rIdx++];
			else
				SortArr[sIdx] = parr[fIdx++];
		}
		
		else
			SortArr[sIdx] = parr[fIdx++];

		sIdx++;
	}

	if (fIdx > mid)
	{
		for (i = rIdx; i <= right; i++, sIdx++)
			SortArr[sIdx] = parr[i];
	}
	else
	{
		for (i = fIdx; i <= mid; i++, sIdx++)
			SortArr[sIdx] = parr[i];
	}

	for (i = left; i <= right; i++)
		parr[i] = SortArr[i];

	free(SortArr);
}

void MergeSort(char **parr, int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		MergeSort(parr, left, mid);
		MergeSort(parr, mid + 1, right);
		MergeTwoArea(parr, left, mid, right);
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	char** parr = (char**)malloc(sizeof(char*) * n);
	
	for (int i = 0; i < n; i++)
		parr[i] = (char*)malloc(sizeof(char) * 51);

	for (int i = 0; i < n; i++)
		scanf("%s", parr[i]); 

	MergeSort(parr, 0, n - 1);
	
	for (int i = 0; i < n; i++)
    {
		if ((i < n - 1) && strcmp(parr[i], parr[i + 1]) == 0)
		{
			free(parr[i]);
			continue;
		}
		printf("%s\n", parr[i]);
		free(parr[i]);
    }
	free(parr);
}
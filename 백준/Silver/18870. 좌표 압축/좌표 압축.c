#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _posinfo
{
	int num;   //들어온 값
	int order; // 들어온 순서
	int idx;   // 결과값
}Pos;

void MergeTwoArea(Pos *arr, int left, int mid, int right, int flag)
{
	int fidx = left;
	int ridx = mid + 1;

	Pos* sortArr = (Pos*)malloc(sizeof(Pos) * (right + 1));
	int sidx = left;

	if (flag == 0)
	{
		while (fidx <= mid && ridx <= right)
		{
			if (arr[fidx].num <= arr[ridx].num)
				sortArr[sidx] = arr[fidx++];
			else
				sortArr[sidx] = arr[ridx++];

			sidx++;
		}
	}
	else
	{
		while (fidx <= mid && ridx <= right)
		{
			if (arr[fidx].order <= arr[ridx].order)
				sortArr[sidx] = arr[fidx++];
			else
				sortArr[sidx] = arr[ridx++];

			sidx++;
		}
	}

	if (fidx > mid)
	{
		for (int i = ridx; i <= right; i++)
			sortArr[sidx++] = arr[i];
	}
	else
	{
		for (int i = fidx; i <= mid; i++)
			sortArr[sidx++] = arr[i];
	}

	for (int i = left; i <= right; i++)
		arr[i] = sortArr[i];

	free(sortArr);
}


void MergeSort(Pos* arr, int left, int right, int flag)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		MergeSort(arr, left, mid, flag);
		MergeSort(arr, mid + 1, right, flag);
		MergeTwoArea(arr, left, mid, right, flag);
	}
}

int main(void)
{
	int n, order = 0, flag;
	scanf("%d", &n);

	Pos* parr = (Pos*)malloc(sizeof(Pos) * n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &(parr[i].num));
		parr[i].order = order++;
	}

	flag = 0;
	MergeSort(parr, 0, n - 1, flag);

	parr[0].idx = 0;
	for (int i = 1, idx = 0; i < n; i++)
	{
		if (parr[i - 1].num == parr[i].num)
			parr[i].idx = idx;
		else
			parr[i].idx = ++idx;
	}

	flag = 1;
	MergeSort(parr, 0, n - 1, flag);

	for (int i = 0; i < n; i++)
		printf("%d ", parr[i].idx);

	free(parr);
}
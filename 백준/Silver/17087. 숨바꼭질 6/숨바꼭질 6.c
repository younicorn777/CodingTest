#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	else
		return GCD(b, a % b);
}

void MergeTwoArr(int arr[], int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid + 1;

	int* SortArr = (int*)malloc(sizeof(int) * (right + 1));
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right)
	{
		if (arr[fIdx] <= arr[rIdx])
			SortArr[sIdx] = arr[fIdx++];
		else
			SortArr[sIdx] = arr[rIdx++];

		sIdx++;
	}

	if (fIdx > mid)
	{
		for (int i = rIdx; i <= right; i++)
			SortArr[sIdx++] = arr[i];
	}
	else
	{
		for (int i = fIdx; i <= mid; i++)
			SortArr[sIdx++] = arr[i];
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
		MergeTwoArr(arr, left, mid, right);
	}
}

int Pos[100001];
int PosDiff[100000];

int main()
{
	int n, gcd, idx = 0;
	scanf("%d", &n);

	for (int i = 0; i < (n + 1); i++)
		scanf("%d", Pos + i);

	MergeSort(Pos, 0, n);

	for (int i = 0; i < n; i++)
		PosDiff[i] = Pos[i + 1] - Pos[i];

	gcd = PosDiff[0];
	while (idx < (n - 1))
		gcd = GCD(gcd, PosDiff[++idx]);

	printf("%d", gcd);
}
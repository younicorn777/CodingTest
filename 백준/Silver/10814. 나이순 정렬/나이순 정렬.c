#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _PersonInfo
{
	int order;      // 가입한 순서 
	int age;        // 나이
	char name[101]; // 이름
}Person;

void MergeTwoArea(Person *arr, int left, int mid, int right)
{
	int fidx = left;
	int ridx = mid + 1;

	Person* sortArr = (Person*)malloc(sizeof(Person) * (right + 1));
	int sidx = left;

	while (fidx <= mid && ridx <= right)
	{
		if (arr[fidx].age < arr[ridx].age)
			sortArr[sidx] = arr[fidx++];
		
		else if (arr[fidx].age == arr[ridx].age)
		{
			if (arr[fidx].order < arr[ridx].order)
				sortArr[sidx] = arr[fidx++];
			else
				sortArr[sidx] = arr[ridx++];
		}
		
		else
			sortArr[sidx] = arr[ridx++];

		sidx++;
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


void MergeSort(Person *arr, int left, int right)
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
	int n, order = 0;
	scanf("%d", &n);

	Person* parr = (Person*)malloc(sizeof(Person) * n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d%s", &(parr[i].age), parr[i].name);
		parr[i].order = order++;
	}

	MergeSort(parr, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%d %s\n", parr[i].age, parr[i].name);
	
	free(parr);
}
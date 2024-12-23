#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define	TBL_SIZE 193
#define STR_LEN 21

typedef int Key;
typedef char Value;
typedef int HashFunc(int key);

typedef struct _node
{
	Key key;
	Value value[STR_LEN];
	struct _node* next;
}Node;

typedef struct _table
{
	Node* slot[TBL_SIZE];
	HashFunc* hf;
}Table;

// 해쉬테이블
void TBLInit(Table* pt, HashFunc* f);
void TBLInsert(Table* pt, Key k, Value* v);
int TBLSearch(Table* pt, Key k, Value* v);
void TBLDestroy(Table* pt);

// 병합정렬
void MergeTwoArea(char arr[][STR_LEN], int left, int mid, int right);
void MergeSort(char arr[][STR_LEN], int left, int right);

// 기타 기능
int MyHashFunc(int key)
{
	return key % TBL_SIZE;
}

int MakeKey(char* pstr)
{
	int key = 0;

	while (*pstr)
	{
		key += (*pstr);
		pstr++;
	}

	return key;
}

char Dntse[500000][STR_LEN];

int main()
{
	Table table;
	TBLInit(&table, MyHashFunc);

	int n, m, i, idx = 0;
	char str[STR_LEN];
	scanf("%d%d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%s", str);
		TBLInsert(&table, MakeKey(str), str);
	}

	for (i = 0; i < m; i++)
	{
		scanf("%s", str);
		
		if (TBLSearch(&table, MakeKey(str), str))
			strcpy(Dntse[idx++], str);
	}

	MergeSort(Dntse, 0, idx - 1);

	printf("%d\n", idx);
	
	for (int i = 0; i < idx; i++)
		printf("%s\n", Dntse[i]);

	TBLDestroy(&table);
}

void TBLInit(Table* pt, HashFunc* f)
{
	for (int i = 0; i < TBL_SIZE; i++)
	{
		Node* newnode = (Node*)malloc(sizeof(Node));
		newnode->next = NULL;
		(pt->slot[i]) = newnode;
	}

	pt->hf = f;
}

void TBLInsert(Table* pt, Key k, Value* v)
{
	int hv = pt->hf(k);

	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->key = k;
	strcpy(newnode->value, v);

	newnode->next = pt->slot[hv]->next;
	pt->slot[hv]->next = newnode;
}

int TBLSearch(Table* pt, Key k, Value* v)
{
	int hv = pt->hf(k);
	Node* cur = pt->slot[hv]->next;

	if (cur != NULL)
	{
		if (cur->key == k && !strcmp(cur->value, v))
			return 1;
		else
		{
			while (cur->next != NULL)
			{
				cur = cur->next;

				if (cur->key == k && !strcmp(cur->value, v))
					return 1;
			}
		}
	}

	return 0;
}

void TBLDestroy(Table* pt)
{
	Node* cur;
	Node* Next;

	for (int i = 0; i < TBL_SIZE; i++)
	{
		cur = pt->slot[i]->next;

		while (cur != NULL)
		{
			Next = cur->next;
			free(cur);
			cur = Next;
		}

		free(pt->slot[i]);
	}
}

void MergeTwoArea(char arr[][STR_LEN], int left, int mid, int right)
{
	int i;
	int fIdx = left;
	int rIdx = mid + 1;

	char** SortArr = (char**)malloc(sizeof(char*) * (right + 1));

	for (int i = left; i <= right; i++)
		SortArr[i] = (char*)malloc(sizeof(char) * STR_LEN);

	int sIdx = left;

	while (fIdx <= mid && rIdx <= right)
	{
		if (strcmp(arr[fIdx], arr[rIdx]) < 0)
			strcpy(SortArr[sIdx], arr[fIdx++]);
		else
			strcpy(SortArr[sIdx], arr[rIdx++]);

		sIdx++;
	}

	if (fIdx > mid)
	{
		for (i = rIdx; i <= right; i++)
			strcpy(SortArr[sIdx++], arr[i]);
	}
	else
	{
		for (i = fIdx; i <= mid; i++)
			strcpy(SortArr[sIdx++], arr[i]);
	}

	for (i = left; i <= right; i++)
	{
		strcpy(arr[i], SortArr[i]);
		free(SortArr[i]);
	}

	free(SortArr);
}

void MergeSort(char arr[][STR_LEN], int left, int right)
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
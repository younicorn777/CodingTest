#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define	TBL_SIZE 193
#define STR_LEN 6

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
void Remove(Node* before, Node* cur);
void TBLDelete(Table* pt, Key k, Value* v);
void TBLMergeAndPrint(Table* pt, int size);

// 병합정렬
void MergeTwoArea(char** arr, int left, int mid, int right);
void MergeSort(char** arr, int left, int right);

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

int main()
{
	Table table;
	TBLInit(&table, MyHashFunc);

	int n, ecount = 0, lcount = 0;
	char name[STR_LEN], record[STR_LEN];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s%s", name, record);

		if (!strcmp(record, "enter"))
		{
			TBLInsert(&table, MakeKey(name), name);
			ecount++;
		}
		else
		{
			TBLDelete(&table, MakeKey(name), name);
			lcount++;
		}
	}

	TBLMergeAndPrint(&table, ecount - lcount);
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

void Remove(Node* before, Node* cur)
{
	Node* delnode = cur;
	before->next = delnode->next;
	cur = before;
	free(delnode);
}

void TBLDelete(Table* pt, Key k, Value* v)
{
	int hv = pt->hf(k);
	
	Node* before = pt->slot[hv];
	Node* cur = before->next;

	if (cur != NULL)
	{
		if (cur->key == k && !(strcmp(cur->value, v)))
		{
			Remove(before, cur);
			return;
		}
		else
		{
			while (cur->next != NULL)
			{
				before = cur;
				cur = cur->next;

				if (cur->key == k && !(strcmp(cur->value, v)))
				{
					Remove(before, cur);
					return;
				}
			}
		}
	}
}

void TBLMergeAndPrint(Table* pt, int size)
{
	int sIdx = 0;
	Node* cur;
	Node* Next;

	char** pstr = (char**)malloc(sizeof(char*) * size);

	for (int i = 0; i < size; i++)
		pstr[i] = (char*)malloc(sizeof(char) * STR_LEN);

	for (int i = 0; i < TBL_SIZE; i++)
	{
		cur = pt->slot[i]->next;
		
		while (cur != NULL)
		{
			Next = cur->next;
			strcpy(pstr[sIdx++], cur->value);
			free(cur);
			cur = Next;
		}
	}

	MergeSort(pstr, 0, size - 1);

	for (int i = size - 1; i >= 0; i--)
	{
		printf("%s\n", pstr[i]);
		free(pstr[i]);
	}

	free(pstr);
}

void MergeTwoArea(char** arr, int left, int mid, int right)
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

void MergeSort(char** arr, int left, int right)
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
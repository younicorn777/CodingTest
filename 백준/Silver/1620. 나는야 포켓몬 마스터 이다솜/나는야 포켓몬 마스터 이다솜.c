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
	int num;
	Key key;
	Value value[STR_LEN];
	struct _node* next;
}Node;

typedef struct _table
{
	Node* slot[TBL_SIZE];
	HashFunc* hf;
}Table;

void TBLInit(Table* pt, HashFunc* f);
void TBLInsert(Table* pt, Key k, Value* v, int num);
void TBLSearch(Table* pt, Key k, Value* v);
void TBLDestroy(Table* pt);

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

char monster[100001][STR_LEN];

int main()
{
	Table table;
	TBLInit(&table, MyHashFunc);

	int n, m, i;
	char str[STR_LEN];
	scanf("%d%d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%s", str);
		strcpy(monster[i + 1], str);
		TBLInsert(&table, MakeKey(str), str, i + 1);
	}

	for (i = 0; i < m; i++)
	{
		scanf("%s", str);

		if (str[0] <= 57)
			printf("%s\n", monster[atoi(str)]);
		else
			TBLSearch(&table, MakeKey(str), str);
	}

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

void TBLInsert(Table* pt, Key k, Value* v, int num)
{
	int hv = pt->hf(k);

	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->key = k;
	strcpy(newnode->value, v);
	newnode->num = num;

	newnode->next = pt->slot[hv]->next;
	pt->slot[hv]->next = newnode;
}

void TBLSearch(Table* pt, Key k, Value* v)
{
	int hv = pt->hf(k);
	Node* cur = pt->slot[hv]->next;

	if (cur != NULL)
	{
		if (cur->key == k && !strcmp(cur->value, v))
		{
			printf("%d\n", cur->num);
			return;
		}
		else
		{
			while (cur->next != NULL)
			{
				cur = cur->next;

				if (cur->key == k && !strcmp(cur->value, v))
				{
					printf("%d\n", cur->num);
					return;
				}
			}
		}
	}
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
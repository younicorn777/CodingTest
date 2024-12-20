#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define	TBL_SIZE 193
#define STR_LEN 501

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

void TBLInit(Table* pt, HashFunc *f)
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

int TBLSearch(Table* pt, Key k, Value* str)
{
	int hv = pt->hf(k);
	Node* cur = pt->slot[hv]->next;

	if (cur != NULL)
	{
		if (cur->key == k && !(strcmp(cur->value, str)))
			return 1;
		else
		{
			while (cur->next != NULL)
			{
				cur = cur->next;
				
				if (cur->key == k && !(strcmp(cur->value, str)))
					return 1;
			}
		}
	}

	return 0;
}

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

	int n, m, count = 0;
	char str[501];
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		TBLInsert(&table, MakeKey(str), str);
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%s", str);
		count += (TBLSearch(&table, MakeKey(str), str));
	}

	printf("%d", count);
}

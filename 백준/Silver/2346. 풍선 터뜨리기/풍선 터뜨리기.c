#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
	int idx; 
	Data move; 
	struct _node* next;
	struct _node* prev;
}Node;

typedef struct _CircularList
{
	Node* cur; 
	Node* tail;
}List;

void ListInit(List* plist)
{
	plist->tail = NULL;
}

void LInsert(List* plist, int idx, Data move)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->idx = idx;
	newnode->move = move;

	if (plist->tail == NULL)
	{
		plist->tail = newnode;
		newnode->next = newnode;
		newnode->prev = newnode;
	}
	else
	{
		newnode->next = plist->tail->next;
		plist->tail->next->prev = newnode;
		
		plist->tail->next = newnode;
		newnode->prev = plist->tail;
		
		plist->tail = newnode;
	}
}

Data LRemove(List* plist, Data *pmove)
{
	Node* delnode = plist->cur;
	int retdata = delnode->idx; 
	*pmove = delnode->move;

	if (delnode == plist->tail)
	{
		if (plist->tail->next == plist->tail)
			plist->tail = NULL;
		else
			plist->tail = plist->cur->prev;
	}

	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev;
	plist->cur = plist->cur->prev;

	free(delnode);
	return retdata;
}

int LFirst(List* plist)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->cur = plist->tail->next;
	return TRUE;
}

int LSearch(List* plist, Data move)
{
	if (plist->tail == NULL)
		return FALSE;

	if (move > 0)
	{
		for (int i = 0; i < move; i++)
			plist->cur = plist->cur->next;
	}
	else
	{
		for (int i = move; i < -1; i++)
			plist->cur = plist->cur->prev;
	}

	return TRUE;
}

int main(void)
{
	List list;
	ListInit(&list);

	int n, idx = 0, move;
	scanf("%d", &n);

	int* presult = (int*)malloc(sizeof(int) * n);

	for (int i = 1, data; i <= n; i++)
	{
		scanf("%d", &data);
		LInsert(&list, i, data);
	}

	if (LFirst(&list))
	{
		presult[idx++] = LRemove(&list, &move);

		while (LSearch(&list, move))
			presult[idx++] = LRemove(&list, &move);
	}
	
	for (idx = 0; idx < n; idx++)
		printf("%d ", presult[idx]);

	free(presult);
}
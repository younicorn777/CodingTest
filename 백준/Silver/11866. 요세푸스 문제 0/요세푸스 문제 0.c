#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
}Node;

typedef struct _CiruclarList
{
	Node* tail;
	Node* before;
	Node* cur;
}List;

void ListInit(List* plist)
{
	plist->tail = NULL;
}

void LInsert(List* plist, Data data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newnode;
		newnode->next = newnode;
	}
	else
	{
		newnode->next = plist->tail->next;
		plist->tail->next = newnode;
		plist->tail = newnode;
	}
}

Data LRemove(List* plist)
{
	Node* delnode = plist->cur;
	Data retData = delnode->data;

	if (delnode == plist->tail)
	{
		if (plist->tail == plist->tail->next)
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	
	free(delnode);
	return retData;
}

int LFirst(List* plist)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->tail;
	plist->cur = plist->tail->next;
	return TRUE;
}

int LNext(List* plist)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	return TRUE;
}

int main(void)
{
	List list;
	ListInit(&list);

	int n, k, idx = 0, count = 0;
	scanf("%d%d", &n, &k);

	int* presult = (int*)malloc(sizeof(int) * n);

	for (int i = 1; i <= n; i++)
		LInsert(&list, i);

	if (LFirst(&list))
	{
		count++;
		if (count == k)
		{
			presult[idx++] = LRemove(&list);
			count = 0;
		}

		while (LNext(&list))
		{
			count++;
			if (count == k)
			{
				presult[idx++] = LRemove(&list);
				count = 0;
			}
		}
	}

	printf("<");
	for (idx = 0; idx < n; idx++)
	{
		if (idx == n - 1)
			printf("%d", presult[idx]);
		else 
			printf("%d, ", presult[idx]);
	}
	printf(">");

	free(presult);
}
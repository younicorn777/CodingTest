#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef char Data;

typedef struct _node
{
	Data data;
	struct _node* next;
	struct _node* prev;
}Node;

typedef struct _DLinkedList
{
	Node* head;
	Node* tail;
	Node* cur;
}List;

void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->tail = (Node*)malloc(sizeof(Node));
	plist->cur = plist->tail;

	plist->head->prev = NULL;
	plist->head->next = plist->tail;
	
	plist->tail->next = NULL;
	plist->tail->prev = plist->head;
}

void LInsert(List* plist, Data data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;

	newnode->prev = plist->cur->prev;
	plist->cur->prev->next = newnode;

	plist->cur->prev = newnode;
	newnode->next = plist->cur;
}

int LFirst(List* plist, Data *data)
{
	if (plist->head->next == plist->tail)
		return FALSE;

	plist->cur = plist->head->next;
	*data = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, Data *data)
{
	if (plist->cur->next == plist->tail)
		return FALSE;

	plist->cur = plist->cur->next;
	*data = plist->cur->data;
	return TRUE;
}

void LRemove(List* plist)
{
	Node* delnode;

	if (plist->cur->prev == plist->head)
		return;

	delnode = plist->cur->prev;

	plist->cur->prev = delnode->prev;
	delnode->prev->next = plist->cur;
}

void MoveLeft(List* plist)
{
	if (plist->cur->prev == plist->head)
		return;

	plist->cur = plist->cur->prev;
}

void MoveRight(List* plist)
{
	if (plist->cur->next == NULL)
		return;

	plist->cur = plist->cur->next;
}

int main(void)
{
	List list;
	ListInit(&list);

	int m, size;
	char op, data;
	
	char* str = (char*)malloc(sizeof(char) * 100001);
	scanf("%s", str);
	size = strlen(str);

	for (int i = 0; i < size; i++)
		LInsert(&list, str[i]);

	scanf("%d", &m);
	getchar();

	for (int i = 0; i < m; i++)
	{
		scanf("%c", &op);

		switch (op)
		{
			case 'L':
				MoveLeft(&list);
				break;

			case 'D':
				MoveRight(&list);
				break;

			case 'P':
				getchar();
				scanf("%c", &data);
				LInsert(&list, data);
				break;
			
			case 'B':
				LRemove(&list);
				break;
		}
		getchar();
	}

	if (LFirst(&list, &data))
	{
		printf("%c", data);
		LRemove(&list);
		while (LNext(&list, &data))
		{
			printf("%c", data);
			LRemove(&list);
		}
	}

	free(str);
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef char* Data;

typedef struct _node
{
	Data data;
	struct _node* next;
}Node;

typedef struct LinkedList
{
	Node* head;
	Node* cur;
	Node* before;
}List;

void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
}

void LInsert(List* plist, Data data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;

	Node* prev = plist->head;

	while (prev->next != NULL && strcmp(data, prev->next->data) > 0)
		prev = prev->next;

	newnode->next = prev->next;
	prev->next = newnode;
}

Data LRemove(List* plist)
{
	Node* delnode = plist->cur;
	Data deldata = delnode->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(delnode);
	return deldata;
}

int LFirst(List* plist)
{
	if (plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	return TRUE;
}

int LNext(List* plist)
{
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	return TRUE;
}

int main(void)
{
	List list;
	ListInit(&list);

	char str[1001];
	scanf("%s", str);

	int size = strlen(str);

	for (int i = 0; i < size; i++)
		LInsert(&list, str + i);

	if (LFirst(&list))
	{
		printf("%s\n", LRemove(&list));
		while(LNext(&list))
			printf("%s\n", LRemove(&list));
	}
}
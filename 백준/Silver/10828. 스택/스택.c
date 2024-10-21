#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _node
{
	int data;
	struct _node* next;
}Node;

typedef struct _list_stack
{
	int numofdata;
	Node* head;
}Stack;

void StackInit(Stack* pstack)
{
	pstack->head = (Node*)malloc(sizeof(Node));
	pstack->head->next = NULL;
	pstack->numofdata = 0;
}

int SIsEmpty(Stack* pstack)
{
	if (pstack->numofdata == 0)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, int data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;

	newnode->next = pstack->head->next;
	pstack->head->next = newnode;

	(pstack->numofdata)++;
}

int SPop(Stack* pstack)
{
	Node* delnode;
	int deldata;

	if (SIsEmpty(pstack))
		return -1;

	delnode = pstack->head->next;
	deldata = delnode->data;

	pstack->head->next = delnode->next;
	free(delnode);
	(pstack->numofdata)--;
	return deldata;
}

int SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack))
		return -1;

	return pstack->head->next->data;
}

int NumOfData(Stack* pstack)
{
	return pstack->numofdata;
}

int main(void)
{
	Stack stack;
	StackInit(&stack);

	char str[6];
	int n;
	scanf("%d", &n);

	for (int i = 0, data; i < n; i++)
	{
		scanf("%s", str);

		if (strcmp(str, "push") == 0)
		{
			scanf("%d", &data);
			SPush(&stack, data);
		}

		else if (strcmp(str, "pop") == 0)
			printf("%d\n", SPop(&stack));

		else if (strcmp(str, "size") == 0)
			printf("%d\n", NumOfData(&stack));

		else if (strcmp(str, "empty") == 0)
			printf("%d\n", SIsEmpty(&stack));

		else
			printf("%d\n", SPeek(&stack));
	}
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _node
{
	int data;
	int appear;
	int turn;
	struct _node* next;
}Node;

typedef struct _list_stack
{
	Node* head;
}Stack;

void StackInit(Stack* pstack)
{
	pstack->head = (Node*)malloc(sizeof(Node));
	pstack->head->next = NULL;
}

int SIsEmpty(Stack* pstack)
{
	if (pstack->head->next == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, int data, int appear,int turn)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	newnode->appear = appear;
	newnode->turn = turn;

	newnode->next = pstack->head->next;
	pstack->head->next = newnode;
}

int SPop(Stack* pstack)
{
	Node* delnode;
	int deldata;

	if (SIsEmpty(pstack))
		return -1;

	delnode = pstack->head->next;
	deldata = delnode->turn;

	pstack->head->next = delnode->next;
	free(delnode);
	return deldata;
}

int SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack))
		return -1;

	return pstack->head->next->appear;
}

int arr[1000000] = { 0 };
int count[1000001] = { 0 };
int result[1000000] = { 0 };

int main()
{
	Stack stack;
	StackInit(&stack);

	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		scanf("%d", &arr[i]);
		count[arr[i]]++;
	}

	for (int i = 0, data, appear; i < t; i++)
	{
		data = arr[i];
		appear = count[arr[i]];

		if (SPeek(&stack) < appear)
		{
			while (!SIsEmpty(&stack) && SPeek(&stack) < appear)
				result[SPop(&stack)] = data;

			SPush(&stack, data, appear, i);
		}
		else
			SPush(&stack, data, appear, i);
	}

	while (!SIsEmpty(&stack))
		result[SPop(&stack)] = -1;

	for (int i = 0; i < t; i++)
		printf("%d ", result[i]);
}
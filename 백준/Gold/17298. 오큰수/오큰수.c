#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _node
{
	int data;
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

void SPush(Stack* pstack, int data, int turn)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
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

	return pstack->head->next->data;
}

int main()
{
	Stack stack;
	StackInit(&stack);

	int t;
	scanf("%d", &t);

	int* presult = (int*)malloc(sizeof(int) * t);

	for (int i = 0, data; i < t; i++)
	{
		scanf("%d", &data);
		
		if (SPeek(&stack) < data)
		{
			while (!SIsEmpty(&stack) && SPeek(&stack) < data)
				presult[SPop(&stack)] = data;
			
			SPush(&stack, data, i);
		}
		else
			SPush(&stack, data, i);
	}

	while (!SIsEmpty(&stack))
		presult[SPop(&stack)] = -1;

	for (int i = 0; i < t; i++)
		printf("%d ", presult[i]);

	free(presult);
}
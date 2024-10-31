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

typedef struct _list_stack
{
	Node* head;
	int numofdata;
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

void SPush(Stack* pstack, Data data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;

	newnode->next = pstack->head->next;
	pstack->head->next = newnode;

	(pstack->numofdata)++;
}

Data SPop(Stack* pstack)
{
	Node* delnode;
	Data deldata;

	if (SIsEmpty(pstack))
		return -1;

	delnode = pstack->head->next;
	deldata = delnode->data;

	pstack->head->next = delnode->next;
	free(delnode);
	(pstack->numofdata)--;
	return deldata;
}

Data SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack))
		return -1;

	return pstack->head->next->data;
}

void NumOfData(Stack* pstack)
{
	printf("%d\n", pstack->numofdata);
}

int main(void)
{
	Stack stack;
	StackInit(&stack);

	int n;
	scanf("%d", &n);

	for (int i = 0, op, data; i < n; i++)
	{
		scanf("%d", &op);

		switch (op)
		{
			case 1:
				scanf("%d", &data);
				SPush(&stack, data);
				break;
			
			case 2:
				printf("%d\n", SPop(&stack));
				break;

			case 3:
				NumOfData(&stack);
				break;

			case 4:
				printf("%d\n", SIsEmpty(&stack));
				break;
			
			case 5:
				printf("%d\n", SPeek(&stack));
				break;
		}
	}

	while (!SIsEmpty(&stack))
		SPop(&stack);
}
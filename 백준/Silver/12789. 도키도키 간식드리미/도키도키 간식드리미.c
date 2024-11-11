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

typedef struct ListBasestack
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

void SPush(Stack* pstack, Data data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;

	newnode->next = pstack->head->next;
	pstack->head->next = newnode;
}

Data SPop(Stack* pstack)
{
	Node* delnode;
	Data deldata;

	if (SIsEmpty(pstack))
		return FALSE;

	delnode = pstack->head->next;
	deldata = delnode->data;

	pstack->head->next = delnode->next;
	free(delnode);
	return deldata;
}

Data SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack))
		return FALSE;

	return pstack->head->next->data;
}

int main(void)
{
	Stack stack;
	StackInit(&stack);
	
	int arr[1000] = { 0 };
	int n, idx = 0, cut = 1;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);

	while (idx < n)
	{
		if (arr[idx] == cut)
		{
			cut++;
			idx++;
		}
		else if (SPeek(&stack) == cut)
		{
			SPop(&stack);
			cut++;
		}
		else
			SPush(&stack, arr[idx++]);
	}

	while (!SIsEmpty(&stack))
	{
		if (SPeek(&stack) == cut)
		{
			SPop(&stack);
			cut++;
		}
		else
		{
			printf("Sad");
			while (!SIsEmpty(&stack))
				SPop(&stack);
			return 0;
		}
	}

	printf("Nice");
}
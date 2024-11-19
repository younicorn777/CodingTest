#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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

void SPush(Stack* pstack, int data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;

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
	deldata = delnode->data;

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

char str[100000];

int main()
{
	Stack stack;
	StackInit(&stack);

	int idx = 0, laser = 0, remain = 0;
	scanf("%s", str);

	while (str[idx] != '\0')
	{
		if (str[idx] == '(')
			SPush(&stack, -1);
		else
		{
			if (SPeek(&stack) == -1)
			{
				SPop(&stack);

				if (!SIsEmpty(&stack))
					SPush(&stack, 1);
			}
			else
			{
				while (SPeek(&stack) != -1)
					laser += SPop(&stack);
				
				SPop(&stack);
				
				remain += (laser + 1);

				if (!SIsEmpty(&stack))
					SPush(&stack, laser);

				laser = 0;
			}
		}
		idx++;
	}
	printf("%d", remain);
}
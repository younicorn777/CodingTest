#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef char Data;

typedef struct _node
{
	Data data;
	struct _node* next;
}Node;

typedef struct _ListBaseStack
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
		exit(-1);

	delnode = pstack->head->next;
	deldata = delnode->data;

	pstack->head->next = delnode->next;
	free(delnode);
	return deldata;
}

Data SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack))
		exit(-1);

	return pstack->head->next->data;
}

int main(void)
{
	Stack stack;
	StackInit(&stack);

	int size;
	char op;
	char str[101];

	while (1)
	{
		scanf("%[^\n]s", str);
		getchar();

		if (str[0] == '.')
			break;

		size = strlen(str);

		for (int i = 0; i < size - 1; i++)
		{
			op = str[i];

			if (isalpha(op) || op == ' ')
				continue;

			switch (op)
			{
				case ')':
					if (SIsEmpty(&stack) || SPeek(&stack) != '(')
						SPush(&stack, op);
					else
						SPop(&stack);
				
					break;

				case ']':
					if (SIsEmpty(&stack) || SPeek(&stack) != '[')
						SPush(&stack, op);
					else
						SPop(&stack);
				
					break;

				default:
					SPush(&stack, op);
					break;
			}
		}

		if (SIsEmpty(&stack))
			printf("yes\n");
		else
		{
			printf("no\n");
			while (!SIsEmpty(&stack))
				SPop(&stack);
		}
	}
}
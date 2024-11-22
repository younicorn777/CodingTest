#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef double Data;

typedef struct _node
{
	Data data;
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

int main()
{
	Stack stack;
	StackInit(&stack);

	char str[101], op;
	double alpha[26] = { 0.0 };
	double data1, data2;

	int op_count, size;
	scanf("%d", &op_count);
	
	scanf("%s", str);
	size = strlen(str);

	for (int i = 0; i < op_count; i++)
		scanf("%lf", &alpha[i]);

	for (int i = 0; i < size; i++)
	{
		op = str[i];

		if (isalpha(op))
		{
			SPush(&stack, alpha[op - 65]);
			continue;
		}

		data2 = SPop(&stack);
		data1 = SPop(&stack);

		switch (op)
		{
			case '+':
				SPush(&stack, data1 + data2);
				break;
			
			case '-':
				SPush(&stack, data1 - data2);
				break;

			case '*':
				SPush(&stack, data1 * data2);
				break;

			case '/':
				SPush(&stack, data1 / data2);
				break;
		}
	}

	printf("%.2lf", SPop(&stack));
}
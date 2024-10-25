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
		return -1;

	delnode = pstack->head->next;
	deldata = delnode->data;

	pstack->head->next = delnode->next;
	free(delnode);
	return deldata;
}

Data SPeek(Stack *pstack)
{
	if (SIsEmpty(pstack))
		return -1;
	
	return pstack->head->next->data;
}

int main(void)
{
	Stack stack;
	StackInit(&stack);

	int n, idx = 0; //idx = 결과를 배열에 저장할 때 쓰는 인덱스
	scanf("%d", &n);

	int* parr = (int*)malloc(sizeof(int) * n);
	char* presult = (char*)malloc(sizeof(char) * 2 * n);

	for (int i = 0; i < n; i++)
		scanf("%d", &parr[i]);

	for (int j = 0, i = 1, target; j < n; j++)
	{
		target = parr[j];

		if (target > SPeek(&stack))
		{
			while (target > SPeek(&stack))
			{
				SPush(&stack, i++);
				presult[idx++] = '+';
			}
		}
		else
		{
			if (SPeek(&stack) != target)
			{
				printf("NO\n");

				while (!SIsEmpty(&stack))
					SPop(&stack);

				return 0;
			}
		}
		SPop(&stack);
		presult[idx++] = '-';
	}

	for (int i = 0; i < (2 * n); i++)
		printf("%c\n", presult[i]);

	free(parr);
	free(presult);
}
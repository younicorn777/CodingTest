#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef char Data;

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

int main(void)
{
	Stack stack;
	StackInit(&stack);
	
	char str[1001];
	int t;
	scanf("%d", &t);
	getchar();

	for (int i = 0, size; i < t; i++)
	{
		scanf("%[^\n]s", str);
		getchar();

		char *ptoken = strtok(str, " ");
		while (ptoken != NULL)
		{
			size = strlen(ptoken);
			for (int i = 0; i < size; i++)
				SPush(&stack, ptoken[i]);

			while (!SIsEmpty(&stack))
				printf("%c", SPop(&stack));
			printf(" ");

			ptoken = strtok(NULL, " ");
		}
		printf("\n");
	}
}
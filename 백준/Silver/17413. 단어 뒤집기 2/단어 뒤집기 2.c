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
		exit(1);

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

	int size, idx = 0;
	char* pstr = (char*)malloc(sizeof(char) * 100001);
	scanf("%[^\n]s", pstr);
	
	size = strlen(pstr);

	while (idx < size)
	{
		if (pstr[idx] == '<' || pstr[idx] == ' ')
		{
			while (!SIsEmpty(&stack))
				printf("%c", SPop(&stack));

			if (pstr[idx] == '<')
			{
				while (pstr[idx] != '>')
					printf("%c", pstr[idx++]);
			}

			printf("%c", pstr[idx++]);
		}
		else
			SPush(&stack, pstr[idx++]);
	}
	while (!SIsEmpty(&stack))
		printf("%c", SPop(&stack));
	free(pstr);
}
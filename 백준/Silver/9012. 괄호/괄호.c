#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _strInfo
{
	char str[51];//문장
	int size;    //글자 개수
}Str;

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

	int t;
	scanf("%d", &t);
	Str* parr = (Str*)malloc(sizeof(Str) * t);

	for (int i = 0, j; i < t; i++)
	{
		scanf("%s", parr[i].str);
		parr[i].size = strlen(parr[i].str);

		for (j = 0; j < parr[i].size; j++)
		{
			if (SIsEmpty(&stack) && (parr[i].str)[j] == ')')
			{
				printf("NO\n");
				break;
			}
			else if ((parr[i].str)[j] == '(')
				SPush(&stack, '(');
			else if ((parr[i].str)[j] == ')')
				SPop(&stack);
		}

		if (j == parr[i].size)
			(SIsEmpty(&stack)) ? printf("YES\n") : printf("NO\n");

		while (!SIsEmpty(&stack))
			SPop(&stack);
	}
	free(parr);
}
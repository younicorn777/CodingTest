#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

typedef char Data;

typedef struct _node
{
	Data data;
	struct _node* next;
}Node;

typedef struct ListBaseStack
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

int GetOpPrec(char op)
{
	switch (op)
	{
		case '(':
			return 1;

		case '+': case '-':
			return 2;

		case '*': case '/':
			return 3;
	}

	return -1;
}

int WhoOpPrec(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)
		return 1;
	else if (op1Prec < op2Prec)
		return -1;
	else
		return 0;
}

void ConvToRPNExp(char exp[], int size)
{
	Stack stack;
	StackInit(&stack);

	int idx = 0;
	char tok;
	char* convExp = (char*)malloc(sizeof(char) * (size + 1));
	memset(convExp, 0, sizeof(char) * (size + 1));

	for (int i = 0; i < size; i++)
	{
		tok = exp[i];

		if (isalpha(tok))
			convExp[idx++] = tok;
		else
		{
			switch (tok)
			{
				case '(':
					SPush(&stack, '(');
					break;
				
				case ')':
					while (SPeek(&stack) != '(')
						convExp[idx++] = SPop(&stack);
					SPop(&stack);
					break;

				default:
					while(!SIsEmpty(&stack) && WhoOpPrec(tok, SPeek(&stack)) <= 0)
						convExp[idx++] = SPop(&stack);
					SPush(&stack, tok);
					break;
			}
		}
	}

	while(!SIsEmpty(&stack))
		convExp[idx++] = SPop(&stack);

	strcpy(exp, convExp);
	free(convExp);
}

int main()
{	
	int size;
	char str[101];
	scanf("%s", str);
	
	size = strlen(str);

	ConvToRPNExp(str, size);

	printf("%s", str);
}
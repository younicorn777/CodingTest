#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* prev;
	struct _node* next;
}Node;

typedef struct ListBaseDequeue
{
	Node* front;
	Node* rear;
}Deque;

void DQInit(Deque* pdq)
{
	pdq->front = (Node*)malloc(sizeof(Node));
	pdq->rear = (Node*)malloc(sizeof(Node));

	pdq->front->prev = NULL;
	pdq->front->next = pdq->rear;

	pdq->rear->next = NULL;
	pdq->rear->prev = pdq->front;
}

int DQIsEmpty(Deque* pdq)
{
	if (pdq->front->next == pdq->rear)
		return TRUE;
	else
		return FALSE;
}

void DQAddFront(Deque* pdq, Data data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;

	newnode->next = pdq->front->next;
	pdq->front->next->prev = newnode;

	newnode->prev = pdq->front;
	pdq->front->next = newnode;
}

void DQAddrear(Deque* pdq, Data data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;

	newnode->prev = pdq->rear->prev;
	pdq->rear->prev->next = newnode;

	pdq->rear->prev = newnode;
	newnode->next = pdq->rear;
}

Data DQRemoveFront(Deque* pdq)
{
	Node* delnode;
	Data deldata;

	if (DQIsEmpty(pdq))
		return -1;

	delnode = pdq->front->next;
	deldata = delnode->data;

	pdq->front->next->next->prev = pdq->front;
	pdq->front->next = pdq->front->next->next;

	free(delnode);
	return deldata;
}

int main(void)
{
	Deque deque;
	DQInit(&deque);

	int n, m;
	scanf("%d", &n);

	int* flag = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		scanf("%d", flag + i);

	for (int i = 0, data; i < n; i++)
	{
		scanf("%d", &data);

		if (flag[i] == 0)
			DQAddFront(&deque, data);
	}

	scanf("%d", &m);
	int* presult = (int*)malloc(sizeof(int) * m);

	for (int i = 0; i < m; i++)
	{
		scanf("%d", presult + i);
		DQAddrear(&deque, presult[i]);
		presult[i] = DQRemoveFront(&deque);
	}

	for (int i = 0; i < m; i++)
		printf("%d ", presult[i]);
	
	free(flag);
	free(presult);
}
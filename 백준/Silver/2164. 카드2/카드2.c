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

typedef struct _ListbaseQueue
{
	Node* front;
	Node* rear;
	int numofdata;
}Queue;

void QueueInit(Queue* pq)
{
	pq->front = (Node*)malloc(sizeof(Node));
	pq->front->next = NULL;
	pq->rear = pq->front;

	pq->numofdata = 0;
}

int QIsEmpty(Queue* pq)
{
	if (pq->numofdata == 0)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue* pq, Data data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = NULL;

	if (QIsEmpty(pq))
	{
		pq->front->next = newnode;
		pq->rear = newnode;
	}
	else
	{
		pq->rear->next = newnode;
		pq->rear = newnode;
	}

	(pq->numofdata)++;
}

Data Dequeue(Queue* pq)
{
	Node* delnode;
	Data deldata;

	if (QIsEmpty(pq))
		exit(-1);

	delnode = pq->front->next;
	deldata = delnode->data;
	pq->front->next = delnode->next;

	free(delnode);
	(pq->numofdata)--;
	return deldata;
}

int NumOfData(Queue* pq)
{
	return pq->numofdata;
}

int main(void)
{
	Queue queue;
	QueueInit(&queue);

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		Enqueue(&queue, i);

	if (NumOfData(&queue) == 1)
	{
		printf("%d", Dequeue(&queue));
		return 0;
	}

	while (1)
	{
		Dequeue(&queue);

		if (NumOfData(&queue) == 1)
		{
			printf("%d", Dequeue(&queue));
			break;
		}

		Enqueue(&queue, Dequeue(&queue));
	}
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
	struct _node* prev;
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
	pq->rear = (Node*)malloc(sizeof(Node));
	
	pq->front->prev = NULL;
	pq->front->next = pq->rear;

	pq->rear->prev = pq->front;
	pq->rear->next = NULL;

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

	newnode->prev = pq->rear->prev;
	pq->rear->prev->next = newnode;

	newnode->next = pq->rear;
	pq->rear->prev = newnode;

	(pq->numofdata)++;
}

Data Dequeue(Queue* pq)
{
	Node* delnode;
	Data deldata;

	if (QIsEmpty(pq))
		return -1;

	delnode = pq->front->next;
	deldata = delnode->data;
	pq->front->next->next->prev = pq->front;
	pq->front->next = pq->front->next->next;

	free(delnode);
	(pq->numofdata)--;
	return deldata;
}

Data QPeekFront(Queue* pq)
{
	if (QIsEmpty(pq))
		return -1;
	
	return pq->front->next->data;
}

Data QPeekRear(Queue* pq)
{
	if (QIsEmpty(pq))
		return -1;

	return pq->rear->prev->data;
}

int NumOfdata(Queue* pq)
{
	return pq->numofdata;
}

int main(void)
{
	Queue queue;
	QueueInit(&queue);

	int n;
	char* pstr = (char*)malloc(sizeof(char) * 6);
	scanf("%d", &n);

	for (int i = 0, data; i < n; i++)
	{
		scanf("%s", pstr);
		getchar();

		if (strcmp(pstr, "push") == 0)
		{
			scanf("%d", &data);
			Enqueue(&queue, data);
		}

		else if (strcmp(pstr, "pop") == 0)
			printf("%d\n", Dequeue(&queue));

		else if (strcmp(pstr, "size") == 0)
			printf("%d\n", NumOfdata(&queue));

		else if (strcmp(pstr, "empty") == 0)
			printf("%d\n", QIsEmpty(&queue));

		else if (strcmp(pstr, "front") == 0)
			printf("%d\n", QPeekFront(&queue));
		else
			printf("%d\n", QPeekRear(&queue));
	}

	while (!QIsEmpty(&queue))
		Dequeue(&queue);
	free(pstr);
}
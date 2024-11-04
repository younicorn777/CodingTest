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

typedef struct _ListBaseDequeue
{
	Node* front;
	Node* rear;
	int numofdata;
}Deque;

void DQInit(Deque* pdq)
{
	pdq->front = (Node*)malloc(sizeof(Node));
	pdq->rear = (Node*)malloc(sizeof(Node));

	pdq->front->prev = NULL;
	pdq->front->next = pdq->rear;

	pdq->rear->next = NULL;
	pdq->rear->prev = pdq->front;

	pdq->numofdata = 0;
}

int DQIsEmpty(Deque* pdq)
{
	if (pdq->numofdata == 0)
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

	(pdq->numofdata)++;
}

void DQAddRear(Deque* pdq, Data data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;

	newnode->prev = pdq->rear->prev;
	pdq->rear->prev->next = newnode;

	newnode->next = pdq->rear;
	pdq->rear->prev = newnode;

	(pdq->numofdata)++;
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
	(pdq->numofdata)--;
	return deldata;
}

Data DQRemoveRear(Deque* pdq)
{
	Node* delnode;
	Data deldata;

	if (DQIsEmpty(pdq))
		return -1;

	delnode = pdq->rear->prev;
	deldata = delnode->data;

	pdq->rear->prev->prev->next = pdq->rear;
	pdq->rear->prev = pdq->rear->prev->prev;

	free(delnode);
	(pdq->numofdata)--;
	return deldata;
}

Data DQFrontPeek(Deque* pdq)
{
	if (DQIsEmpty(pdq))
		return -1;

	return pdq->front->next->data;
}

Data DQRearPeek(Deque* pdq)
{
	if (DQIsEmpty(pdq))
		return -1;

	return pdq->rear->prev->data;
}

void NumOfData(Deque* pdq)
{
	printf("%d\n", pdq->numofdata);
}

int main(void)
{
	Deque deque;
	DQInit(&deque);

	int n;
	scanf("%d", &n);

	for (int i = 0, op, data; i < n; i++)
	{
		scanf("%d", &op);

		switch (op)
		{
			case 1:
				scanf("%d", &data);
				DQAddFront(&deque, data);
				break;
			case 2:
				scanf("%d", &data);
				DQAddRear(&deque, data);
				break;
			case 3:
				printf("%d\n", DQRemoveFront(&deque));
				break;
			case 4:
				printf("%d\n", DQRemoveRear(&deque));
				break;
			case 5:
				NumOfData(&deque);
				break;
			case 6:
				printf("%d\n", DQIsEmpty(&deque));
				break;
			case 7:
				printf("%d\n", DQFrontPeek(&deque));
				break;
			case 8:
				printf("%d\n", DQRearPeek(&deque));
				break;
		}
	}

	while (!DQIsEmpty(&deque))
		DQRemoveFront(&deque);
}
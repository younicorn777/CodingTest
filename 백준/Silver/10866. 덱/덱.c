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

void DQAddrear(Deque* pdq, Data data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	
	newnode->prev = pdq->rear->prev;
	pdq->rear->prev->next = newnode;

	pdq->rear->prev = newnode;
	newnode->next = pdq->rear;

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

Data DQGetFront(Deque* pdq)
{
	if (DQIsEmpty(pdq))
		return -1;
	
	return pdq->front->next->data;
}

Data DQGetRear(Deque* pdq)
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
	char* parr = (char*)malloc(sizeof(char) * 11);
	scanf("%d", &n);

	for (int i = 0, data; i < n; i++)
	{
		scanf("%s", parr);

		if (!strcmp(parr, "push_front"))
		{
			scanf("%d", &data);
			DQAddFront(&deque, data);
		}

		else if (!strcmp(parr, "push_back"))
		{
			scanf("%d", &data);
			DQAddrear(&deque, data);
		}

		else if (!strcmp(parr, "pop_front"))
			printf("%d\n", DQRemoveFront(&deque));

		else if (!strcmp(parr, "pop_back"))
			printf("%d\n", DQRemoveRear(&deque));

		else if (!strcmp(parr, "size"))
			NumOfData(&deque);

		else if (!strcmp(parr, "empty"))
			printf("%d\n", DQIsEmpty(&deque));

		else if (!strcmp(parr, "front"))
			printf("%d\n", DQGetFront(&deque));
		else
			printf("%d\n", DQGetRear(&deque));
		getchar();
	}

	while (!DQIsEmpty(&deque))
		DQRemoveFront(&deque);
	free(parr);
}
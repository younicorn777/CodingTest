#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ArrSize 2000001
#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct ArrayBaseQueue
{
	Data arr[ArrSize];
	int front;
	int rear;
	int numofdata;
}Queue;

int NextPosIdx(int idx)
{
	if (idx == ArrSize - 1)
		return 0;
	else
		return idx + 1;
}

void QueueInit(Queue* pq)
{
	pq->front = 0;
	pq->rear = 0;
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
	if (NextPosIdx(pq->rear) == pq->front)
		exit(-1);

	pq->rear = NextPosIdx(pq->rear);
	pq->arr[pq->rear] = data;
	(pq->numofdata)++;
}

Data Dequeue(Queue* pq)
{
	Data retData;
	
	if (QIsEmpty(pq))
		return -1;

	pq->front = NextPosIdx(pq->front);
	retData = pq->arr[pq->front];
	
	(pq->numofdata)--;
	return retData;
}

Data QPeekFront(Queue* pq)
{
	if (QIsEmpty(pq))
		return -1;
	return pq->arr[NextPosIdx(pq->front)];
}

Data QPeekRear(Queue* pq)
{
	if (QIsEmpty(pq))
		return -1;
	return pq->arr[pq->rear];
}

void NumOfData(Queue* pq)
{
	printf("%d\n", pq->numofdata);
}


int main(void)
{
	Queue queue;
	QueueInit(&queue);

	int n;
	char str[6];
	scanf("%d", &n);

	for (int i = 0, data; i < n; i++)
	{
		getchar();
		scanf("%s", str);

		if (!strcmp(str, "push"))
		{
			scanf("%d", &data);
			Enqueue(&queue, data);
		}

		else if (!strcmp(str, "pop"))
			printf("%d\n", Dequeue(&queue));

		else if (!strcmp(str, "size"))
			NumOfData(&queue);

		else if (!strcmp(str, "empty"))
			printf("%d\n", QIsEmpty(&queue));

		else if (!strcmp(str, "front"))
			printf("%d\n", QPeekFront(&queue));
		
		else
			printf("%d\n", QPeekRear(&queue));
	}
}
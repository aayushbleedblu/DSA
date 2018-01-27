/*

struct MQ* mq1 = (struct MQ*) malloc(sizeof(struct MQ));
mq1->arr1 = (struct ArrElem*)malloc(sizeof(struct ArrElem)*num);

*/

#include "que.h"
#include "multiq.h"

MultiQ createMQ(int num)
{
	MultiQ mq = (MultiQ)malloc(sizeof(struct MultiQ));
	mq->arr=(Queue*)malloc(sizeof(Queue)*num);
	for(int i=0; i<num; i++)
	{
		mq->arr[i]=newQ();
	}
	mq->count=num;
	return mq;
}

MultiQ addMQ(MultiQ mq, Task t)
{
	mq->arr[t->priority]=addQ(mq->arr[t->priority], t);
	return mq;
}

Task nextMQ(MultiQ mq)
{
	int i=0;
	while(mq->arr[i]->head==NULL)
	{
		i++;
	}
	return front(mq->arr[i]);
}

MultiQ delNextMQ(MultiQ mq)
{
	int i=0;
	while(mq->arr[i]->head==NULL)
	{
		i++;
	}
	mq->arr[i] = delQ(mq->arr[i]);
}

Boolean isEmptyMQ(MultiQ mq)
{
	for(int i=0; i<mq->count; i++)
	{
		if(mq->arr[i]->head!=NULL)
		{
			return false;
		}
	}
	return true;
}

int sizeMQ(MultiQ mq)
{
	int counter=0;
	for (int i=0; i<mq->count; i++)
	{
		counter+=lengthQ(mq->arr[i]);
	}
	return counter;
}

int sizeMQbyPriority(MultiQ mq, Priority p)
{
	return lengthQ(mq->arr[p-1]);
}

Queue getQueueFromMQ(MultiQ mq, Priority p)
{
	return mq->arr[p-1];
}








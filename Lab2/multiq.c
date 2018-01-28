/*

struct MQ* mq1 = (struct MQ*) malloc(sizeof(struct MQ));
mq1->arr1 = (struct ArrElem*)malloc(sizeof(struct ArrElem)*num);

*/

#include "multiq.h"
#include <sys/time.h>

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
	mq->arr[t->priority-1]=addQ(mq->arr[t->priority-1], t);
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
	return mq;
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

MultiQ loadData(MultiQ mq, FILE* f)
{
	struct timeval t1, t2;
	double elapsedTime;
	int tid, p;
	gettimeofday(&t1, NULL);
	int count=0;
	while(fscanf(f, "%d,%d", &tid, &p)!=EOF)
	{
		 mq= addMQ(mq, newEle(p,tid));
		 count++;
	}	
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Avg time is %f ms.\n", elapsedTime/count);
	return mq;
}

MultiQ testDel(MultiQ mq,int num)
{
	struct timeval t1, t2;
	double elapsedTime;
	gettimeofday(&t1, NULL);
	for(int i=0; i<num; i++)
	{
		mq = delNextMQ(mq);
	}
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Avg time is %f ms.\n", elapsedTime/num);
	return mq;
}

void printmq(MultiQ mq)
{
	for(int i=0; i<mq->count; i++)
	{
		printQ(mq->arr[i]);
	}
}


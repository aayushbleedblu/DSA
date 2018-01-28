#include "multiq.h"
#include <stdio.h>
#include <stdlib.h>

void printmq(MultiQ mq)
{
	for(int i=0; i<mq->count; i++)
	{
		printQ(mq->arr[i]);
	}
}

int main()
{
	MultiQ mq = createMQ(3);
	mq = addMQ(mq,newEle(1,100));
	mq = addMQ(mq,newEle(1,200));
	mq = addMQ(mq,newEle(2,100));
	mq = addMQ(mq,newEle(2,200));
	mq = addMQ(mq,newEle(3,100));
	mq = delNextMQ(mq);
	printmq(mq);
	int size = sizeMQ(mq);
	printf("%d\n", size);
	int a,b;
	a=sizeMQbyPriority(mq,2);
	printf("%d", a);
}

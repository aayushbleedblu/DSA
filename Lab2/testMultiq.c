#include "multiq.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	FILE *fp;
	fp = fopen("input100.txt", "r");
	MultiQ mq = createMQ(10);
	mq = loadData(mq, fp);
//	printmq(mq);
	printf("%d\n", sizeMQbyPriority(mq,1));
	printf("%d\n", sizeMQbyPriority(mq,2));
	mq = testDel(mq, 60);
//	printmq(mq);

	Task t = newEle(1, 1000);
	mq = addMQ(mq, t);
	printmq(mq);

	printf("%d\n", sizeMQbyPriority(mq,1));
	printf("%d\n", sizeMQbyPriority(mq,2));

}

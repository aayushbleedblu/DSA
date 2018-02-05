#include <stdio.h>
#include <stdlib.h>

int globalcnt;

void * myalloc(int size, int count)
{
	void* new = (void*)malloc(size*count);
	globalcnt = globalcnt + size*count;
	return new;
}

void myfree(void* ptr, int count, int size)
{
	globalcnt = globalcnt-count*size;
	free(ptr);
}


int main()
{
/*
	printf("%d\n", globalcnt);
	int* ptr = (int*)myalloc(sizeof(int), 100);
	printf("%d\n", globalcnt);
	myfree(ptr, 50, sizeof(int));
	printf("%d\n", globalcnt);
*/
	
	while(1)
	{
	int rn = 10000+rand()%15000;
	int* a = (int*)myalloc(sizeof(int), rn);
	printf("%d, %d\n", &a[0], a+rn-1);
	myfree(a, rn, sizeof(int));
	}
	return 0;
}


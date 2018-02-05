#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

typedef struct element* element;
struct element
{
	int key;
	element next;
};

typedef struct list* list;
struct list
{
	element head;
	element tail;
	int count;
};

list createList(int N)
{
	list ls = (list)myalloc(sizeof(struct list),1);
	ls->head=NULL;
	ls->tail=NULL;
	ls->count=0;
	
	for(int i=0; i<N; i++)
	{
		element e = (element)myalloc(sizeof(struct element),1);
		e->key=rand()%100;
		e->next=NULL;
		if(ls->count==0)
		{
			ls->head=e;
			ls->tail=e;
			ls->count++;
		}
		else
		{
			ls->tail->next=e;
			ls->tail=e;
			ls->count++;
		}
	}
	return ls;
}

list createCycle(list ls)
{
	if(ls->head==NULL)
		{ return ls; }
	int toss=rand()%2;
	printf("\ntoss=%d",toss);
	if(toss==0)
	{
		return ls;
	}
	else
	{
		int r=rand()%(ls->count);
		printf("\nr=%d", r);
		element temp=(element)malloc(sizeof(struct element));
		temp=ls->head;
		for(int i=0;i<r;temp=temp->next,i++);
		ls->tail->next=temp;
		return ls;
	}	
}



void printList(list ls)
{
	element temp = (element)malloc(sizeof(struct element));
	temp=ls->head;
	if(ls->head==NULL)
		printf("\nempty list");
	for (int i=0; i<ls->count; temp=temp->next, i++)
	{
		printf("\n%d", temp->key);
	}
}

void testCyclic1(list ls)
{
	if (ls->head==NULL)
	{
		printf("\nempty list");
	}
	else
	{
		element hare=(element)malloc(sizeof(struct element));
		element tort=(element)malloc(sizeof(struct element));
		hare=tort=ls->head;
		if(hare->next!=NULL)
			{
				hare=hare->next->next;
			}
			else
			{
				printf("\nlinear list");
				return;
			}
		tort=tort->next;
		while(1)
		{
			if(hare==NULL || hare->next==NULL)
			{
				printf("\nlinear list");
				return;
			}
			else
			{
				hare=hare->next->next;
				tort=tort->next;
			}
			if(hare==tort || (hare!=NULL && hare->next==tort))
			{
				printf("\ncyclic list");
				return;
			}
		}	
	}
}

int main()
{
	srand(time(NULL));
	list ls = createList(4);
	ls = createCycle(ls);
	printList(ls);
	testCyclic1(ls);
	return 0;
}
















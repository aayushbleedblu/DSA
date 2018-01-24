#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"

struct SeqList* merge(struct SeqList* a, struct SeqList* b)
{
	struct Element* e1=a->head;
	struct Element* e2=a->head;
	while(e1!=NULL)
	{
		e2=e1;
		e1=e1->next;
		b=insertInOrder(b,e2);
	}
	return b;
}

struct SeqList* insertionSort(struct SeqList* sl)
{
	struct Element* e1 = sl->head;
	struct Element* e2 = sl->head;
	struct SeqList* sortedList = newList();
	while(e1!=NULL)
	{
		printf("%d", e1->key);
		e2=e1;
		e1=e1->next;
		sortedList = insertInOrder(sortedList, e2);

	}
	return sortedList;
}

struct SeqList* sort(struct SeqList* sl) 
{
	struct Element* e1 = sl->head;
	struct SeqList* a = newList();
	struct Element* e2 = sl->head;
	//printf("%d-%d",sl->head->key,sl->tail->key);
	while(e1!=NULL) {
		printf("%d",e1->key);
		e2=e1;
		e1=e1->next;
		a = insertInOrder(a, e2);
	}
	return a;
}





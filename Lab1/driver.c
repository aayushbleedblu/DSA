#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"

void print(struct SeqList* sl)
{
	struct Element* temp=sl->head;
	while(temp!=NULL)
	{
		printf("%d\n",temp->key);
		temp=temp->next;
	}
	printf("NULL\n");
}

struct Element* newEle(int k)
{
	struct Element* e = (struct Element *)malloc(sizeof(struct Element));
	e->key=k;
	e->next=NULL;
	return e;
}

int main()
{
	struct SeqList* sl = newList();
	sl=insertInOrder(sl,newEle(6));
	sl=insertAtEnd(sl,newEle(3));
	sl=insertAtEnd(sl,newEle(7));
	sl=insertAtEnd(sl,newEle(88));
	sl=insertAtEnd(sl,newEle(1));
	sl=insertAtEnd(sl,newEle(10));
	sl=insertAtEnd(sl,newEle(15));
	print(sl);
	sl = insertionSort(sl);
//	sl = sort(sl);
	print(sl);
	
//	struct SeqList* sec = newList();
//	sec = insertAtEnd(sec,newEle(5));
//	sec = insertAtEnd(sec,newEle(12));
//	sec = insertAtEnd(sec,newEle(23));
//	sec = insertAtEnd(sec,newEle(34));
//	print(sec);
	
//	sec = merge(sl, sec);
//	print(sec);
	
}


#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"

struct SeqList* newList()
{
	struct SeqList* sl = (struct SeqList*)malloc(sizeof(struct SeqList));
	sl->count=0;
	sl->head=NULL;
	sl->tail=NULL;
	return sl;
}


struct SeqList* insertInOrder(struct SeqList* sl, struct Element* e)
{	
	if(sl->head==NULL)
	{
		sl->head=e;
		sl->tail=e;
		e->next=NULL;
		sl->count++;
		return sl;
	}
	if(e->key<sl->head->key)
	{
		e->next=sl->head;
		sl->head=e;
		sl->count++;
		return sl;
	}
	struct Element* temp=sl->head;
	struct Element* prev=sl->head;
	while(temp!=NULL && temp->key<e->key)
	{
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)
	{
		prev->next=e;
		sl->tail=e;
		e->next=NULL;
		sl->count++;
		return sl;
	}
	e->next=prev->next;
	prev->next=e;
	sl->count++;
	return sl;	
}


struct SeqList* insertAtFront(struct SeqList* sl, struct Element* e)
{
	e->next = sl->head;
	sl->head = e;
	if(sl->count==0)
	{
		sl->tail=e;
	}
	sl->count++;
	return sl;
}


struct SeqList* insertAtEnd(struct SeqList* sl, struct Element* e)
{
	e->next=NULL;
	sl->count++;
	if(sl->count==1) 
	{
		sl->head=e;
		sl->tail=e;
		return sl;
	}
	sl->tail->next=e;
	sl->tail=e;
	return sl;
}


struct SeqList* delete(struct SeqList* sl, struct Element* e)
{
	struct Element* temp = sl->head;
	if(temp==NULL)
	{
		return sl;
	}
	struct Element* prev = temp;
	if(sl->head==e)
	{
		sl->head=temp->next;
		sl->count--;
		if(sl->count==0) { sl->tail=NULL; }
		return sl;
	}
	while(temp!=e && temp!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)
	{
		return sl;
	}
	if(sl->tail==temp)
	{
		sl->tail=prev;
		prev->next=NULL;
		sl->count--;
		return sl;
	}
	prev->next=temp->next;
	sl->count--;
	return sl;
}


struct SeqList* deleteAtFront(struct SeqList* sl)
{
	if(sl->count==0)
	{
		return sl;
	}
	if(sl->count==1)
	{
		sl->count--;
		sl->head=NULL;
		sl->tail=NULL;
		return sl;
	}
	sl->head = sl->head->next;
	sl->count--;
	return sl;
}


struct Element* find(struct SeqList* sl, int k)
{
	struct Element* temp = sl->head;
	while(temp!=NULL && temp->key!=k)
	{
	temp=temp->next;
	}
	return temp;
}



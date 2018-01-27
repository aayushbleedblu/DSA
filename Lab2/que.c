#include "que.h"

Queue newQ()
{
	Queue q = (Queue)malloc(sizeof(struct queue));
	q->head = NULL;
	q->tail = NULL;
	return q;
}


Boolean isEmptyQ(Queue q)
{
	if (q->head==NULL)
		return true;
	else
		return false;
}


Queue delQ(Queue q)
{
	if(q->head==NULL)
	{
		return q;
	}
	else if (q->head==q->tail)
	{
		q->head==NULL;
		q->tail==NULL;
		return q;
	}
	q->head = q->head->next;
	return q;
}


Element front(Queue q)
{
	return q->head;
}


Queue addQ(Queue q, Element e)
{
	if(q->head == NULL)
	{
		q->head = e;
		q->tail = e;
		e->next = NULL;
		return q;
	}
	else
	{
		q->tail->next = e;
		q->tail = e;
		e->next = NULL;
		return q;
	}
}


int lengthQ(Queue q)
{
	Element temp = q->head;
	int i=0;
	while(temp!=NULL)
	{
		i++;
		temp=temp->next;
	}
	return i;
}

Element newEle(int p, int id)
{
	Element e = (Element)malloc(sizeof(struct element));
	e->priority=p;
	e->tid=id;
}



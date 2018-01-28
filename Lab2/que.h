#include <stdio.h>
#include <stdlib.h>

typedef struct queue * Queue;
typedef struct element * Element;

typedef enum {
  false = 0,
  true = 1
} Boolean;

struct queue
{
	struct element * head;
	struct element * tail;
};

struct element
{
	int priority;
	int tid;
	struct element * next;
};

Queue newQ();
Boolean isEmptyQ(Queue q);
Queue delQ(Queue q);
Element front(Queue q);
Queue addQ(Queue q , Element e);
int lengthQ(Queue q);

Element newEle (int p, int id);
void printQ(Queue q);

struct Element
{
	int key;
	struct Element* next;
};

struct SeqList
{
	struct Element* head;
	struct Element* tail;
	int count;
};



struct SeqList* newList(); // creates an empty list
struct SeqList* insertInOrder(struct SeqList* sl, struct Element* e); // add e to sl in order of key assuming sl is ordered; return the modified list
struct SeqList* insertAtFront(struct SeqList* sl, struct Element* e); // add e at the front of the list; return the modified list
struct SeqList* insertAtEnd(struct SeqList* sl, struct Element* e); // add e at the end of the list; return the modified list
struct SeqList* delete(struct SeqList* sl, struct Element* e); // delete e from sl; return the modified list
struct SeqList* deleteAtFront(struct SeqList* sl); // delete the first element from sl; return the modified list
struct Element* find(struct SeqList* sl, int k); // find the element e with key k in sl; return e
struct SeqList* merge(struct SeqList* a, struct SeqList* b);
struct SeqList* insertionSort(struct SeqList* sl);
struct SeqList* sort (struct SeqList* sl);

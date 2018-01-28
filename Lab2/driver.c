#include "que.h"



int main()
{
    Queue q = newQ();
    addQ(q,newEle(1,1));
    addQ(q,newEle(2,2));
    addQ(q,newEle(3,3));
    addQ(q,newEle(4,4));
    printQ(q);
    delQ(q);
    printQ(q);
    printf("%d", lengthQ(q));
}




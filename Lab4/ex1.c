#include <stdio.h>
#include <stdlib.h>
#include "info.h"

CreditCard readfn()
{
	int i=0;
	FILE* fp;
	fp = fopen("100.txt","r");
	int count=10;
	CreditCard cc = (CreditCard)malloc(sizeof(struct creditcard)*count);
	while(fscanf(fp,"\"%lu,%[^,],%[^,],%[^,],%[^\"]\"\n", &(cc+i)->cardno, (cc+i)->bankcode, (cc+i)->exp, (cc+i)->firstname, (cc+i)->lastname)!=EOF)
	{
		i++;
		if(i>=count)
		{
			count+=10;
			cc = (CreditCard)realloc(cc, sizeof(struct creditcard)*count);
		}
	}
	fclose(fp);
	return cc;
}

void print(CreditCard arr, int size)
{
	for(int i=0; i<size; i++)
	{
		printf("\n%lu", arr[i].cardno);
	}
}



/*
int main()
{
	CreditCard cc = readfn();
	
	
}
*/

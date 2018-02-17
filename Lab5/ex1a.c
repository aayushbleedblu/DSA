#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex1.h"

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[])
{
	int i=0,j=0,k=0;
	while(i<sz1 && j<sz2)
	{
		if(Ls1[i].cgpa<Ls2[j].cgpa)
		{
			Ls[k]=Ls1[i];
			k++;
			i++;
		}
		else if(Ls1[i].cgpa>Ls2[j].cgpa)
		{
			Ls[k]=Ls2[j];
			k++;
			j++;
		}
	}
	if(i==sz1)
	{
		while(j<sz2)
		{
			Ls[k]=Ls2[j];
			k++;
			j++;
		}
	}
	else if(j==sz2)
	{
		while(i<sz1)
		{
			Ls[k]=Ls1[i];
			k++;
			i++;
		}
	}	
}

Element newEle(char nm[], float cg)
{
	Element* e = (Element*)malloc(sizeof(Element));
	e->cgpa=cg;
	strcpy(e->name,nm);
	return *e;
}

void print(Element l[], int size)
{
	for(int i=0; i<size; i++)
		printf("\n%s %f", l[i].name, l[i].cgpa);
	printf("\n");
}
/*
int main()
{
	Element Ls1 = (Element)malloc(sizeof(struct Element)*2);
	Element Ls2 = (Element)malloc(sizeof(struct Element)*2);
	Element Ls = (Element)malloc(sizeof(struct Element)*4);
	Ls1[0] = newEle("abcdefghij",1);
	Ls1[1] = newEle("klmnopqrst",4);
	Ls2[0] = newEle("asdfghjklm",2);
	Ls2[1] = newEle("qwertyuiop",3);
	merge(Ls1, 2, Ls2, 2, Ls);
	print(Ls, 4);
	
}
*/


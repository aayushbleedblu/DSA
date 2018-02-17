#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex1.h"

void mergeSortRec(Element Ls[], int low, int high)
{
	if(low<high)
	{
		int mid = (low+high)/2;
		mergeSortRec(Ls, low, mid);
		mergeSortRec(Ls, mid+1, high);
		Element* temp = (Element*)malloc(sizeof(Element)*(high-low+1));
		merge(Ls+low, mid-low+1, Ls+mid+1, high-mid, temp);
		for(int i=0; i<high-low+1;i++)
		{
			Ls[i+low]=temp[i];
		}
		free(temp);
	}
	return ;
}


void mergeSortIter(Element Ls[], int low, int high)
{
	for(int i=2; i<=high+1 ; i*=2)
	{
		Element* temp=(Element*)malloc(sizeof(Element)*i);
		for(int j=0; j<(high+1)/i; j++)
		{
			merge(Ls+j*i , i/2 , Ls+j*i+i/2 , i/2 , temp);
			for(int k=0; k<i ; k++)
			{
				Ls[i*j+k]=temp[k];
			}
		}
		free(temp);
	}
}


int main()
{
	Element* Ls = (Element*)malloc(sizeof(Element)*4);
	Ls[0] = newEle("abcdefghij",4);
	Ls[1] = newEle("klmnopqrst",1);
	Ls[2] = newEle("asdfghjklm",3);
	Ls[3] = newEle("qwertyuiop",2);
	mergeSortIter(Ls, 0, 3);
	print(Ls, 4);
}



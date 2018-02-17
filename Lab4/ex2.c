#include <stdio.h>
#include <stdlib.h>
#include "info.h"

CreditCard insertInOrder(CreditCard arr, int size, struct creditcard c)
{
	int i=0;
	struct creditcard temp1 = c;
	struct creditcard temp2 = c;
	while(i<size)
	{
		if(arr[i].cardno>=temp1.cardno)
		{
			temp2=arr[i];
			arr[i]=temp1;
			temp1=temp2;
		}
		i++;
	}
	arr[i]=temp1;
	return arr;
}

CreditCard insertionSort(CreditCard arr, int size)
{
	int a;
	if (size>1)
	{	
		arr = insertionSort(arr, size-1);
		arr = insertInOrder(arr, size-1, arr[size-1]);
	}
	else { printf("%p", &a);}
	return arr;
}

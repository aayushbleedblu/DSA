#include <stdio.h>
#include <stdlib.h>
#include "info.h"

int main()
{
	int a;
	CreditCard arr = readfn();
	print(arr, 100);
	printf("\n\n");
	arr=insertionSort(arr,100);
	printf("\n%p\n", &a);
	print(arr,100);
	

}

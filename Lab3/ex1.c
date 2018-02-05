#include <stdio.h>
#include <stdlib.h>

int bits;

void p(int n)
{
	printf("%u\n", &n);
	p(n+1);
}

void g()
{
	int goa;
	printf("%u\n", &goa);
}

void h()
{
	int hyd;
	printf("%u\n", &hyd);
}

void d()
{
	int dub;
	printf("%u\n", &dub);
}



int main()
{
	p(10);
	return 0;
}

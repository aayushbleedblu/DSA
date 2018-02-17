//typedef struct element* Element;
typedef struct
{
	char name[11];
	float cgpa;	
}Element;

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]);
void print(Element l[], int size);
Element newEle(char nm[], float cg);



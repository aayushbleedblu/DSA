typedef struct creditcard* CreditCard;
struct creditcard
{
	unsigned long cardno;
	char bankcode[10];
	char exp[8];
	char firstname[15];
	char lastname[15];
};

CreditCard readfn();
void print(CreditCard arr, int size);
CreditCard insertInOrder(CreditCard arr, int size, struct creditcard c);
CreditCard insertionSort(CreditCard arr, int size);

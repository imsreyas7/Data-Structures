typedef struct{
		int size;
		int *a;
		int cur_size;
}NumberADT;

void initADT(NumberADT *N, int size);
void insertElements(NumberADT *N, int *a);
int linearSearch(NumberADT *N, int x);
int binarySearch(NumberADT *N, int x);
void selectionSort(NumberADT *N);
void display(NumberADT *N);
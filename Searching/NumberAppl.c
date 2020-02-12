#include<stdio.h>
#include<stdlib.h>
#include "NumberIF.h"
#include "NumberImpl.h"

void main(){
	int opt=1;
	NumberADT *N=(NumberADT *)malloc(sizeof(NumberADT));
	int size;
	printf("\nEnter Size of the Array ADT:  ");
	scanf("%d",&size);
	initADT(N,size);
	int *arr,ins_size=size,x,res;


	while(opt!=0){
		printf("\n\n\t\tNUMBER MANIPULATION APPLICATION\n");
		printf("\nEnter A Choice:\n\t1 to Insert Elements\n\t2 to Display Elements\n\t3 to Search Linearly\n\t4 to Search Binarily\n\t0 to Quit\n\tYour Choice -> ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("\nEnter the No. of Elements you wish to enter: ");
				scanf("%d",&ins_size);
				arr=(int *)malloc(sizeof(int)*ins_size);
				if(ins_size>size)
					printf("\nThe size exceeds ADT size. Enter size less than %d.",N->size);
				else{
					printf("\nEnter the elements: ");
					x=0;
					while(x<ins_size)
						scanf("%d",&arr[x++]);
			
					insertElements(N,arr);
					printf("\nThe entered elements have been successfully overwritten/copied into the array!");
				}
				break;
			case 2:
					display(N);
					break;
			case 3:
					printf("\nEnter an element to search for: ");
					scanf("%d",&x);
					res=linearSearch(N,x);
					if(res!=-1)
						printf("\nElement %d was found at Index %d.",x,res);
					else
						printf("\nElement %d was not found.",x);
					break;
			case 4:
					printf("\nEnter an element to search for: ");
					scanf("%d",&x);
					res=binarySearch(N,x);
					if(res!=-1)
						printf("\nElement %d was found at Index %d.",x,res);
					else
						printf("\nElement %d was not found.",x);
					break;
			case 0:
				printf("\n\t\tThank You!");
				break;
			default:
				printf("\n\tInvalid Option!");
				break;
		}
	}
}

/*
OUTPUT:
vishakan@legion:~/Desktop/Semester III/Lab/Data Structures/Searching$ gcc NumberAppl.c -o n
vishakan@legion:~/Desktop/Semester III/Lab/Data Structures/Searching$ ./n

Enter Size of the Array ADT:  20


		NUMBER MANIPULATION APPLICATION

Enter A Choice:
	1 to Insert Elements
	2 to Display Elements
	3 to Search Linearly
	4 to Search Binarily
	0 to Quit
	Your Choice -> 1

Enter the No. of Elements you wish to enter: 15

Enter the elements: 1 13 7 18 29 22 10 39 28 48 29 10 23 42 13   

The entered elements have been successfully overwritten/copied into the array!

		NUMBER MANIPULATION APPLICATION

Enter A Choice:
	1 to Insert Elements
	2 to Display Elements
	3 to Search Linearly
	4 to Search Binarily
	0 to Quit
	Your Choice -> 2


Elements of the Array:
1	13	7	18	29	22	10	39	28	48	29	10	23	42	13	

		NUMBER MANIPULATION APPLICATION

Enter A Choice:
	1 to Insert Elements
	2 to Display Elements
	3 to Search Linearly
	4 to Search Binarily
	0 to Quit
	Your Choice -> 3

Enter an element to search for: 29

Element 29 was found at Index 4.

		NUMBER MANIPULATION APPLICATION

Enter A Choice:
	1 to Insert Elements
	2 to Display Elements
	3 to Search Linearly
	4 to Search Binarily
	0 to Quit
	Your Choice -> 4

Enter an element to search for: 28

Element 28 was found at Index 9.

		NUMBER MANIPULATION APPLICATION

Enter A Choice:
	1 to Insert Elements
	2 to Display Elements
	3 to Search Linearly
	4 to Search Binarily
	0 to Quit
	Your Choice -> 4

Enter an element to search for: 0

Element 0 was not found.

		NUMBER MANIPULATION APPLICATION

Enter A Choice:
	1 to Insert Elements
	2 to Display Elements
	3 to Search Linearly
	4 to Search Binarily
	0 to Quit
	Your Choice -> 3

Enter an element to search for: -1

Element -1 was not found.

		NUMBER MANIPULATION APPLICATION

Enter A Choice:
	1 to Insert Elements
	2 to Display Elements
	3 to Search Linearly
	4 to Search Binarily
	0 to Quit
	Your Choice -> 0

		Thank You!
*/
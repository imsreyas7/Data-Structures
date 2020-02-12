#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define COUNT 10
#include"AVLimpl.h"

void main()
{
	data w;
	dict *d=NULL;
	dict *d1;
	int opt;
	char w1[80];
	
	do
	{
		printf("\nMENU \n1.INSERT \n2.SEARCH \n3.DISPLAY \n4.EXIT");
		printf("\nEnter option : ");
		scanf("%d",&opt);
 		switch(opt)
		{
			case 1:
					printf("Word: ");
					scanf(" %[^\n]",w.word);
					printf("Enter the meaning \n");
					scanf(" %[^\n]",w.meaning);					
					d=insert(d,w);
					break;
		
			case 2:
					printf("Word ");
					scanf(" %[^\n]",w1);
					d1=search(d,w1);
					printf(" The meaning is %s",d1->x.meaning);
					break;
			case 3:
					dispTree(d,0);
					break;
			case 4:	
					printf("Exiting. \n");
					break;
		}
	}
	while(opt!=4);
}
					
	

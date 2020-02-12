#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define COUNT 10
#include"Playerimpl.h"

void main()
{
	Player *P=initialize();
	int ch;
	char name[80];
	do{
		printf("\nMenu:\n1.Insert\n2.Delete\n3.Display\n4.exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			  	printf("Enter the name: ");
			  	scanf(" %[^\n]",name);
			  	insert(P,name);
			  	break;
			case 2:
			  	printf("Enter the name: ");
			  	scanf(" %[^\n]",name);
			  	Delete(P,name);
			  	break;
			case 3:
			  	dispTree(P,0);
			  	break;	
			
		}
				
				
	}while(ch!=4);
	inorder(P);
		postorder(P);
		preorder(P);
}

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include "ExpStack.h"
#include "TreeStack.h"
#include "TreeImpl.h"

typedef struct{
	char *infix,*postfix;
	int value;
	Stack s;
	TreeStack *ts;
}ExpADT;

void main(){
	ExpADT e;
	initStack(&e.s,100);
	struct Tree *t;
	t=(struct Tree *)malloc(sizeof(struct Tree));
	char ask;

	e.infix=(char *)malloc(sizeof(char)*100);
	e.postfix=(char *)malloc(sizeof(char)*100);

	printf("\n\t\t\tINFIX TO POSTFIX CONVERSION\n");
	while(1){
		printf("\nEnter an INFIX expression: ");
		scanf("%s",e.infix);
		e.postfix=infixtoPostfix(e.infix,&e.s);
		printf("\nThe POSTFIX expression is: %s\n",e.postfix);
		
		initStackT(e.ts,strlen(e.postfix));
		t=expressionTree(e.ts,e.postfix);
		printf("\nThe Tree Structure is:");
		dispTree(t,0);
		
		e.value=evaluateExpTree(t);
		printf("\n\nThe value of the POSTFIX expression is: %d\n",e.value);
		askpos:
		printf("\nDo you wish to continue? (Y/N) : ");
		scanf(" %c",&ask);
		if(ask=='Y'||ask=='y')
			continue;
		else if(ask=='N'||ask=='n'){
			printf("\nThank You!");
			break;
		}
		else{
			printf("\nInvalid Option!");
			goto askpos;
		}
	}

}

/*
OUTPUT:

vishakan@legion:~/Desktop/Semester III/Lab/Data Structures/Expression Tree$ gcc TreeApp.c -o t -lm
vishakan@legion:~/Desktop/Semester III/Lab/Data Structures/Expression Tree$ ./t

			INFIX TO POSTFIX CONVERSION

Enter an INFIX expression: 4+2*8+1

The POSTFIX expression is: 428*+1+

The Tree Structure is:
+
  ->+
    ->4
    ->*
      ->2
      ->8
  ->1

The value of the POSTFIX expression is: 21


Do you wish to continue? (Y/N) : N

*/

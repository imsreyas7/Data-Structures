/*MAIN FUNCTION FOR POLYNOMIAL LIST ADT PROGRAM*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "PolyADTIF.h"
#include "PolyADTImpl.h"



void main(){
	
	printf("\n\t\tAPPLICATION OF LINKED LIST- POLYNOMIAL MANIPULATION");
	
	MainMenu();
}

void Insertion(int iopt,struct poly *p1){
	int e,c,ee,ec,flag;
				while(iopt!=0){
					printf("\n\n\t\t\tEnter Option:");
					printf("\n\t\t1 Insert At Front\n\t\t2 Insert At End\n\t\t3 Insert After a Term\n\t\t0 No Insertion\n\n");
					scanf("%d",&iopt);
					switch(iopt){
						case 1:
							printf("\nEnter the co-efficient: ");
							scanf("%d",&c);
							printf("\nEnter the exponent: ");
							scanf("%d",&e);
							insertFront(p1,c,e);
							printf("\nInsertion Succesful.");
							break;
						case 2:
							printf("\nEnter the co-efficient: ");
							scanf("%d",&c);
							printf("\nEnter the exponent: ");
							scanf("%d",&e);
							insertEnd(p1,c,e);
							printf("\nInsertion Succesful.");
							break;
						case 3:
							printf("\nEnter the co-efficient: ");
							scanf("%d",&c);
							printf("\nEnter the exponent: ");
							scanf("%d",&e);
							printf("\nEnter the co-efficient of existing term: ");
							scanf("%d",&ec);
							printf("\nEnter the exponent of existing term: ");
							scanf("%d",&ee);
							flag=insertAfterTerm(p1,c,e,ec,ee);
							if(flag)
								printf("\nInsertion Succesful.");
							break;
						case 0:
							break;
						default:
							printf("\nInvalid Input.Try Again.");

					}
				}
}

void MainMenu(){
	struct poly *p1, *p2, *add, *mul;
	int opt=1,iopt=1;
	int x;
	while(opt!=0){
		printf("\n\n\t\t\tMENU\n\n\t1 Initialise Polynomial\n\t2 Insert into Polynomial\n\t3 To Display Polynomial\n\t4 Find Degree\n\t5 Evaluate Polynomial Expression\n\t6 Simplify Polynomial\n\t7 Addition\n\t8 Multiplication\n\t0 Exit\n\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				p1=initPoly();
				printf("\nInitialisation done");
				break;

			case 2:
				Insertion(iopt,p1);
				break;

			case 3:
				showPoly(p1);
				break;

			case 4:
				printf("\n\nPolynomial is: ");
				showPoly(p1);
				polyDegree(p1);
				break;

			case 5:
				printf("\nEnter a value for x to evaluate: ");
				scanf("%d",&x);
				printf("\n\nPolynomial is: ");
				showPoly(p1);
				evaluatePoly(p1,x);
				break;

			case 6:
				simplifyPoly(p1);
				printf("\n\nPolynomial is: ");
				showPoly(p1);
				break;
			case 7:
				iopt=1;
				p2=initPoly();
				add=initPoly();
				printf("\nEnter values to second polynomial to continue.");
				Insertion(iopt,p2);
				add=addPoly(p1,p2);
				printf("\n\nPolynomial 1 is: ");
				showPoly(p1);
				printf("\n\nPolynomial 2 is: ");
				showPoly(p2);
				printf("\n\nThe result is: ");
				showPoly(add);
				break;
			case 8:
				iopt=1;
				p2=initPoly();
				mul=initPoly();
				printf("\nEnter values to second polynomial to continue.");
				Insertion(iopt,p2);
				mul=multiplyPoly(p1,p2);
				printf("\n\nPolynomial 1 is: ");
				showPoly(p1);
				printf("\n\nPolynomial 2 is: ");
				showPoly(p2);
				printf("\n\nThe result is: ");
				showPoly(mul);
				break;

			case 0:
				break;

			default:
				printf("\nInvalid Input.Try Again.");

		}
	}
}


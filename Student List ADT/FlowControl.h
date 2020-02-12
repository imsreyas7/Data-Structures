#include "StudentListADTImpl.h"

void flowControl(ListADT *l, char choice){
	int regnum;
	int ch;
	Student S;
	
	switch(choice)	{
			case 1 :{
				S=getInput(l);
				printf("\nInsert Student at \n\t1       - Front \n\t2       - Rear \n\t3       - AfterRegNo \n\tdefault - Rear\n\nEnter your choice : ");
				scanf("%d",&ch);
				
				switch(ch) {
					case 1:insertFront(l,S); break;
					case 2:insertBack(l,S); break;
					case 3:{
						printf("Enter student regno after which record is to be inserted : ");
						scanf("%d",&regnum);
						insertRegno(l,S,regnum);
						break;
					}
					default:insertFront(l,S); break;
				} 
				break;
			}
			case 2 :{
				printf("Enter Student regno to be deleted : "); 
				scanf("%d",&regnum); 
				delete(l,regnum);
				break;
			} 
			case 3 :{
				printf("\nDisplay Student records of \n\t1       - Passed \n\t2       - FirstClass \n\t3       - All\n\tdefault - All\n\nEnter your choice : ");
				scanf("%d",&ch);
				computeResult(l);
				switch(ch) {
					case 1:dispALL(listResult(*l)); break;
					case 2:printf("\nThe no. of students who got fist class : %d\n",listClass(*l)); break;
					default :dispALL(*l); break;
				}
				break;
			}
			case 4 :{
				computeResult(l);
				printf("\nSearch Student records based on \n\t1       - Name \n\t2       - RegNo \n\tdefault - RegNo\n\nEnter your choice : ");
				scanf("%d",&ch);
				
				switch(ch){
					case 2 :{
						printf("Enter RegNo to be searched : ");
						scanf("%d",&regnum);
						S = searchRegNo(*l,regnum);
						if(S.RegNo == -1)
							printf("Student not found !!!\n");
						else{
							printf("\n---------------------------------------------------------------------\n");
							printf("%5s %-20s %-8s %-8s %-8s %-8s %s\n","RegNo","Name","DPST","JAVA","MATH","Total","Result");
							printf("---------------------------------------------------------------------\n");	
		
							display(S);
							printf("---------------------------------------------------------------------\n");
						}
						break;
					}
					default :{
						char a[50];
						scanf("%c",&a[0]);
						printf("Enter Name to be searched : ");
						scanf(" %[^\n]",a);
						dispALL(searchName(*l,a));
						break;
					}
			}
		}
	}
}

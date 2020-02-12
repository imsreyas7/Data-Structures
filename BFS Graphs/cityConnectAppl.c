#include "cityConnectImpl.h"

int main() {
	int MapCapacity,choice;
	char source[100],destination[100];
	printf("Enter the number of cities to be included : ");
	scanf("%d",&MapCapacity);
	cityADT *c = (cityADT*)malloc(sizeof(cityADT));
	c = init(c,MapCapacity);
	

	do {
		
		printf("\nMENU\n\t1 - Add Road\n\t2 - Display Connections \n\t3 - BFS traversal\n\t0 - Exit\n\nEnter your choice : ");
		scanf("%d",&choice);
	
		
		switch(choice) {
			case 1 : {
				printf("\nEnter Road pts : ");
				printf("\n\tPOINT A : ");
				scanf("%s",source);
				printf("\tPOINT B : ");
				scanf("%s",destination);
				create(c,source,destination);
				break;
			}

			case 2 : {
				dispCity(c);
				printf("\n");
				break;
			}

			case 3 : {
				printf("BFS Traversal produces : ");
				makeZero();
				BFS(c);
				printf("\n\n");
			}
		}
	}while(choice);

	
	return 0;
}

/*
OUTPUT


C:\Users\sreyas\Desktop\labs\datastructures\bfs\BFS\BFS-CityConnect>a
                       

Enter the number of cities to be included : 4

MENU
        1 - Add Road
        2 - Display Connections
        3 - BFS traversal
        0 - Exit

Enter your choice : 1

Enter Road pts :
        POINT A : chennai
        POINT B : pune
Connected chennai & pune

MENU
        1 - Add Road
        2 - Display Connections
        3 - BFS traversal
        0 - Exit

Enter your choice : 1

Enter Road pts :
        POINT A : chennai
        POINT B : trichy
Connected chennai & trichy

MENU
        1 - Add Road
        2 - Display Connections
        3 - BFS traversal
        0 - Exit

Enter your choice : 2
chennai    connects -> | chennai     | pune        | trichy      |
pune       connects -> | chennai     | pune        |
trichy     connects -> | chennai     | trichy      |


MENU
        1 - Add Road
        2 - Display Connections
        3 - BFS traversal
        0 - Exit

Enter your choice : 1

Enter Road pts :
        POINT A : pune
        POINT B : mumbai
Connected pune & mumbai

MENU
        1 - Add Road
        2 - Display Connections
        3 - BFS traversal
        0 - Exit

Enter your choice : 2
chennai    connects -> | chennai     | pune        | trichy      |
pune       connects -> | chennai     | pune        | mumbai      |
trichy     connects -> | chennai     | trichy      |
mumbai     connects -> | pune        | mumbai      |


MENU
        1 - Add Road
        2 - Display Connections
        3 - BFS traversal
        0 - Exit

Enter your choice : 3
BFS Traversal produces :  chennai  pune  trichy  mumbai


MENU
        1 - Add Road
        2 - Display Connections
        3 - BFS traversal
        0 - Exit

Enter your choice : 0
*/
#include "DFSimpl.h"

int main() {
	int MapCapacity,choice;
	char source[100],destination[100];
	printf("\t\t\tDFS CITY CONNECTOR\n\n");
	printf("Enter (upper_bound) no. of cities to be included : ");
	scanf("%d",&MapCapacity);
	cityADT *c = (cityADT*)malloc(sizeof(cityADT));
	c = init(c,MapCapacity);
	

	do {
		printf("\n----------------------------------\n");
		printf("\nMENU\n\t1 - Add Road\n\t2 - Display Connections \n\t3 - DFS traversal\n\t4 - Path?\n\t0 - Exit\n\nEnter your choice : ");
		scanf("%d",&choice);
		printf("\n----------------------------------\n");
		
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
				printf("\nDFS Traversal produces : ");
				DFS(c);
				printf("\n\n");
				break;
			}
			
			case 4 : {
				printf("\nEnter Road pts : ");
				printf("\n\tPOINT A : ");
				scanf("%s",source);
				printf("\tPOINT B : ");
				scanf("%s",destination);
				makeZero();
				printPath(c,source,destination,0);
			}
		}
	}while(choice);

	printf("\n----------------------------------\n");
	printf("\n\t\t\tTHANK YOU !!!\n");
	printf("\n----------------------------------\n");
	return 0;
}

/*
OUTPUT

C:\Users\sreya\Desktop\labs\datastructures\dfs>gcc DFSappl.c -o m

C:\Users\sreya\Desktop\labs\datastructures\dfs>m
                        DFS CITY CONNECTOR

Enter (upper_bound) no. of cities to be included : 4

----------------------------------

MENU
        1 - Add Road
        2 - Display Connections
        3 - DFS traversal
        4 - Path?
        0 - Exit

Enter your choice : 1

----------------------------------

Enter Road pts :
        POINT A : chennai
        POINT B : coimbatore
chennai and coimbatore are connected.
----------------------------------

MENU
        1 - Add Road
        2 - Display Connections
        3 - DFS traversal
        4 - Path?
        0 - Exit

Enter your choice : 1

----------------------------------

Enter Road pts :
        POINT A : chennai
        POINT B : trichy
chennai and trichy are connected.
----------------------------------

MENU
        1 - Add Road
        2 - Display Connections
        3 - DFS traversal
        4 - Path?
        0 - Exit

Enter your choice : 1

----------------------------------

Enter Road pts :
        POINT A : ooty
        POINT B : coimbatore
ooty and coimbatore are connected.
----------------------------------

MENU
        1 - Add Road
        2 - Display Connections
        3 - DFS traversal
        4 - Path?
        0 - Exit

Enter your choice : 2

----------------------------------
chennai    connects -> | chennai     | coimbatore  | trichy      |
coimbatore connects -> | chennai     | coimbatore  |
trichy     connects -> | chennai     | trichy      |
ooty       connects -> | coimbatore  |


----------------------------------

MENU
        1 - Add Road
        2 - Display Connections
        3 - DFS traversal
        4 - Path?
        0 - Exit

Enter your choice : 3

----------------------------------

DFS Traversal produces : chennai coimbatore ooty trichy


----------------------------------

MENU
        1 - Add Road
        2 - Display Connections
        3 - DFS traversal
        4 - Path?
        0 - Exit

Enter your choice : 4

----------------------------------

Enter Road pts :
        POINT A : chennai
        POINT B : ooty
 chennai -> coimbatore ->
----------------------------------

*/
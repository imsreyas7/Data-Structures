#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "SPAIF.h"
#include "SPAImpl.h"


void main(){

	int cap,choice=4;
	char start[100],dest[100];
	cityADT *c;
	c=(cityADT*)malloc(sizeof(cityADT));

	printf("\n\t\tDjikstra's Shortest Path Algorithm");

	while(choice!=0){
		printf("\n\n\t\tMAIN MENU\n\t1 - Add A Connection\n\t2 - Display All Existing Connections\n\t3 - Shortest Path Finder\n\t4 - Initialise Map\n\t0 - Exit\n\n\tEnter your choice -> ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1 :
				printf("\nEnter the City Names: ");
				printf("\n\tStarting Point: ");
				scanf("%s",start);
				printf("\tDestination Point: ");
				scanf("%s",dest);
				create(c,start,dest);
				break;

			case 2 :
				display(c);
				break;

			case 3 :
				printf("\nEnter the Starting City: ");
				scanf("%s",start);
				printf("\nEnter the Destination City: ");
				scanf("%s",dest);
				PathFinder(c,start,dest);
				break;

			case 4:
				printf("\nEnter the Total No. Of Cities in the Map : ");
				scanf("%d",&cap);
				c = initADT(c,cap);
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
vishakan@legion:~/Desktop/Semester III/Lab/Data Structures/Graphs/Djikstra$ gcc SPAApp.c -o s
vishakan@legion:~/Desktop/Semester III/Lab/Data Structures/Graphs/Djikstra$ ./s

		Djikstra's Shortest Path Algorithm

		MAIN MENU
	1 - Add A Connection
	2 - Display All Existing Connections
	3 - Shortest Path Finder
	4 - Initialise Map
	0 - Exit

	Enter your choice -> 4

Enter the Total No. Of Cities in the Map : 4


		MAIN MENU
	1 - Add A Connection
	2 - Display All Existing Connections
	3 - Shortest Path Finder
	4 - Initialise Map
	0 - Exit

	Enter your choice -> 1

Enter the City Names: 
	Starting Point: A
	Destination Point: B

Enter cost to go from A to B: 2

A is now connected with B with cost 2.

		MAIN MENU
	1 - Add A Connection
	2 - Display All Existing Connections
	3 - Shortest Path Finder
	4 - Initialise Map
	0 - Exit

	Enter your choice -> 1

Enter the City Names: 
	Starting Point: A
	Destination Point: C

Enter cost to go from A to C: 8

A is now connected with C with cost 8.

		MAIN MENU
	1 - Add A Connection
	2 - Display All Existing Connections
	3 - Shortest Path Finder
	4 - Initialise Map
	0 - Exit

	Enter your choice -> 1

Enter the City Names: 
	Starting Point: B
	Destination Point: C

Enter cost to go from B to C: 2

B is now connected with C with cost 2.

		MAIN MENU
	1 - Add A Connection
	2 - Display All Existing Connections
	3 - Shortest Path Finder
	4 - Initialise Map
	0 - Exit

	Enter your choice -> 1

Enter the City Names: 
	Starting Point: E
	Destination Point: A

Enter cost to go from E to A: 3

E is now connected with A with cost 3.

		MAIN MENU
	1 - Add A Connection
	2 - Display All Existing Connections
	3 - Shortest Path Finder
	4 - Initialise Map
	0 - Exit

	Enter your choice -> 2

A is connected to:
  B  C
B is connected to:
  C
C is connected to:

E is connected to:
  A

		MAIN MENU
	1 - Add A Connection
	2 - Display All Existing Connections
	3 - Shortest Path Finder
	4 - Initialise Map
	0 - Exit

	Enter your choice -> 3

Enter the Starting City: A

Enter the Destination City: C


Vertex	Known	Distance	Path

A	1	0		0
B	1	2		A
C	1	4		B
E	1	∞		0
Shortest Path exists between A and C with cost 4.
Shortest Path:
	A--->B--->C

		MAIN MENU
	1 - Add A Connection
	2 - Display All Existing Connections
	3 - Shortest Path Finder
	4 - Initialise Map
	0 - Exit

	Enter your choice -> 3

Enter the Starting City: E

Enter the Destination City: C


Vertex	Known	Distance	Path

A	1	3		E
B	1	5		A
C	1	7		B
E	1	0		0
Shortest Path exists between E and C with cost 7.
Shortest Path:
	E--->A--->B--->C

		MAIN MENU
	1 - Add A Connection
	2 - Display All Existing Connections
	3 - Shortest Path Finder
	4 - Initialise Map
	0 - Exit

	Enter your choice -> 3

Enter the Starting City: C

Enter the Destination City: E


Vertex	Known	Distance	Path

A	1	∞		0
B	1	∞		0
C	1	0		0
E	1	∞		0
Path does not exist between C and E

		MAIN MENU
	1 - Add A Connection
	2 - Display All Existing Connections
	3 - Shortest Path Finder
	4 - Initialise Map
	0 - Exit

	Enter your choice -> 0

		Thank You!

*/

#include<stdio.h>
#include<string.h>
#include "FlowControl.h"

void main() {
	ListADT l;
	initialize(&l);
	
	int choice;
	
	do{
		printf("************************************************************************\n");
		printf("MENU -\n\t1 - ADD A RECORD\n\t2 - DELETE A RECORD\n\t3 - DISPLAY RECORDS\n\t4 - SEARCH FOR RECORD\n\t0 - EXIT\n\nEnter your choice : ");
		scanf("%d",&choice);
		
		flowControl(&l,choice);
				
	}while(choice);
	printf("************************************************************************\n");
}

/*
C:\Users\sreyas\Desktop>gcc StudentListADTAppl.c -o x

C:\Users\sreyas\Desktop>x
************************************************************************
MENU -
        1 - ADD A RECORD
        2 - DELETE A RECORD
        3 - DISPLAY RECORDS
        4 - SEARCH FOR RECORD
        0 - EXIT

Enter your choice : 1
Enter Student Details :-
----------------------------
        Register Number : 123
        Name of student : Kiran
        Marks -
                Data Structures and Algorithms  : 88
                UNIX and Shell programming  : 92
                Discrete Mathematics  : 84

Insert Student at
        1       - Front
        2       - Rear
        3       - AfterRegNo
        default - Rear

Enter your choice : 1
************************************************************************
MENU -
        1 - ADD A RECORD
        2 - DELETE A RECORD
        3 - DISPLAY RECORDS
        4 - SEARCH FOR RECORD
        0 - EXIT

Enter your choice : 1
Enter Student Details :-
----------------------------
        Register Number : 134
        Name of student : Prakash
        Marks -
                Data Structures and Algorithms  : 98
                UNIX and Shell programming  : 95
                Discrete Mathematics  : 100

Insert Student at
        1       - Front
        2       - Rear
        3       - AfterRegNo
        default - Rear

Enter your choice : 2
************************************************************************
MENU -
        1 - ADD A RECORD
        2 - DELETE A RECORD
        3 - DISPLAY RECORDS
        4 - SEARCH FOR RECORD
        0 - EXIT

Enter your choice : 3

Display Student records of
        1       - Passed
        2       - FirstClass
        3       - All
        default - All

Enter your choice : 3

---------------------------------------------------------------------
RegNo Name                 DSA      UNIX     MATH     Total    Result
---------------------------------------------------------------------
  123 Kiran                   88.00    92.00    84.00   264.00   P
  134 Prakash                 98.00    95.00   100.00   293.00   P
---------------------------------------------------------------------
************************************************************************
MENU -
        1 - ADD A RECORD
        2 - DELETE A RECORD
        3 - DISPLAY RECORDS
        4 - SEARCH FOR RECORD
        0 - EXIT

Enter your choice : 1
Enter Student Details :-
----------------------------
        Register Number : 166
        Name of student : David
        Marks -
                Data Structures and Algorithms  : 100
                UNIX and Shell programming  : 98
                Discrete Mathematics  : 98

Insert Student at
        1       - Front
        2       - Rear
        3       - AfterRegNo
        default - Rear

Enter your choice : 1
************************************************************************
MENU -
        1 - ADD A RECORD
        2 - DELETE A RECORD
        3 - DISPLAY RECORDS
        4 - SEARCH FOR RECORD
        0 - EXIT

Enter your choice : 3

Display Student records of
        1       - Passed
        2       - FirstClass
        3       - All
        default - All

Enter your choice : 2

---------------------------------------------------------------------
RegNo Name                 DSA      UNIX     MATH     Total    Result
---------------------------------------------------------------------
  166 David                  100.00    98.00    98.00   296.00   P
  123 Kiran                   88.00    92.00    84.00   264.00   P
  134 Prakash                 98.00    95.00   100.00   293.00   P
---------------------------------------------------------------------

The no. of students who got fist class : 3
************************************************************************
MENU -
        1 - ADD A RECORD
        2 - DELETE A RECORD
        3 - DISPLAY RECORDS
        4 - SEARCH FOR RECORD
        0 - EXIT

Enter your choice : 1
Enter Student Details :-
----------------------------
        Register Number : 178
        Name of student : Varun
        Marks -
                Data Structures and Algorithms  : 56
                UNIX and Shell programming  : 72
                Discrete Mathematics  : 63

Insert Student at
        1       - Front
        2       - Rear
        3       - AfterRegNo
        default - Rear

Enter your choice : 2
************************************************************************
MENU -
        1 - ADD A RECORD
        2 - DELETE A RECORD
        3 - DISPLAY RECORDS
        4 - SEARCH FOR RECORD
        0 - EXIT

Enter your choice : 3

Display Student records of
        1       - Passed
        2       - FirstClass
        3       - All
        default - All

Enter your choice : 3

---------------------------------------------------------------------
RegNo Name                 DSA      UNIX     MATH     Total    Result
---------------------------------------------------------------------
  166 David                  100.00    98.00    98.00   296.00   P
  123 Kiran                   88.00    92.00    84.00   264.00   P
  134 Prakash                 98.00    95.00   100.00   293.00   P
  178 Varun                   56.00    72.00    63.00   191.00   P
---------------------------------------------------------------------
************************************************************************
MENU -
        1 - ADD A RECORD
        2 - DELETE A RECORD
        3 - DISPLAY RECORDS
        4 - SEARCH FOR RECORD
        0 - EXIT

Enter your choice : 3

Display Student records of
        1       - Passed
        2       - FirstClass
        3       - All
        default - All

Enter your choice : 2

---------------------------------------------------------------------
RegNo Name                 DSA      UNIX     MATH     Total    Result
---------------------------------------------------------------------
  166 David                  100.00    98.00    98.00   296.00   P
  123 Kiran                   88.00    92.00    84.00   264.00   P
  134 Prakash                 98.00    95.00   100.00   293.00   P
---------------------------------------------------------------------

The no. of students who got fist class : 3
************************************************************************
MENU -
        1 - ADD A RECORD
        2 - DELETE A RECORD
        3 - DISPLAY RECORDS
        4 - SEARCH FOR RECORD
        0 - EXIT

Enter your choice : 2
Enter Student regno to be deleted : 123

---------------------------------------------------------------------
RegNo Name                 DSA      UNIX     MATH     Total    Result
---------------------------------------------------------------------
  123 Kiran                   88.00    92.00    84.00   264.00   P
---------------------------------------------------------------------
************************************************************************
MENU -
        1 - ADD A RECORD
        2 - DELETE A RECORD
        3 - DISPLAY RECORDS
        4 - SEARCH FOR RECORD
        0 - EXIT

Enter your choice : 4

Search Student records based on
        1       - Name
        2       - RegNo
        default - RegNo

Enter your choice : 1
Enter Name to be searched : David

---------------------------------------------------------------------
RegNo Name                 DSA      UNIX     MATH     Total    Result
---------------------------------------------------------------------
  166 David                  100.00    98.00    98.00   296.00   P
---------------------------------------------------------------------
************************************************************************
MENU -
        1 - ADD A RECORD
        2 - DELETE A RECORD
        3 - DISPLAY RECORDS
        4 - SEARCH FOR RECORD
        0 - EXIT

Enter your choice : 4

Search Student records based on
        1       - Name
        2       - RegNo
        default - RegNo

Enter your choice : 2
Enter RegNo to be searched : 178

---------------------------------------------------------------------
RegNo Name                 DPST     JAVA     MATH     Total    Result
---------------------------------------------------------------------
  178 Varun                   56.00    72.00    63.00   191.00   P
---------------------------------------------------------------------
************************************************************************
MENU -
        1 - ADD A RECORD
        2 - DELETE A RECORD
        3 - DISPLAY RECORDS
        4 - SEARCH FOR RECORD
        0 - EXIT

Enter your choice :
*/
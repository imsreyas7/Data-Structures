#include "PriorQueueIf.h"
#include "PriorQueueImpl.h"

int main() {
    pq *p;
    int max,choice;
    printf("Enter the size of Heap : ");
    scanf("%d",&max);
    p = init(max);
    do{
        printf("------------------------------\n\n");
        printf("DRIVER-MENU:\n\t1 - Insert\n\t2 - Delete\n\t3 - Veiw\n\nEnter Your Choice :");
        scanf("%d",&choice);
        printf("------------------------------\n\n");
        
        switch(choice) {
            case 1: {
                emp mx=input();
                insert(p,mx);
                break;
            }
            case 2:{
                emp x=Delete(p);
                if(x.sal!=INT_MIN)
                    printf("Deleted : (%d)-(%s)\n",x.id,x.name);
                break;
            }
            case 3: disp(p,1,0);break;
        }
    }while(choice);
    printf("------------------------------\n\n");
    printf("THANK YOU\n\n");
    printf("------------------------------\n\n");
    return 0;
}

/*
exam51@jtl-17:~/DS/PriorQueue$ gcc PriorQueueAppl.c -o m
exam51@jtl-17:~/DS/PriorQueue$ ./m
Enter the size of Heap : 6
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :1
------------------------------

Enter element to be added : 1
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :1
------------------------------

Enter element to be added : 2
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :1
------------------------------

Enter element to be added : 3
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :1
------------------------------

Enter element to be added : 5
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :1
------------------------------

Enter element to be added : 4
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :1
------------------------------

Enter element to be added : 2
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :3
------------------------------

(1)
--(2)
----(5)
----(4)
--(2)
----(3)
----------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :2
------------------------------

Deleted : 1
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :2
------------------------------

Deleted : 2
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :2
------------------------------

Deleted : 2
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :3
------------------------------

(3)
--(5)
--(4)
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :0
------------------------------

------------------------------

THANK YOU

------------------------------

*/

/*
exam51@jtl-17:~/DS/PriorQueue$ gcc PriorQueueAppl.c -o m
exam51@jtl-17:~/DS/PriorQueue$ ./m
Enter the size of Heap : 6
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :3
------------------------------

------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :1
------------------------------

Enter Details : 
	ID :1001
	NAME :Shin
	SALARY :20000
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :1
------------------------------

Enter Details : 
	ID :1002
	NAME :Chan
	SALARY :12000
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :1
------------------------------

Enter Details : 
	ID :1003
	NAME :Ghan
	SALARY :15000
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :3
------------------------------

(1002)-(Chan)-(12000.00)
--(1001)-(Shin)-(20000.00)
--(1003)-(Ghan)-(15000.00)
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :1
------------------------------

Enter Details : 
	ID :1004
	NAME :Superman
	SALARY :12345
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :3
------------------------------

(1002)-(Chan)-(12000.00)
--(1001)-(Shin)-(20000.00)
----(1004)-(Superman)-(12345.00)
--(1003)-(Ghan)-(15000.00)
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :2
------------------------------

Deleted : (1002)-(Chan)
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :2
------------------------------

Deleted : (1004)-(Superman)
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :2
------------------------------

Deleted : (1003)-(Ghan)
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :3
------------------------------

(1001)-(Shin)-(20000.00)
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :0
------------------------------

------------------------------

THANK YOU

------------------------------

exam51@jtl-17:~/DS/PriorQueue$ gcc PriorQueueAppl.c -o m
exam51@jtl-17:~/DS/PriorQueue$ ./m
Enter the size of Heap : 8
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :1
------------------------------

Enter Details : 
	ID :1
	NAME :a
	SALARY :40
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :1
------------------------------

Enter Details : 
	ID :2
	NAME :b
	SALARY :20
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :1
------------------------------

Enter Details : 
	ID :3
	NAME :c
	SALARY :70
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :1
------------------------------

Enter Details : 
	ID :4
	NAME :d
	SALARY :60
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :3
------------------------------

(2)-(b)-(20.00)
--(1)-(a)-(40.00)
----(4)-(d)-(60.00)
--(3)-(c)-(70.00)
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :1
------------------------------

Enter Details : 
	ID :5
	NAME :e
	SALARY :100
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :1
------------------------------

Enter Details : 
	ID :6
	NAME :f
	SALARY :10
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :1
------------------------------

Enter Details : 
	ID :7
	NAME :g
	SALARY :5
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :1
------------------------------

Enter Details : 
	ID :8
	NAME :h
	SALARY :85
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :3
------------------------------

(7)-(g)-(5.00)
--(1)-(a)-(40.00)
----(4)-(d)-(60.00)
------(8)-(h)-(85.00)
----(5)-(e)-(100.00)
--(6)-(f)-(10.00)
----(3)-(c)-(70.00)
----(2)-(b)-(20.00)
------------------------------

DRIVER-MENU:
	1 - Insert
	2 - Delete
	3 - Veiw

Enter Your Choice :0
------------------------------

------------------------------

THANK YOU

------------------------------
*/

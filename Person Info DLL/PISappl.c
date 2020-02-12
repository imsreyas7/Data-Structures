#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"PISif.h"
#include"PISimpl.h"
void main()
{
	struct PIS *a,*temp;
	person p;
	struct ratio *r;
	r=(struct ratio *)malloc(sizeof(struct ratio));
	r->male=0;
	r->female=0;
	a=(struct PIS*)malloc(sizeof(struct PIS));
	temp=(struct PIS*)malloc(sizeof(struct PIS));
	a=init(a);
	int opt,x,wish,pin;
	char name[20];
	int pinno[50],i;
	pinno[0]=101;
	for(i=1;i<50;i++)
		pinno[i]=101+i;
	i=0;
	do{
	printf("\nenter option :\n\t1.insert FRONT\n\t2.insert END\n\t3.insert with PIN\n\t4.display\n\t5.sort\n\t6.list seniors\n\t7.List based on given location\n\t8.Give the ratio of male versus female  : ");
	
	scanf("%d",&opt);
	
		switch(opt){
			case 1: p=input(r);
				p.pin=pinno[i];
				insertFront(a,p);
				i++;
				break;
				
			case 2: p=input(r);
				p.pin=pinno[i];
				insertEnd(a,p);
				i++;
				break;
				
			case 3: printf("\nenter pin to find : ");
				scanf("%d",&pin);
				printf("\nnew record ");
				p=input(r);
				p.pin=pinno[i];
				insertPIN(a,p,pin);
				i++;
				break;
			case 4:	display(a);
				break;
				printf("\nsorted list ");
			case 5: sort(a);
				display(a);
				break;
				
			case 6:	seniorage(a);
				break;
			case 7: printf("\nenter the locatin to find : ");
				scanf("%s",name);
				location(a,name);
				break;
			case 8: findratio(r);
				break;
			default : break;
		}
		printf("\n--------------------------------------\ndo u wish to continue ?(1-Y/2-N)");
		scanf("%d",&wish);
	}while(wish!=2 && i<50);
}

/*

output :


enter option :
	1.insert FRONT
	2.insert END
	3.insert with PIN
	4.display
	5.sort
	6.list seniors
	7.List based on given location
	8.Give the ratio of male versus female  : 1

enter the details 
	name : vasanth

	age : 19

	sex (m/f) : m

	city address : chennai

	state address : tn

--------------------------------------
do u wish to continue ?(1-Y/2-N)1

enter option :
	1.insert FRONT
	2.insert END
	3.insert with PIN
	4.display
	5.sort
	6.list seniors
	7.List based on given location
	8.Give the ratio of male versus female  : 2

enter the details 
	name : michael      

	age : 12

	sex (m/f) : m

	city address : ranchi

	state address : delhi

--------------------------------------
do u wish to continue ?(1-Y/2-N)1

enter option :
	1.insert FRONT
	2.insert END
	3.insert with PIN
	4.display
	5.sort
	6.list seniors
	7.List based on given location
	8.Give the ratio of male versus female  : 3

enter pin to find : 101

new record 
enter the details 
	name : dwight

	age : 23

	sex (m/f) : m

	city address : goa

	state address : mumbai

--------------------------------------
do u wish to continue ?(1-Y/2-N)1

enter option :
	1.insert FRONT
	2.insert END
	3.insert with PIN
	4.display
	5.sort
	6.list seniors
	7.List based on given location
	8.Give the ratio of male versus female  : 2

enter the details 
	name : angela

	age : 22

	sex (m/f) : f

	city address : pune

	state address : mumbai

--------------------------------------
do u wish to continue ?(1-Y/2-N)1

enter option :
	1.insert FRONT
	2.insert END
	3.insert with PIN
	4.display
	5.sort
	6.list seniors
	7.List based on given location
	8.Give the ratio of male versus female  : 4

printing left to right :  
pin	|	name	|	age	|	sex

101	|	vasanth	|	19	|	m
103	|	dwight	|	23	|	m
102	|	michael	|	12	|	m
104	|	angela	|	22	|	f

do u wish to continue ?(1-Y/2-N)1

enter option :
	1.insert FRONT
	2.insert END
	3.insert with PIN
	4.display
	5.sort
	6.list seniors
	7.List based on given location
	8.Give the ratio of male versus female  : 5

printing left to right :  
pin	|	name	|	age	|	sex

102	|	michael	|	12	|	m
101	|	vasanth	|	19	|	m
104	|	angela	|	22	|	f
103	|	dwight	|	23	|	m
do u want to view the records from right to left? (1-Y/2-N) 2

--------------------------------------
do u wish to continue ?(1-Y/2-N)1

enter option :
	1.insert FRONT
	2.insert END
	3.insert with PIN
	4.display
	5.sort
	6.list seniors
	7.List based on given location
	8.Give the ratio of male versus female  : 2

enter the details 
	name : toby

	age : 67

	sex (m/f) : m

	city address : dispur

	state address : assam

--------------------------------------
do u wish to continue ?(1-Y/2-N)1

enter option :
	1.insert FRONT
	2.insert END
	3.insert with PIN
	4.display
	5.sort
	6.list seniors
	7.List based on given location
	8.Give the ratio of male versus female  : 6

pin	|	name	|	age	|	sex

105	|	toby	|	67	|	m
--------------------------------------
do u wish to continue ?(1-Y/2-N)1

enter option :
	1.insert FRONT
	2.insert END
	3.insert with PIN
	4.display
	5.sort
	6.list seniors
	7.List based on given location
	8.Give the ratio of male versus female  : 7

enter the locatin to find : mumbai

pin	|	name	|	age	|	sex

104	|	angela	|	22	|	f
103	|	dwight	|	23	|	m
--------------------------------------
do u wish to continue ?(1-Y/2-N)1

enter option :
	1.insert FRONT
	2.insert END
	3.insert with PIN
	4.display
	5.sort
	6.list seniors
	7.List based on given location
	8.Give the ratio of male versus female  : 8

RATIO-> male: female = 4 : 1
--------------------------------------
do u wish to continue ?(1-Y/2-N)2

*/

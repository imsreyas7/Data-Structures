#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>



typedef struct 
{
	char name[20];
	long int bp,sp;
}Player;


static int b=0;

typedef struct Team
{
	char Name[30];
	char Plr[15][80];
	long int wallet;
	int ct;
}Team;

void addPlayer(Player x)
{
	FILE *fptr=fopen("mini.txt","a+");
   fprintf(fptr,"%s %li\n",x.name,x.bp);
   fclose(fptr);
}


void displayAdmin()
{
	FILE *fptr=fopen("mini.txt","r");
	Player x;
	printf("Name\tBase Price\n");
	int c=0,i;
	while(fscanf(fptr,"%s%li\n",x.name,&x.bp)!=EOF)
	{
		printf("%s\t%li\n",x.name,x.bp);
		sleep(1);		
	}
	fclose(fptr);
	printf("\n\nDo you wish to continue ?");
	scanf("%d",&i);
}

typedef struct 
{
	char name[20];
	long int val;
}bid;

typedef struct
{	int top,size;
	bid arr[20];
}stack;

stack* initialises()
{
	stack *s=(stack *)malloc(sizeof(stack));
	s->top=-1;
	return s;
}

void push(stack *s,bid x)
{	
	s->top+=1;
	s->arr[s->top]=x;

}

int peek(stack *s)
{	
	return s->arr[(s->top)].val;
	
}
bid pop(stack *s)
{	
	s->top-=1;
	return s->arr[(s->top)+1];
	
}
typedef struct
{	Player a[50];
	int f,r,size;
}queue;


queue *initialise()
{
	queue *t=malloc(sizeof(queue));
	t->f=t->r=-1;
	t->size=15;
	return t;
}


int isFull(queue *Q)
{
	if((Q->r==Q->size-1&&Q->f==0)||(Q->r+1==Q->f))
		return 1;
	return 0;
}

int isEmpty(queue *Q)
{
	if(Q->f==-1)
		return 1;
	return 0;
}


void enqueue(queue *Q,Player x)
{
	if(isFull(Q))
		printf("Queue full!");
	else
	{
		if(Q->r==-1)
		{	Q->f=0;Q->r=0;}
		else if(Q->r==Q->size)
			Q->r=0;
		else
			Q->r+=1;
		Q->a[Q->r]=x;
		

	}
}


Player dequeue(queue *Q)
{
	
	Player t=Q->a[Q->f];
	if(Q->f==Q->r)
	{	Q->f=-1;Q->r=-1;}
	else if(Q->f==Q->size)
		Q->f=0;
	else
		Q->f+=1;
	return t;
}



void PlayerList(queue *q)
{
	FILE *fptr=fopen("mini.txt","r");
	Player x;
	while(fscanf(fptr,"%s %li\n",x.name,&x.bp)!=EOF)
	{
		enqueue(q,x);
	}
	fclose(fptr);

}






Team* teamInp()
{
	Team *T=(Team *)malloc(sizeof(Team));
	system("clear");
	printf("\n\n\t\tCREATE YOUR TEAM\n\n");
	printf("\nTEAM NAME: ");
	scanf(" %[^\n]",T->Name);
	T->wallet=1000000000;
	T->ct=0;
	return T;
}


void playerInp()
{
	Player P;
	system("clear");
	printf("\n\n\t\tADD PLAYER\n\n");
	printf("\nPlayer details: ");
	printf("Name: ");
	scanf(" %[^\n]",P.name);
	printf("\nBase Price: ");
	scanf("%li",&P.bp);
	P.sp=0;
	addPlayer(P);
}

int compW()
{
long arr[10000]={4,3,4,3,3,3,4,6,4,7,3,2,4,6,4,3,4,2,1,3,4,7,8,7,6,6,4,3,2,4,5,6,6,7,6,3,4,3,5,5,7,6,9,6,6,3,2,4,3,5,5,7,6,7,7,5,5,3,4,4,6,6,8,9,7,6,4,4,2,3,2,4,6,6,7,8,6,3,4,2,3,2,2,4,5,6,5,7,6,7,6,4,7};
	
	return (arr[b++]+arr[b+b-2+3])%2;
}

long compBid(long u)
{
	int ch=compW();
	long bid; 
	srand(time(0));
	bid= (rand() %( (u*2) - (u/2) + 1))+(u/2);
	long d=bid,c=0,i=0;
	while(d)
	{
		d/=10;
		c++;
	}
	d=bid;
	if(c%2==0)
	{
		while(d)
		{
			if(i<c-1)
				bid-=bid%(long int)pow(10,i+1);
			i++;
			d/=10;
		}
	}
	else
	{
		while(d)
		{
			if(i<c-2)
				bid-=bid%(int)pow(10,i+1);
			i++;
			d/=10;
		}
	}
	return bid; 
}



void Admin()
{
	Admin:
	system("clear");
	printf("\n\n\t\tADMIN PAGE\n\n");
	printf("\n\nMenu: \n\t1.Add Players\n\t2.Player Database\n\t3.Back\n\nChoice: ");
	int ch;
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			playerInp();
			break;
		case 2:
			displayAdmin();
			printf("dfsffsf");
			break;
		case 3:
			break;
		default:
			printf("\n\nINVALID CHOICE !!!!PRESS ANY KEY TO CONTINUE !");
			getchar();getchar();
	}			
}

void teamstandings(Team *T)
{
	system("clear");
	printf("\n\n\t\t\tFINAL %s SQUAD",T->Name);
	printf("\n\nPlayers: \n");
	for(int i=0;i<T->ct;i++)
	{
		printf("%d. %s\n",i+1,T->Plr[i]);
	}
	printf("\n\n\nWallet: %li",T->wallet);
	printf("\nPress 1 to continue: ");
	int con;
	scanf("%d",&con);
}


void Auctions()
{	
	queue *q=initialise();
	PlayerList(q);
	Team *T=teamInp();
	char cch;
	bid m;
	do
	{	system("clear");
		int ct=0;
		Player x;
		int temp;
		stack *s=initialises();
		long int y,z,k,l;
		char ch;
		long int val;
		int y1,y2;
		x=dequeue(q);
		int uf=1, cf1=1, cf2=1;
		int rno=1;
		printf("\n\t\t\tAUCTIONS\n");
		printf("-----------------------------------------------------------------------");
		printf("\nPLAYER: %s",x.name);
		do
		{	
			printf("\n-----------------------------------------------------------------------");
			printf("\nROUND %d",rno++);
			printf("\t\tCurrent Bid: %li",x.bp);
			printf("\t  Wallet: %li",T->wallet);			
			printf("\n-----------------------------------------------------------------------");
			if(uf)
			{
				printf("\n\nWould you like to bid: ");
				scanf(" %c",&ch);
				if(ch=='y'||ch=='Y')
				{	
					strcpy(m.name,T->Name);
					do{
					printf("Enter bid: ");
					scanf("%li",&m.val);
					}while(m.val<x.bp || m.val>T->wallet);
					
					push(s,m);
				}
				else
				{
					uf=0;
				}
			}
			if(uf==0)
			{
				sleep(2);
				if(cf1==0)
					printf("\nMI buys %s\n",x.name);
				else if(cf2==0)
					printf("\nRCB buys %s\n",x.name);
				else
				{
					int p=compW();
					if(p==0 )
						printf("\nRCB buys %s\n",x.name);
					else
						printf("\nMI buys %s\n",x.name);
				
				}
				break;
			}
			else
			{
				if(cf1)
				{
					y1=compW();
					if(y1==1)
					{	z=compBid((m.val-x.bp));
						y=peek(s);
						y=y+z;
						strcpy(m.name,"RCB");
						m.val=y;
						push(s,m);
						sleep(2);
						printf("\n\nRCB has bid:%li\n",m.val);
					}
					else
					{
						cf1=0;
					}
				}
				if(cf2)
				{
					y2=compW();
					if(y2==1)
					{	k=peek(s);
						m=pop(s);
						l=peek(s);
						z=compBid((k-l));
						y=z+k;
						strcpy(m.name,"MI");
						m.val=y;
						push(s,m);
						sleep(2);
						printf("\n\nMI has bid:%li\n",m.val);
					}
					else
						cf2=0;
				}
				
			}
			x.bp=peek(s);
		}while(cf1 || cf2);
		if(!cf1 && !cf2)
		{
			printf("\n-----------------------------------------------------------------------");
			printf("\n\t\tCongratulations!!You bought %s for Rs.%li!",x.name,m.val);
			printf("\n-----------------------------------------------------------------------");
			strcpy(T->Plr[T->ct],x.name);
			T->ct++;
			T->wallet-=x.bp;
		}
		if(uf==0&&cf1==0&&cf2==0)
		{
			printf("\n-----------------------------------------------------------------------");
			printf("\n\t%s goes Unsold",x.name);
			enqueue(q,x);
		}
		printf("\n\nPress 1 to continue: ");
		
		scanf("%d",&temp);		
		if(T->ct>2)
		{			
			printf("\n\nDo you wanna continue bidding ?");
			scanf(" %c",&ch);
		}
		
	}while(((cch=='y' || cch=='Y') || T->ct<4)&& !isEmpty(q));	
	
	teamstandings(T);		

}


void main()
{
	Main:
	system("clear");
	printf("\n\n\t\tFANTASY AUCTION SIMULATOR\n\n");
	printf("\n\nMenu: \n\t1.ADMINISTRATOR\n\t2.AUCTIONS\n\t3.EXIT\n\nChoice: ");
	int ch;
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			Admin();
			goto Main;
			break;
		case 2:
			Auctions();
			goto Main;
			break;
		case 3:
			exit(0);
		default:
			printf("\n\nINVALID CHOICE !!!!PRESS ANY KEY TO CONTINUE !");
			getchar();getchar();
			goto Main;
	}			
}

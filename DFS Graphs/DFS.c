#include<stdio.h>
#include<stdlib.h>


int a[7][7]={0};
int n;
int visited[7];
int path[7];

/*typedef struct
{	int top,size;
	char a[20];
}stack;

void initialise(stack *s)
{
	s->top=-1;
}
int isEmpty(stack *s)
{	if(s->top==-1)
		return 1;
	else return 0;
}
int isFull(stack *s)
{	if(s->top==s->size)
		return 0;
	else return 1;
}
void push(stack *s,char x)
{	
	s->top+=1;
	s->a[s->top]=x;

}
char pop(stack *s)
{	if(isEmpty(s)==1)
	{	printf("stack is empty");
		return 0;
	}
	else
	{	
		s->top-=1;
		return s->a[(s->top)+1];
	}
}
int peek(stack *s)
{
	return(s->a[s->top]):
}*/


void DFS(int i)
{
    int j;
    static int k=0;
	path[k++]=i;
  	 visited[i]=1;
	
	for(j=0;j<n;j++)
       if(!visited[j]&&a[i][j]==1)
            DFS(j);
}	


void pathfunc(int x,int y)
{
	int i;int j;
	for( i=0;i<n;i++)

	{
		if(path[i]==x)
		{
			for(j=i;path[j]!=y;j++)
			{
				printf(" %d ",path[j]);
				/*if(j==n-1)
				j=0;*/
			}
		
			printf(" %d ",path[j]);
			
			break;
		}	
	}
	
	

}

void main()
{
	char op;
	int x,y;
	
	printf(" Enter the number of vertices ");
	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)

			{
					printf(" \n Is there a link between vertices %d and %d (Y/N)",i,j);
					scanf(" %c",&op);
					if(op=='Y')
					{
					a[i][j]=1;
					a[j][i]=1;
					}
			}

	}


	for(int i=0;i<n;i++)
		{	
			printf("\n");
			for(int j=0;j<n;j++)
				printf(" %d ",a[i][j]);

		}


	DFS(0);

	
	printf(" \n Enter the source and destination vertices ");
	scanf(" %d %d",&x,&y);



	pathfunc(x,y);




	

}

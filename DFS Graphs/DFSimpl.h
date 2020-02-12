#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static int cur_state=-1;
int visited[1000];
char path[100][20];
int path_index=0;

typedef struct
{
	int no_of_cities;
	int adj[1000][1000];
	char cities[100][20];
}cityADT;

cityADT *init(cityADT *c,int size)
{
	int i,j;
	c=(cityADT*)malloc(sizeof(cityADT));
	c->no_of_cities=size;
	for(i=0;i<size+1;i++)
		for(j=0;j<size;j++)
		{
			if(i==j)
				c->adj[i][j]=1;
			else
				c->adj[i][j]=0;
		}
	return c;
}

int isFullC(cityADT *c)
{
	return c->no_of_cities<=cur_state;
}

int findCity(cityADT *c, char* city)
{
	for(int i=0;i<cur_state;i++)
	{
		if(strcmp(c->cities[i],city)==0)
			return i;
	}
	strcpy(c->cities[++cur_state],city);
	return cur_state;
}

void makeZero()
{
	for(int i=0;i<100;i++)
		visited[i]=0;
}

void create(cityADT *c,char* source,char* destination)
{
	if(!isFullC(c))
	{
		int i=findCity(c,source); int j=findCity(c,destination);
		if(!isFullC(c))
		{
			c->adj[i][j]=c->adj[j][i]=1;
			printf("%s and %s are connected.",source,destination);
		}
		else
			printf("\nThe map is full");
	}
	else
	{
		printf("\nThe map is full.");
	}

}

void visit(int x)
{	
	visited[x]=1;
}

int min(int a,int b)
{
	return a<b?a:b;
}

int connect(cityADT *c,char* source,char* destination)
{
	int size=cur_state;
	int i=findCity(c,source), j=findCity(c,destination);
	if(i>size || j>size)
		return 0;
	else
		return c->adj[i][j];
}

void dispCity(cityADT *c)
{
	int i,j;
	for(i=0;i<=min(c->no_of_cities-1,cur_state);i++)
	{
		printf("%-10s connects -> | ",c->cities[i]);
		for(j=0;j<min(c->no_of_cities-1,cur_state);j++)
		{
			if(connect(c,c->cities[i],c->cities[j]))
				printf("%-10s  | ",c->cities[j]);
		}
		printf("\n");
	}
}

int unvisited(cityADT *c)
{
	for(int i=0;i<=min(c->no_of_cities-1,cur_state);i++)
	{
		if(visited[i]==0)
			return i;
	}
	return -1;
}

void DFSdo(cityADT *c,int x)
{
	if(x==-1)
		printf("\nNo data available");
	else
	{
		visit(x);
		printf("  %s",c->cities[x]);
		for(int i=0;i<=min(c->no_of_cities-1,cur_state);i++)
		{
			if(c->adj[x][i] && visited[i]==0)
				DFSdo(c,i);
		}
	}
}

void DFS(cityADT *c)
{
	makeZero();
	while(unvisited(c)+1)
		DFSdo(c,unvisited(c));
}

void displayPath(int n)
{
	for(int i=0;i<n;i++)
	{
		if(i!=n) 
			printf(" %s ->",path[i]);
		else	 
			printf(" %s\n\n",path[i]);
	}
}

void printPath(cityADT *c,char* source,char* destination,int path_index)
{
	strcpy(path[path_index],source);
	if(strcmp(source,destination)==0) 
	{
		displayPath(path_index);
	}
	else 
	{
		int x=findCity(c,source);
		visit(x);
		int i;
		for(int i=0;i<=min(c->no_of_cities-1,cur_state);i++) 
		{
			if(c->adj[x][i] && visited[i]==0) 
			{
				printPath(c,c->cities[i],destination,path_index+1);
			}
		}
	}
}

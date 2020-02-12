#include "LinearQueue.h"

static int cur_state = -1;
int visited[1000000];

typedef struct {
	int no_of_cities;
	int adj[1000][1000];
	char cities[100][20];
}cityADT;


cityADT* init(cityADT* c,int size) {
	int i,j;
	c = (cityADT*)malloc(sizeof(cityADT));
	c->no_of_cities = size;
	for(i=0;i<size+1;i++) 
		for(j=0;j<size+1;j++) {
			if(i==j)	c->adj[i][j]=1;
			else		c->adj[i][j]=0;
		}
	return c;
}

int isFullC(cityADT *c) {
	return c->no_of_cities<cur_state;
}

int findCity(cityADT *c,char* city) {
	int i=0;
	for(;i<=cur_state;i++) {
		if(strcmp(c->cities[i],city)==0)
			return i;
	}
	strcpy(c->cities[++cur_state],city);
	return cur_state;
}

void makeZero() {
	int i;
	for(i=0;i<100;i++) visited[i]=0;
}
 
void create(cityADT *c , char* source , char* destination ) {
	if(!isFullC(c)) {
		int i=findCity(c,source),j=findCity(c,destination);
		c->adj[i][j]=c->adj[j][i]=1;
		printf("Connected %s & %s\n",source,destination);
	}
	else {
		printf("Map Full -- no more data can be added \n");
	}
}

void visit(int x) {
	visited[x]=1;
}

int min(int a,int b) {
	return a<b?a:b;
}

int connect(cityADT *c , char* source , char* destination ) {
	int size=cur_state;
	int i=findCity(c,source),j=findCity(c,destination);
	if(i>size || j>size)	return 0;
	else					return c->adj[i][j];
}

void dispCity(cityADT *c) {
	int i,j;
	for(i=0;i<=min(c->no_of_cities-1,cur_state);i++) {
		printf("%-10s connects -> | ",c->cities[i]);
		for(j=0;j<=min(c->no_of_cities-1,cur_state);j++) {
			if(connect(c,c->cities[i],c->cities[j]))	printf("%-10s  | ",c->cities[j]);
		}
		printf("\n");
	}
}

int unvisited(cityADT *c) {
	int i;
	for(i=0;i<=min(c->no_of_cities-1,cur_state);i++) {
		if(visited[i]==0)
			return i;
	}
	return -1;
}

void BFS(cityADT *c) {
	//BFS ALGO BASED ON NOTES.....
	queue *q = initialize(100000);
	int x,y,z;
	while(unvisited(c)+1) {
		x=unvisited(c);
		visit(x);
		enqueue(q,x);
		while(!isEmpty(q)) {
			z = dequeue(q);
			printf(" %s ",c->cities[z]);
			for(y=0;y<min(c->no_of_cities-1,cur_state);y++) {
				if(c->adj[z][y]==1 && visited[y]==0) {
					visit(y);
					enqueue(q,y);
				}
			}
		}
	}
}


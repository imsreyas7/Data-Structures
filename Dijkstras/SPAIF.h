typedef struct{
	int city_count;
	int adj[100][100];
	char cities[100][30];
	int visited[100];
	int distance[100];
	int path[100];
	int cur_state;
	
}cityADT;

cityADT *initADT(cityADT *c, int size);
int min(int a,int b);
int isFullState(cityADT *c);
int findCity(cityADT *c, char city[]);
int connect(cityADT *c, char start[], char dest[]);
void create(cityADT *c, char start[], char dest[]);
void display(cityADT *c);
void clearArrays(cityADT *c);
void visit(cityADT *c, int x);
int unvisited(cityADT *c);
void Dijkstra(cityADT *c, char start[]);
void PathFinder(cityADT *c, char start[], char end[]);


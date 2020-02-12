cityADT *initADT(cityADT *c, int size){
	int i,j;
	c=(cityADT *)malloc(sizeof(cityADT));
	c->city_count=size;
	for(i=0;i<=size;i++){
		for(j=0;j<=size;j++){
				c->adj[i][j]=10000;		//all nodes are initially not connected
		}
	}
	c->cur_state=-1;
	return c;
}

int min(int a,int b){
	return a<b?a:b;
}

int isFullState(cityADT *c){
	return c->city_count<c->cur_state;
}

int findCity(cityADT *c, char city[]){
	int i=0;
	for(i=0;i<=c->cur_state;i++){
		if(strcmp(c->cities[i],city)==0)
			return i;
	}
	strcpy(c->cities[++c->cur_state],city);		//assigning the city to the cur_state+1 if it does not exist
	return c->cur_state;						//used only while create routine is called
}

int connect(cityADT *c, char start[], char dest[]){
	int i,j,size;
	size=c->cur_state;
	i=findCity(c,start);
	j=findCity(c,dest);
	if(i>size||j>size||c->adj[i][j]==10000)
		return 0;
	else
		return c->adj[i][j];
}

void create(cityADT *c, char start[], char dest[]){
	if(!isFullState(c)){
		int cost;
		int i=findCity(c,start);
		int j=findCity(c,dest);
		printf("\nEnter cost to go from %s to %s: ",start,dest);
		scanf("%d",&cost);
		c->adj[i][j]=cost;
		printf("\n%s is now connected with %s with cost %d.",start,dest,cost);
	}
	else{
		printf("\nData limit has been reached. No more additions can be made.");
	}
}

void display(cityADT *c){
	int i,j;
	int flag=0;
	int limit=min(c->city_count-1,c->cur_state);
	for(i=0;i<=limit;i++){
		printf("\n%s is connected to:\n",c->cities[i]);
		for(j=0;j<=limit;j++){
			if(connect(c,c->cities[i],c->cities[j])!=0){
				printf("  %s",c->cities[j]);
				flag=1;
			}
		}
		if(flag==0)
			printf("\t-nil-");
	}
}


void clearArrays(cityADT *c){
	int x;
	int limit=min(c->cur_state,c->city_count-1);
	for(x=0;x<100;x++){
		c->visited[x]=0;
		c->distance[x]=10000;		//high value
		c->path[x]=-1;			//no path default
	}
}

void visit(cityADT *c, int x){
	c->visited[x]=1;
}

int unvisited(cityADT *c){
	int i;
	int limit=min(c->city_count-1,c->cur_state);
	for(i=0;i<=limit;i++){
		if(c->visited[i]==0)
			return i;
	}
	return -1;
}

void Dijkstra(cityADT *c, char start[]){
	int s_node=findCity(c,start);
	c->distance[s_node]=0;
	c->path[s_node]=0;
	int limit=min(c->city_count-1,c->cur_state);
	int i=0,min_node=s_node; 
	int min=10000;		//the default value of initial distance
	int prev_min;

	while(unvisited(c)+1){
		prev_min=min_node;
		for(i=0;i<=limit;i++){		//shortest unknown distance vertex
			if(c->visited[i]==0)	//unvisited
				if(min>=c->distance[i]){		//finding minimum distance vertex
					min=c->distance[i];		//updating minimum to find if there's still a minimum
					min_node=i;				//finally updating min node to the current minimum
				}							//the least distance vertex is returned
		}
		min=10000;							//reassigning it back to default max value
		visit(c,min_node);		
		i=0;
		if(!(unvisited(c)+1))		//printing VKDP Table for Dijkstra's Shortest Path Algorithm
			printf("\n\nVertex\tKnown\tDistance\tPath\n");
		while(i<=limit){
			if(c->adj[min_node][i]!=0){
				if(c->visited[i]==0){
					if(c->distance[min_node]+c->adj[min_node][i]<c->distance[i]){
						c->distance[i]=c->distance[min_node]+c->adj[min_node][i];
						if(c->distance[i]!=10000)		//changing path only if distance is valid
							c->path[i]=min_node;
					}	
				}
				if(!(unvisited(c)+1)){
					if(c->path[i]!=-1 && i!=s_node)		//Final Table
						printf("\n%s\t%d\t%d\t\t%s",c->cities[i],c->visited[i],c->distance[i],c->cities[c->path[i]]);
					else if(i==s_node)
						printf("\n%s\t%d\t0\t\t0",c->cities[i],c->visited[i]);
					else
						printf("\n%s\t%d\t∞\t\t0",c->cities[i],c->visited[i]);
				}
			}
			i++;
		}
	}
}

void PathFinder(cityADT *c, char start[], char end[]){
	int s_node=findCity(c,start);
	int e_node=findCity(c,end);
	clearArrays(c);
	Dijkstra(c,start);
	int route[100],count=0,i;
	if(c->distance[e_node]<10000){	//distance should not be the max value
		printf("\n\nShortest Path exists between %s and %s with cost %d.",start,end,c->distance[e_node]);
		route[count++]=e_node;
		while(s_node!=e_node){
			route[count++]=c->path[e_node];
			e_node=c->path[e_node];
		}
		printf("\nShortest Path:\n\t");
		for(i=count-1;i>=0;i--){		//printing the path
			printf("%s",c->cities[route[i]]);
			if(i-1>=0)
				printf("--->");
		}
	}
	else
		printf("\n\nPath does not exist between %s and %s",start,end);

}

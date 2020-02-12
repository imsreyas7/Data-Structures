void initHT(HashTable *H, int size){
	int i;
	H->size=size;
	for(i=0;i<size;i++){
		H->list[i]=(struct node *)malloc(sizeof(struct node));
		H->list[i]->next=NULL;
	}
}

int hash(HashTable *H, int x){
	return x%(H->size);
}

void insertElement(HashTable *H, int x){
	struct node *temp,*i;
	int key;
	temp=(struct node *)malloc(sizeof(struct node));
	i=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;

	key=hash(H,x);
	i=H->list[key];
	if(i==NULL){		//Inserting at First Node, if Node is Empty
		H->list[key]=temp;
	}
	else{
		while(i->next!=NULL){		//conflict resolution
			i=i->next;		
		}
		i->next=temp;		//Inserting at End, if Node isn't Empty
	}
}

void searchElement(HashTable *H, int x){
	int key=hash(H,x);
	int flag=-1,pos=-1;
	struct node *i;
	i=(struct node *)malloc(sizeof(struct node));
	i=H->list[key]->next;		//Starting from Next of first, since
	while(i!=NULL){				//thats where we start storing initially
		pos++;					//finding position in bucket
		if(i->data==x){
			printf("\nElement %d was found at Index %d in Bucket %d.",x,pos,key);
			flag++;
		}
		i=i->next;
	}
	if(flag==-1)
		printf("\nElement %d was not found.",x);
}

void displayHT(HashTable *H){
	struct node *i;
	i=(struct node *)malloc(sizeof(struct node));
	int key=0;
	printf("\nHash Table: ");
	while(key<H->size){			//Traversing each bucket one by one
		i=H->list[key]->next;
		printf("\n\n");
		while(i!=NULL){
			printf("%d",i->data);
			i=i->next;
			if(i!=NULL)
				printf("--->");
		}
		key++;
	}
}
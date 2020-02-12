/* TREE ADDRESS STACK IMPLEMENTATION */

struct Tree{
	char opnd;
	int optr;
	struct Tree *right,*left;
};

typedef struct{
	struct Tree *t;
	int top;
	int limit;	
}TreeStack;

int isEmptyT(TreeStack *T){					// – Check whether the stack is empty

	if(T->top==-1)
		return 1;
	return 0;

} 


int isFullT(TreeStack *T){					//	– Check whether the stack is full
	if(T->top==T->limit-1)
		return 1;
	return 0;
} 


void initStackT(TreeStack *T, int lim){		// - To initialize the stack
	T->top=-1;
	T->limit=lim;
	T->t=(struct Tree *)malloc(sizeof(struct Tree)*lim);
}


void pushT(TreeStack *T, struct Tree *n){			// – Push an element into the stack

	if(isFullT(T))
		printf("\nStack is Full. Cannot push further.");
	else
		T->t[++T->top]=*n;

}


struct Tree *popT(TreeStack *T){						// – Pop an element from the stack

	struct Tree *n;
	n=(struct Tree *)malloc(sizeof(struct Tree));

	if(isEmptyT(T))
		printf("\nStack is empty. Cannot pop further.");
	else{
		*n=T->t[T->top];
		T->top--;
	}
	return n;

}


void dispTree(struct Tree *t,int spacing){					// – Display elements from the stack

	int i=0;
	
	printf("\n");
	
	for (i=0; i<spacing; i++){
 		if (i%2==0||i==0)     
    		printf("  ");
    }

    if(spacing)
    	printf("->");

	if(t->optr=='0')
		printf("%d",t->opnd);
	if (t->optr!='0'){
		printf("%c",t->optr);
       		dispTree(t->left,spacing+2);
		dispTree(t->right,spacing+2);

	}

}



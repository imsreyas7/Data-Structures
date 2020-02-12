/* BASIC CHAR ARRAY STACK IMPLEMENTATION */

typedef struct{
	char arr[100];
	int top;
	int limit;
}Stack;


int isEmpty(Stack *S){					// – Check whether the stack is empty

	if(S->top==-1)
		return 1;
	return 0;

} 


int isFull(Stack *S){					//	– Check whether the stack is full
	if(S->top==S->limit-1)
		return 1;
	return 0;
} 


void initStack(Stack *S, int lim){		// - To initialize the stack
	S->top=-1;
	S->limit=lim;
}


void push(Stack *S, char x){			// – Push an element into the stack

	if(isFull(S))
		printf("\nStack is Full. Cannot push further.");
	else
		S->arr[++S->top]=x;

}


char pop(Stack *S){						// – Pop an element from the stack

	char popped;

	if(isEmpty(S))
		printf("\nStack is empty. Cannot pop further.");
	else{
		popped=S->arr[S->top];
		S->top--;
	}
	return popped;

}


void disp(Stack *S){					// – Display elements from the stack

	int i=0;
	if(isEmpty(S))
		printf("\nStack is empty. No elements to display.");
	else{
		printf("\nStack elements, from Bottom To Top: ");
		while(i<S->top){
			printf("\n\t\t%c",S->arr[i]);
		}
	}
}



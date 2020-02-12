#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct{
	int a[100000];
	int capacity,front,rear;
}queue;

queue* initialize(int x){
	queue *q = (queue*)malloc(sizeof(queue));	
	q->capacity = x;
	q->front = 0;
	q->rear = -1;
}


int isEmpty(queue *q) {
	return q->front == q->rear +1 ;
}

int isFull(queue *q) {
	return q->rear == q->capacity-1;
}

void enqueue(queue *q, int x){
	if(isFull(q)){
		printf("\n! Queue is Full !\n");
	}
	else{
		q->a[++q->rear] = x;
	}
}

int dequeue(queue *q) {
	if(isEmpty(q)){
		q->front =0;
		q->rear = -1;
		printf("\n! Queue is Empty !\n");
		return -99;
	}
	else
		return q->a[q->front++];
}

void disp(queue *q){
	int i;
	if(!isEmpty(q)) {
		printf("\nFRONT -> ");
		for(int i=q->front ; i<= q->rear ; i++) {
			printf(" %d",q->a[i]);
		}
		printf(" <- REAR\n\n");
	}
}
#include<limits.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int id;
    char name[20];
    float sal;
}emp;

typedef struct {
    emp a[100000];
    int size;
    int capacity;
}pq;

pq* init(int max);
int isFull(pq *p);
int isEmpty(pq *p);
void insert(pq *p,emp x);
void disp(pq *p,int in,int lvl);
emp Delete(pq *p);

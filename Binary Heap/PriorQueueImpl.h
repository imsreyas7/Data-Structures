pq* init(int max){
    pq *p=(pq*)malloc(sizeof(pq));
    p->a[0].sal=INT_MIN;
    p->a[1].sal=INT_MIN;
    p->size=0;
    p->capacity=max;  
    return p; 
}

int isFull(pq *p)  {return p->size==p->capacity;}
int isEmpty(pq *p) {return p->size==0;}

void insert(pq *p,emp x) {
    if(isFull(p)){
        printf("Queue Full\n");
    }
    else{
        int i=p->size;
        p->a[++p->size]=x;
        while(p->a[i/2].sal>p->a[i].sal ) {
            emp t=p->a[i/2];
            p->a[i/2]=p->a[i];
            p->a[i]=t;
            i/=2;
        }
    }
}

void disp(pq *p,int in,int lvl) {
    int i;
    for(int i=0;i<lvl;i++) printf("--");
    if(in<=p->size) { 
        printf("(%d)-(%s)-(%.2f)\n",p->a[in].id,p->a[in].name,p->a[in].sal);
        if(2*in <= p->size) disp(p,2*in,lvl+1);
        if(2*in+1 <=p->size)  disp(p,2*in+1,lvl+1);
    }
}

emp Delete(pq *p) {
    if(isEmpty(p)) { printf("Queue Empty\n"); return p->a[0];}
    else {
        int i,child;
        emp min = p->a[1];
        emp last = p->a[p->size--];
        
        for(i=1;(i*2)<=p->size;i=child) {
            child=i*2;
            if(child+1<=p->size && p->a[child+1].sal<p->a[child].sal) child++;
            if(last.sal > p->a[child].sal)  p->a[i]=p->a[child];
            else break;
        }
        p->a[i]=last;
        return min;
    }   
}

emp input() {
    emp p;
    printf("Enter Details : ");
    printf("\n\tID :");
    scanf("%d",&p.id);
    printf("\tNAME :");
    scanf("%s",p.name);
    printf("\tSALARY :");
    scanf("%f",&p.sal);
    return p;
}

typedef struct{
	int pow;
	int coeff;
}term;

struct poly{
	term t;
	struct poly *next;
};

struct poly* initPoly(){
	struct poly *p;
	p=(struct poly *)malloc(sizeof(struct poly));
	return p;
}

void insertFront(struct poly *p,int c,int e){
	struct poly *temp=initPoly();
	temp=(struct poly *)malloc(sizeof(struct poly));
	temp->t.pow=e;
	temp->t.coeff=c;
	temp->next=p->next;
	p->next=temp;

}

void insertEnd(struct poly *p,int c,int e){
	struct poly *i,*temp;
	term new;
	temp=initPoly();
	i=initPoly();
	temp->t.pow=e;
	temp->t.coeff=c;
	i=p;
	while(i->next!=NULL){			
		i=i->next;
	}
	temp->next=i->next;
	i->next=temp;			
}


int insertAfterTerm(struct poly *p,int c,int e,int sc,int se){
	struct poly *temp,*i;
	int k=0;
	temp=initPoly();
	i=initPoly();
	temp->t.pow=e;
	temp->t.coeff=c;
	i=p;
	while(i!=NULL){
		if(i->t.pow==se && i->t.coeff==sc){
			temp->next=i->next;
			i->next=temp;
			k++;
			break;
		}
		else
			i=i->next;
	}
	if(k==0)
		printf("\nTerm was not found. Element was not inserted.");
}


void polyDegree(struct poly *p){
	struct poly *i;
	i=initPoly();
	int maxdeg=0;
	i=p;
	while(i!=NULL){
		if(maxdeg<i->t.pow)
			maxdeg=i->t.pow;
		i=i->next;
	}
	printf("\nThe degree of the polynomial is : %d",maxdeg);
}

void evaluatePoly(struct poly *p,int val){
	struct poly *i;
	i=initPoly();
	int res=0;
	i=p;
	while(i!=NULL){
		res=res+(pow(val,i->t.pow)*(i->t.coeff));
		i=i->next;
	}
	printf("\nThe expression's value when x= %d is %d",val,res);
}

void showPoly(struct poly *p){
	struct poly *i=initPoly();
	i=p->next;
	while(i!=NULL){ 
	    printf("%dx^%d",i->t.coeff,i->t.pow); 
	    i=i->next; 
	    if(i!=NULL) 
	        printf(" + "); 
	} 
}


struct poly* addPoly(struct poly *poly1,struct poly *poly2){ 
	struct poly *p1,*p2,*p3, *p;
	p1=initPoly();
	p2=initPoly();
	p3=initPoly();
	p=initPoly();
	p1=poly1->next;
	p2=poly2->next;
	while(p1!=NULL && p2!=NULL){
		if(p1->t.pow==p2->t.pow){
			p->t.coeff=p1->t.coeff+p2->t.coeff;
			p->t.pow=p1->t.pow;
			insertFront(p3,p->t.coeff,p->t.pow);
			p1=p1->next;
			p2=p2->next;
		}
		else if(p1->t.pow>p2->t.pow){
			p->t.coeff=p1->t.coeff;
			p->t.pow=p1->t.pow;
			p1=p1->next;
			insertFront(p3,p->t.coeff,p->t.pow);
		}
		else{
			p->t.coeff=p2->t.coeff;
			p->t.pow=p2->t.pow;
			p2=p2->next;
			insertFront(p3,p->t.coeff,p->t.pow);
		}
	}

	while(p2!=NULL){
			p->t.coeff=p2->t.coeff;
			p->t.pow=p2->t.pow;
			p2=p2->next;
			insertFront(p3,p->t.coeff,p->t.pow);
	}

	while(p1!=NULL){
			p->t.coeff=p1->t.coeff;
			p->t.pow=p1->t.pow;
			p1=p1->next;
			insertFront(p3,p->t.coeff,p->t.pow);
		}
	return p3;
}





struct poly* findPrevious(struct poly *p,struct poly *elt){
	struct poly *i,*res,*j;
	i=initPoly();
	j=initPoly();
	res=initPoly();
	i=p;
	j=p;
	while(i!=NULL){
		if(i->t.pow==elt->t.pow && i->t.coeff==elt->t.coeff)
			return j;
		else{
			j=i;
			i=i->next;
		}
	}
}

void simplifyPoly(struct poly *p){
	struct poly *i,*j,*prev;
	i=initPoly();
	j=initPoly();
	prev=initPoly();
	i=p->next;
	while(i!=NULL)
	{
		j=i->next;
		while(j!=NULL)
		{
			if(j->t.pow==i->t.pow)
			{
				i->t.coeff+=j->t.coeff;
				prev=findPrevious(p,j);
				prev->next=j->next;
			}
			j=j->next;
		}
		i=i->next;
	}
}


struct poly* multiplyPoly(struct poly *poly1,struct poly *poly2){
	struct poly *p1,*p2,*p3,*p,*temp;
	p1=initPoly();
	p2=initPoly();
	p3=initPoly();
	p=initPoly();
	temp=initPoly();
	p1=poly1->next;
	p2=poly2->next;
	while(p1!=NULL){
		while(p2!=NULL){
			temp->t.coeff=p1->t.coeff*p2->t.coeff;
			temp->t.pow=p1->t.pow+p2->t.pow;
			insertFront(p,temp->t.coeff,temp->t.pow);
			p2=p2->next;
		}
		p1=p1->next;
		p2=poly2->next;
	}
	simplifyPoly(p);
	return p;
}

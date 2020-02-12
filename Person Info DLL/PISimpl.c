struct PIS *init(struct PIS *a)
{
	a->lptr=NULL;
	a->rptr=NULL;
	return a;
}
void insertFront(struct PIS *a,person p) 
{
	struct PIS *temp,*next;
	temp=(struct PIS*)malloc(sizeof(struct PIS));
	next=(struct PIS*)malloc(sizeof(struct PIS));
	temp->p=p;
	next=a->rptr;
	if(next==NULL){
		temp->rptr=a->rptr;
		a->rptr=temp;
		temp->lptr=a;
	}
	else{
		temp->rptr=a->rptr;
		a->rptr=temp;
		temp->lptr=a;
		next->lptr=temp;
	}
}
person input(struct ratio *r)
{
	person p;
	printf("\nenter the details \n\tname : ");
	scanf("%s",p.name);
	printf("\n\tage : ");
	scanf("%d",&p.age);
	printf("\n\tsex (m/f) : ");
	scanf(" %c",&p.sex);
	//printf("\n\tPerson Identification Number (PIN) : ");
	//scanf("%d",&p.pin);
	printf("\n\tcity address : ");
	scanf("%s",p.cityadres);
	printf("\n\tstate address : ");
	scanf("%s",p.stadres);
	r=ratiocalc(p.sex,r);
	return p;
}
void insertEnd(struct PIS *a,person p)
{
	struct PIS *temp,*next;
	temp=(struct PIS*)malloc(sizeof(struct PIS));
	next=(struct PIS*)malloc(sizeof(struct PIS));
	temp->p=p;
	next=a->rptr;
	while(next->rptr!=NULL){
		next=next->rptr;
	}
	temp->rptr=next->rptr;
	next->rptr=temp;
	temp->lptr=next;
}
void insertPIN(struct PIS *a,person p,int pin)
{
	struct PIS *next,*temp;
	temp=(struct PIS*)malloc(sizeof(struct PIS));
	temp->p=p;
	int flag=0;
	next=(struct PIS*)malloc(sizeof(struct PIS));
	next=a->rptr;
	while(next!=NULL){
		if(next->p.pin==pin){
			flag=1;
			temp->rptr=next->rptr;
			next->rptr=temp;
			temp->lptr=next;
			break;
		}
		next=next->rptr;
	}
	if(flag==0)
		printf("\nSORRY!!!no such pin is available");
}			
	
void display(struct PIS *a)
{
	struct PIS *temp;
	temp=(struct PIS*)malloc(sizeof(struct PIS*));
	temp=a->rptr;
	printf("\nprinting left to right :  ");
	printf("\npin\t|\tname\t|\tage\t|\tsex\n");
	while(temp->rptr!=NULL){
		printf("\n%d\t|\t%s\t|\t%d\t|\t%c",temp->p.pin,temp->p.name,temp->p.age,temp->p.sex);
		temp=temp->rptr;
	}
	printf("\n%d\t|\t%s\t|\t%d\t|\t%c",temp->p.pin,temp->p.name,temp->p.age,temp->p.sex);
	int wish;
	printf("\ndo u want to view the records from right to left? (1-Y/2-N) ");
	scanf("%d",&wish);
	if(wish==1){
		printf("\nprinting right to left\n");
		printf("\npin\t|\tname\t|\tage\t|\tsex\n");
		while(temp->lptr!=NULL){
			printf("\n%d\t|\t%s\t|\t%d\t|\t%c",temp->p.pin,temp->p.name,temp->p.age,temp->p.sex);
			temp=temp->lptr;
		}
	}
	
	
}	

void sort(struct PIS *a)
{
	struct PIS *next,*next2;
	person temp,p1,p2;
	int flag=0,k;
	next2=(struct PIS*)malloc(sizeof(struct PIS));
	next=(struct PIS*)malloc(sizeof(struct PIS));
	next=a->rptr;	
	while(next!=NULL){
		next2=next->rptr;
		while(next2!=NULL){
			p1=next->p;p2=next2->p;
			if(p1.age > p2.age){
				temp=p1;
				p1=p2;
				p2=temp;
				next->p=p1;
				next2->p=p2;
			}
			next2=next2->rptr;
		}
		next=next->rptr;
	}
}

void seniorage(struct PIS *a)
{
	struct PIS *temp;
	temp=(struct PIS*)malloc(sizeof(struct PIS*));
	temp=a->rptr;
	int count;
	printf("\npin\t|\tname\t|\tage\t|\tsex\n");
				
	while(temp!=NULL){
		if(temp->p.age>=60){
			printf("\n%d\t|\t%s\t|\t%d\t|\t%c",temp->p.pin,temp->p.name,temp->p.age,temp->p.sex);
			count++;
		}
		temp=temp->rptr;
	}
	if(count==0)
		printf("\n!!! NO SENOIRS !!!!!");
}

void location(struct PIS *a,char name[])
{
	struct PIS *temp;
	person p;
	temp=(struct PIS*)malloc(sizeof(struct PIS*));
	temp=a->rptr;
				
	printf("\npin\t|\tname\t|\tage\t|\tsex\n");
	while(temp!=NULL){
		if(strcmp(temp->p.cityadres,name) ==0 ||  strcmp(temp->p.stadres,name) ==0 ){
		printf("\n%d\t|\t%s\t|\t%d\t|\t%c",temp->p.pin,temp->p.name,temp->p.age,temp->p.sex);
		}
		temp=temp->rptr;
	}
}

void findratio(struct ratio *r)
{
	int i,gcd,a=r->male,temp;
	int a1=r->male,b=r->female,b1=r->female;
	if(a<b){
		temp=a;
		a=b;
		b=temp;
	}
	while(b!=0){
		temp=b;
		b=a%b;
		a=temp;	
	}
	a1=a1/a;
	b1=b1/a;
	printf("\nRATIO-> male: female = %d : %d",a1,b1);
}

struct ratio *ratiocalc(char sex,struct ratio *r)
{
	int flag;
	if(sex=='m')
		r->male+=1;
	else if (sex=='f')
		r->female+=1;
	else
	 	flag++;
	return r;
}

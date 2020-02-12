#define limit 100

typedef struct {
	int RegNo;
	char Name[50];
	float M1,M2,M3,Tot;
	char res;
	int flag;
} Student;

typedef struct{
	Student X[limit];
	int size;
} ListADT;


void initialize (ListADT *l) {
	int i;
	l->size=-1;
	for(i=0;i<limit;i++) {	
		l->X[i].RegNo = -1;
		l->X[i].flag  = 0;
	}
}

void display(Student S)	{
	printf("%5d %-20s %8.2f %8.2f %8.2f %8.2f %3c\n",S.RegNo,S.Name,S.M1,S.M2,S.M3,S.Tot,S.res);	
}

void insertFront (ListADT *l , Student S) {
	int i;
	
	if(l->size + 1 < limit)	{
		for(i=l->size + 1; i>0 ; i--)
			l->X[i] = l->X[i - 1] ;
		
		l->X[0] = S ;
		l->size++;
	}
	
	else
		printf("Memory Full !!\n") ;
} 

void insertBack (ListADT *l , Student S) {
	
	
	if(l->size + 1 < limit)	
		l->X[++l->size] = S ;
	
	else
		printf("Memory Full !!\n") ;
}

void insertRegno (ListADT *l , Student S , int regnum) {
	int i,j;
	
	if(l->size + 1 < limit) {
		for(i=0 ; i< l->size+1 ;i++) 
			if (regnum == l->X[i].RegNo) 
				break;
		
		for(j= l->size +1 ; j > i+1 ; j--)
			l->X[j] = l->X[j-1];	
		l->X[i+1] = S;
		l->size+=1;
	}
	
	else
		printf("Memory Full !!\n") ;
}

Student searchRegNo (ListADT l , int regnum) {
		int i;
		
		Student temp = {-1,"-",0,0,0,0,'F',1};
		for(i=0;i<l.size+1;i++)
			if(l.X[i].RegNo == regnum){
				temp = l.X[i] ;
				break;
			}
		
		return temp;
} 

ListADT searchName (ListADT l , char Nm[]) {
	ListADT list;
	initialize(&list);
	int i;
	
	for(i=0;i<l.size+1;i++) 
		if(strcmp(l.X[i].Name , Nm) == 0) {
			list.X[++list.size] = l.X[i] ;
		}
		
	return list;
}

void delete (ListADT *l , int regnum) {
	Student S;
	int i,j;
	
	if(l->size != -1) {
		for(i=0;i<l->size+1;i++)
			if(l->X[i].RegNo == regnum){
				S = l->X[i];
				break;
			}
		
		for(j=i;j<l->size+1;j++)
			l->X[j] = l->X[j+1];
		l->size--;
		
		printf("\n---------------------------------------------------------------------\n");
		printf("%5s %-20s %-8s %-8s %-8s %-8s %s\n","RegNo","Name","DSA","UNIX","MATH","Total","Result");
		printf("---------------------------------------------------------------------\n");	
		display(S);
		printf("---------------------------------------------------------------------\n");
	}
	
	else
		printf("Empty.\n");
}

void computeResult (ListADT *l) {
	int i;
	
	for(i=0;i<l->size+1;i++){
		if(!(l->X[i].flag)) {
			if(l->X[i].M1 < 50 || l->X[i].M2 < 50 || l->X[i].M3 < 50)
				l->X[i].res = 'F' ;
			else
				l->X[i].res = 'P' ;
			l->X[i].flag=1;
		}
	
		l->X[i].Tot = l->X[i].M1 + l->X[i].M2 + l->X[i].M3;
	}
}

void dispALL(ListADT l) {
	int i;
	
	if(l.size != -1){
		printf("\n---------------------------------------------------------------------\n");
		printf("%5s %-20s %-8s %-8s %-8s %-8s %s\n","RegNo","Name","DSA","UNIX","MATH","Total","Result");
		printf("---------------------------------------------------------------------\n");	
		for(i=0;i<l.size+1;i++)
			display(l.X[i]);
		printf("---------------------------------------------------------------------\n");
	}
	
	else
		printf("No Data  !!!\n");
}

ListADT listResult	(ListADT l) {
		ListADT list;
		initialize(&list);
		int i;
		
		for(i=0;i<l.size+1;i++)	{
			if(l.X[i].res == 'P')
				list.X[++list.size] = l.X[i];
		}
		
		return list;
}

int listClass (ListADT l)	{
	int i,count = 0;
	ListADT l1;
	l1.size=-1;
	
	for(i=0;i<l.size+1;i++)
		if(l.X[i].M1 > 60 && l.X[i].M2 > 60 && l.X[i].M3 > 60) {
			l1.X[count++] = l.X[i];
			l1.size++;
		}	
	dispALL(l1);
	return count;
}

Student getInput(ListADT *l)	{
	Student S;
	
	S.flag = 0;
	printf("Enter Student Details :-\n");
	printf("----------------------------\n");
	printf("\tRegister Number : ");
	scanf("%d",&S.RegNo);
	printf("\tName of student : ");
	scanf(" %[^\n]",S.Name);
	printf("\tMarks -\n\t\tData Structures and Algorithms  : ");
	scanf("%f",&S.M1);
	printf("\t\tUNIX and Shell programming  : ");
	scanf("%f",&S.M2);
	printf("\t\tDiscrete Mathematics  : ");
	scanf("%f",&S.M3);
	
	return S;
}



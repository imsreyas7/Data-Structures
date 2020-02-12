typedef struct{
	char name[50],sex;
	int age;
	char stadres[40],cityadres[40];
	int pin;
}person;
struct PIS{
	
	person p; 
	struct PIS *lptr;
	struct PIS *rptr;
};
struct ratio{
	int male;
	int female;
};
person input(struct ratio *r);
struct PIS *init(struct PIS *a);
void insertFront(struct PIS *a,person p);
void display(struct PIS *a);
void insertEnd(struct PIS *a,person p);
void insertPIN(struct PIS *a,person p,int pin);
void sort(struct PIS *a);
void seniorage(struct PIS *a);
void location(struct PIS *a,char name[]);
void findratio(struct ratio *r);
struct ratio *ratiocalc(char sex,struct ratio *r);

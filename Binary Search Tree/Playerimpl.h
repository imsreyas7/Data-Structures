typedef struct Player
{
	char name[80];
	struct Player *lptr, *rptr; 
	
}Player; 

Player *initialize()
{
	Player *P=(Player *)malloc(sizeof(Player));
	P->lptr=NULL;
	P->rptr=NULL;
	return P; 
}


Player *insert(Player *P,char name[80])
{
	if(P==NULL)
	{
		P=initialize();
		strcpy(P->name,name);
	}
	else
	{
		if(strcmp(P->name,name)>0)
			P->lptr=insert(P->lptr,name);
		else
			P->rptr=insert(P->rptr,name);
	}
}

Player *findMin(Player *P)
{
	while(P->lptr)
		P=P->lptr;
	return P;
}

Player *Delete(Player *P,char name[80])
{
	Player *temp=initialize();
	if(strcmp(P->name,name)>0)
		P->lptr=Delete(P->lptr,name);
	else if(strcmp(P->name,name)<0)
		P->rptr=Delete(P->rptr,name);
	else
	{
		if(P->lptr && P->rptr)
		{
			temp=findMin(P->rptr);	
			strcpy(P->name,temp->name);
			P->rptr = Delete(P->rptr,P->name);
					
		}
		else 
		{
			temp=P;
			if(P->rptr==NULL)
				P=P->lptr;
			else if(P->lptr==NULL)
				P=P->rptr;
			free(temp);
		}			
		
	}
	return P;
}


void dispTree(Player *P, int space) 
{ 
    if (P == NULL) 
        return; 
  
    space += COUNT; 
  
    dispTree(P->rptr, space); 
  
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%s\n", P->name); 
  
    dispTree(P->lptr, space); 
} 

void inorder(Player *P)
{
    printf("\n\n");
    if(P->lptr!=NULL)
      inorder(P->lptr);
    printf("\n  %s",P-> name);
    if(P->rptr!=NULL)
      inorder(P->rptr);
}


void preorder(Player *P)
{
    printf("\n  %s",P-> name);
    if(P->lptr!=NULL)
      preorder(P->lptr);
    if(P->rptr!=NULL)
      preorder(P->rptr);
}


void postorder(Player *P)
{
    printf("\n\n");
    if(P->lptr!=NULL)
      postorder(P->lptr);
    if(P->rptr!=NULL)
      postorder(P->rptr);
    printf("\n  %s",P-> name);
}


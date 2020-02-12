typedef struct data
{
	char word[30];
	char meaning[80];
}data;

typedef struct dict
{
	data x;
	int h;
	struct dict *left,*right;
}dict;

dict *init()
{
	dict *t=(dict *)malloc(sizeof(dict));
	t->left=NULL;
	t->right=NULL;
	t->h=0;
	return t;
}
int height(dict *d)
{
	if(d==NULL)
		return -1;
	else
		return d->h;
}

dict *singlerotatewithleft(dict *d)
{
	dict *d1;
	d1=d->left;
	d->left=d1->right;
	d1->right=d;
	
	d->h=(height(d->left) > height(d->right))?height(d->left)+1:height(d->right)+1;
	d1->h=(height(d1->left) > height(d))?height(d1->left)+1:height(d)+1;

	return d1;
}

dict *singlerotatewithright(dict *d)
{
	dict *d1;
	d1=d->right;
	d->right=d1->left;
	d1->left=d;
	
	d->h=(height(d->right) > height(d->left))?height(d->right)+1:height(d->left)+1;
	d1->h=(height(d1->right) > height(d))?height(d1->left)+1:height(d)+1;

	return d1;
}

dict *doublerotatewithleft(dict *d)
{
	d->left=singlerotatewithright(d->left);
	d=singlerotatewithleft(d);
	return d;
}

dict *doublerotatewithright(dict *d)
{
	d->right=singlerotatewithleft(d->right);
	d=singlerotatewithright(d);
	return d;
}	

dict *insert(dict *d,data w)
{
	if(d==NULL)
	{	
		d=init();
		d->x=w;
		
	}
	
	else if(strcmp(d->x.word,w.word)>0)
	{
		d->left=insert(d->left,w);
		int dif=height(d->left)-height(d->right);
		if(dif==2)
		{
			if(strcmp(d->left->x.word,w.word)>0)
				d=singlerotatewithleft(d);
			else
				d=doublerotatewithleft(d);
		}
	}
	else if(strcmp(d->x.word,w.word)<0)
	{
		d->right=insert(d->right,w);
		int dif=height(d->left)-height(d->right);
		if(dif==2)
		{
			if(strcmp(d->right->x.word,w.word)<0)
				d=singlerotatewithright(d);
			else
				d=doublerotatewithright(d);
		}
	}
	d->h=(height(d->left) > height(d->right))?height(d->left)+1:height(d->right)+1;
	return d;
}



dict *search(dict *d,char a[30])
{
	if(d==NULL)
		return NULL;
	else if(strcmp(d->x.word,a)>0)
		search(d->left,a);
	else if(strcmp(d->x.word,a)<0)
		search(d->right,a);
	else
		return d;
}

void dispTree(dict *d, int space) 
{ 
    if (d == NULL) 
        return; 
  
    space += COUNT; 
  
    dispTree(d->right, space); 
  
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("WORD: %s  MEANING: %s \n", d->x.word,d->x.meaning); 
  
    dispTree(d->left, space); 
} 
	





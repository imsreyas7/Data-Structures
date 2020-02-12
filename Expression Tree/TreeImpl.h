int Precedence(char op1){			//To check precedence between 2 operators
	int o1;
	switch(op1){
		case '+':
		case '-':
				o1=1;
				break;
		case '*':
		case '/':
				o1=2;
				break;
		case '^':
				o1=3;
				break;
	}

	return o1;
}

char *infixtoPostfix(char *str, Stack *s){		//  To convert the given infix expression 
														//(without involving parenthesis) into its 
	char *temp;													//postfix form using the stack
	int len=strlen(str);
	temp=(char *)malloc(sizeof(char)*len);
	int i=0,tc=0;

	while(i<len){
		if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='^')
		{

			if(isEmpty(s))
				push(s,str[i]);
			
			else
			{
				while((Precedence(s->arr[s->top])>=Precedence(str[i]))&&(!isEmpty(s)))
				{
					temp[tc]=pop(s);
					tc++;
				}
				push(s,str[i]);	
			}
			
		}

		else
			temp[tc++]=str[i];

		i++;
	}

	while(!isEmpty(s)){
		temp[tc]=pop(s);
		tc++;
	}

	return temp;
}

struct Tree *expressionTree(TreeStack *T, char *postfix){
	int len=strlen(postfix);
	int i=0;
	struct Tree *n,*temp1,*temp2;
	n=(struct Tree *)malloc(sizeof(struct Tree));
	temp1=(struct Tree *)malloc(sizeof(struct Tree));
	temp2=(struct Tree *)malloc(sizeof(struct Tree));
				

	while(i<len){		
		n->right=n->left=NULL;
		n->optr='0';		//allocating default operator as 0 for later programming simplicity
		if(postfix[i]>=48 && postfix[i]<=57){
			n->opnd=postfix[i]-48;
			pushT(T,n);
		}
	
		else{
			n->optr=postfix[i];
			temp1=popT(T);
			temp2=popT(T);
			n->right=temp1;
			n->left=temp2;
			pushT(T,n);
		}
		
		i++;
	}
	
	return popT(T);
}


int evaluateExpTree(struct Tree *t){
	if(t->optr!='0')
		switch(t->optr){
			case '+':
				return evaluateExpTree(t->right)+evaluateExpTree(t->left);
			case '-':
				return evaluateExpTree(t->left)-evaluateExpTree(t->right);
			case '*':
				return evaluateExpTree(t->right)*evaluateExpTree(t->left);
			case '/':
				return evaluateExpTree(t->left)/evaluateExpTree(t->right);
			case '^':				
				return pow(evaluateExpTree(t->left),evaluateExpTree(t->right));

		}

	else
		return t->opnd;
}


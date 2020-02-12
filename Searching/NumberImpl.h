void initADT(NumberADT *N, int size){
	N->size=size;
	N->a=(int *)malloc(sizeof(int)*size);
	N->cur_size=0;
}

void insertElements(NumberADT *N, int *a){
	int i=0;
	N->cur_size=0;
	int len=N->size;
	while(a[i]){
		N->a[i]=a[i];
		i++;
		N->cur_size++;
	}
}

int linearSearch(NumberADT *N, int x){
	int i=0;
	for(i=0;i<N->cur_size;i++){
		if(N->a[i]==x)
			return i;
	}
	return -1;
}

int binarySearch(NumberADT *N, int x){
	selectionSort(N);
	int left,right,mid;
	left=0;
	right=N->cur_size;
	while(left<=right){
		mid=(left+right)/2;

		if(N->a[mid]==x)
			return mid;
		else if(N->a[mid]<x)
			left=mid+1;
		else
			right=mid-1;
	}
	return -1;
}

void selectionSort(NumberADT *N){ 
    int i, j, min,temp;
    int n=N->cur_size;

    for(i=0;i<n-1;i++){ 
    	min=i; 
        for(j=i+1;j<n;j++) 
        	if (N->a[j]<N->a[min]) 
        		min=j;
        temp=N->a[min];
        N->a[min]=N->a[i];
        N->a[i]=temp;
    } 
}

void display(NumberADT *N){
	int n=N->cur_size;
	int i=0;
	printf("\nElements of the Array:\n");
	while(i<n){
		printf("%d\t",N->a[i]);
		i++;
	}
}
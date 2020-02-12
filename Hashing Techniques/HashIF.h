struct node{
	int data;
	struct node *next;
};

typedef struct{
	int size;
	struct node *list[100];
}HashTable;

void initHT(HashTable *H, int size);							//– To initialize the size and the header nodes of the lists
void insertElement (HashTable *H, int x);		//-To insert the input key into the hash table using the hash function
void searchElement(HashTable *H, int x); 		//– Searching an element in the hash table
void displayHT(HashTable *H);					//– Display the elements in the hash table
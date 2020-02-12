					 
//1. Basic Funtions
	void initialize (ListADT *l);  	// - To initialize member of ListADT function
	void computeResult (ListADT *l);// - To Compute total and assign the result of Each Student based on sub marks
	Student getInput(ListADT *l);	// - To get user input of the Student details

//2. Display Functions
	void display(Student S);		// - To display details of one student 
	void dispALL(ListADT l);		// - To display details of a set of stdents
	ListADT listResult	(ListADT l);// - To display details of students who have passed the exam
	int listClass (ListADT l);		// - To display details of students who got firstclass in exam

//3. Insert or push Functions
	void insertFront (ListADT *l , Student S);				// - Adds Student data at first,by moving others subsequently by one position
	void insertBack (ListADT *l , Student S);				// - Appends Student data to the list
	void insertRegno (ListADT *l , Student S , int regnum); // - Adds data after register regnum is encountered

//4. Search Functions
	Student searchRegNo (ListADT l , int regnum);	// - Search student data based on Register
	ListADT searchName (ListADT l , char Nm[]);		// - Search student data based on STudent's Name

//5. Delete or pop Function
	void delete (ListADT *l , int regnum);	// - Delete a record based on Register

//6. Mini Main FUnction
	void flowControl(ListADT *l, char choice); // - Used to control the flow of the Program



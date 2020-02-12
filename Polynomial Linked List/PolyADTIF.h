

struct poly* initPoly();
void insertFront(struct poly *p,int c,int e);
void insertEnd(struct poly *p,int c,int e);
int insertAfterTerm(struct poly *p,int c,int e,int sc,int se);
void polyDegree(struct poly *p);
void evaluatePoly(struct poly *p,int val);
void showPoly(struct poly *p);
struct poly* addPoly(struct poly *poly1,struct poly *poly2);
struct poly* findPrevious(struct poly *p,struct poly *elt);
void simplifyPoly(struct poly *p);
struct poly* multiplyPoly(struct poly *poly1,struct poly *poly2);
void MainMenu();
void Insertion();
struct node {
	int val;
	struct node *next;
};

//Implemented in Lab #9, but now return new head address
int length(struct node *);
void print(struct node *);
struct node * push(struct node *, int); //put at front
struct node * append(struct node *, int); //put at back

struct node * clear(struct node *);
struct node * remove1(struct node *, int);
struct node * sort_ascending(struct node *);
struct node * sort_descending(struct node *);
//insert into a specific location in the list
struct node * insert_middle(struct node *, int, int);
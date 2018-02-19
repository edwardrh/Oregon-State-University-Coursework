struct node {
	int val;
	struct node *next;
};

int length(struct node *);
void push(struct node **, int); //add to front of list
void append(struct node **, int); //add to rear of list

void print(struct node *, int);
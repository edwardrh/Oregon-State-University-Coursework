struct node {
	int info;
	struct node *next;
};

void divideList(struct node *,struct node **);
struct node * mergeList(struct node *,struct node *);
void recMergeSort(struct node **);
void mergeSort(struct node **, struct node **);
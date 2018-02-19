struct BSTree *buildBSTTree() {
    struct BSTree *tree	= newBSTree();		
		
    /*Create value of the type of data that you want to store*/
    struct datab *myData1 = (struct datab *) malloc(sizeof(struct datab));
    struct datab *myData2 = (struct datab *) malloc(sizeof(struct datab));
    struct datab *myData3 = (struct datab *) malloc(sizeof(struct datab));
    struct datab *myData4 = (struct datab *) malloc(sizeof(struct datab));
		
    myData1->numGifts = 50;
    myData1->cost = 123.63;
    myData2->numGifts = 13;
    myData2->cost = 55.56;
    myData3->numGifts = 110;
    myData3->cost = 250.00;
    myData4->numGifts = 10;
    myData4->cost = 9.99;
	
    /*add the values to BST*/
    addBSTree(tree, myData1);
    addBSTree(tree, myData2);
    addBSTree(tree, myData3);
    addBSTree(tree, myData4);
    
    return tree;
}

void printTestResult(int predicate, char *nameTestFunction, char *message){
    if (predicate)
	printf("%s(): PASS %s\n",nameTestFunction, message);
    else
	printf("%s(): FAIL %s\n",nameTestFunction, message);        
}

void testAddNode() {
    struct BSTree *tree	= newBSTree();
    
    struct datab myData1,  myData2,  myData3,   myData4;
		
    myData1.numGifts = 50;
    myData1.cost = 123.63;
    addBSTree(tree, &myData1);
    //check the root node
    if (compare(tree->root->val,&myData1) != 0) {
        printf("addNode() test: FAIL to insert 50 as root\n");
        return;
    }
    //check the tree->cnt value after adding a node to the tree
    else if (tree->cnt != 1) {
        printf("addNode() test: FAIL to increase count when inserting 50 as root\n");
        return;
    }
    else
	printf("addNode() test: PASS when adding 50 as root\n");
    
    
    myData2.numGifts = 13;
    myData2.cost = 55.56;
    addBSTree(tree, &myData2);
    
    //check the position of the second element that is added to the BST tree
    if (compare(tree->root->left->val,  &myData2) != 0) {
        printf("addNode() test: FAIL to insert 13 as left child of root\n");
        return;
    }
    else if (tree->cnt != 2) {
        printf("addNode() test: FAIL to increase count when inserting 13 as left of root\n");
        return;
    }
    else
	printf("addNode() test: PASS when adding 13 as left of root\n");
    
    
    myData3.numGifts = 110;
    myData3.cost = 250.00;
    addBSTree(tree, &myData3);
        
    //check the position of the third element that is added to the BST tree    
    if (compare(tree->root->right->val,  &myData3) != 0) {
        printf("addNode() test: FAIL to insert 110 as right child of root\n");
        return;
    }
    else if (tree->cnt != 3) {
        printf("addNode() test: FAIL to increase count when inserting 110 as right of root\n");
        return;
    }
    else
	printf("addNode() test: PASS when adding 110 as right of root\n");
    
    myData4.numGifts = 10;
    myData4.cost = 9.99;
    addBSTree(tree, &myData4);
    
    //check the position of the fourth element that is added to the BST tree
    if (compare(tree->root->left->left->val,  &myData4) != 0) {
        printf("addNode() test: FAIL to insert 10 as left child of left of root\n");
        return;
    }
    else if (tree->cnt != 4) {
        printf("addNode() test: FAIL to increase count when inserting 10 as left of left of root\n");
        return;
    }
    else
	printf("addNode() test: PASS when adding 10 as left of left of root\n");

    printf("Deleting the BSTree...\n");
    deleteBSTree(tree);
    printf("Returning from testAddNode().\n");
}

void testContainsBSTree() {
    struct BSTree *tree = buildBSTTree();
    
    struct datab myData1,  myData2,  myData3,  myData4, myData5;
	
    myData1.numGifts = 50;
    myData1.cost = 123.63;
    myData2.numGifts = 13;
    myData2.cost = 55.56;
    myData3.numGifts = 110;
    myData3.cost = 250.00;
    myData4.numGifts = 10;
    myData4.cost = 9.99;
    myData5.numGifts = 111;
    myData5.cost = 500.00;
    
    printTestResult(containsBSTree(tree, &myData1), "containsBSTree", "when test containing 50 as root");
        
    printTestResult(containsBSTree(tree, &myData2), "containsBSTree", "when test containing 13 as left of root");
    
    printTestResult(containsBSTree(tree, &myData3), "containsBSTree", "when test containing 110 as right of root");
        
    printTestResult(containsBSTree(tree, &myData4), "containsBSTree", "when test containing 10 as left of left of root");

    //check containsBSTree fucntion when the tree does not contain a node    
    printTestResult(!containsBSTree(tree, &myData5), "containsBSTree", "when test containing 111, which is not in the tree");

    printf("Deleting the BSTree...\n");
    deleteBSTree(tree);
    printf("Returning from testContainsBSTree().\n");

}

void testLeftMost() {
    struct BSTree *tree = buildBSTTree();
    
    struct datab myData3, myData4;

    myData3.numGifts = 110;
    myData3.cost = 250.00;
    myData4.numGifts = 10;
    myData4.cost = 9.99;
    
    printTestResult(compare(_leftMost(tree->root), &myData4) == 0, "_leftMost", "left most of root");
    
    printTestResult(compare(_leftMost(tree->root->left), &myData4) == 0, "_leftMost", "left most of left of root");
    
    printTestResult(compare(_leftMost(tree->root->left->left), &myData4) == 0, "_leftMost", "left most of left of left of root");
    
    printTestResult(compare(_leftMost(tree->root->right), &myData3) == 0, "_leftMost", "left most of right of root");

    printf("Deleting the BSTree...\n");
    deleteBSTree(tree);
    printf("Returning from testLeftMost().\n");

}

void testRemoveLeftMost() {
    struct BSTree *tree = buildBSTTree();
    struct Node *cur;
    
    cur = _removeLeftMost(tree->root);

    printTestResult(cur == tree->root, "_removeLeftMost", "removing leftmost of root 1st try");
    
    cur = _removeLeftMost(tree->root->right);
    printTestResult(cur == NULL, "_removeLeftMost", "removing leftmost of right of root 1st try");
   
    cur = _removeLeftMost(tree->root);
    printTestResult(cur == tree->root, "_removeLeftMost", "removing leftmost of root 2st try");
}

void testRemoveNode() {
    struct BSTree *tree = buildBSTTree();
    struct Node *cur;
    struct datab myData1,  myData2,  myData3,  myData4;
		
    myData1.numGifts = 50;
    myData1.cost = 123.63;
    myData2.numGifts = 13;
    myData2.cost = 55.56;
    myData3.numGifts = 110;
    myData3.cost = 250.00;
    myData4.numGifts = 10;
    myData4.cost = 9.99;
    
    _removeNode(tree->root, &myData4);
    printTestResult(compare(tree->root->val, &myData1) == 0 && tree->root->left->left == NULL, "_removeNode", "remove left of left of root 1st try");
	        
    _removeNode(tree->root, &myData3);
    printTestResult(compare(tree->root->val, &myData1) == 0 && tree->root->right == NULL, "_removeNode", "remove right of root 2st try");
	   
    _removeNode(tree->root, &myData2);
    printTestResult(compare(tree->root->val, &myData1) == 0 && tree->root->left == 0, "_removeNode", "remove right of root 3st try");
        
    cur = _removeNode(tree->root, &myData1);
    printTestResult(cur == NULL, "_removeNode", "remove right of root 4st try");
}
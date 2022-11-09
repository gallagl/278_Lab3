// LAB03BST2.c – Lab 03 – Liam, Gallagher

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

#define BST_FAIL 0
#define BST_SUCCESS 1

typedef struct Node{ // define the node
    int id; //hold the ID
    char *pass; //pointer to password string
    struct Node *leftChild, *rightChild;
} Node;

Node *initNode (int k, void *value)
// Allocate memory for new node and initialize fields.
// Returns pointer to node created.
{
    Node *n = malloc(sizeof(Node));
    // initialize node if memory obtained
    if (n != NULL)	{
        n->id = k;
        n->pass = value==NULL ? NULL : strdup (value);
        n->leftChild = NULL;
        n->rightChild = NULL;
    }
    return n;
}//initNode()

int insert(int k, void *v, Node *root)
// Function inserts a new node into the tree, with key k and value pointed to
// by v. Parameter root points to root node of tree.  Note that this code
// rejects an attempt to insert a duplicate key.
{
    int result = BST_FAIL; // this if statement can only be true with first root (root of whole tree)
    if (root == NULL)	{
        Node *n = initNode(k,v);
        root = n;
        return BST_SUCCESS;
    }

    // already exists in tree ==> want to replace!!
    if (root->id == k) {
        root->pass = v;
        result = BST_SUCCESS;
    }
    else if (k < root->id) {
        // key value less than key value in root node - try to insert into left
        // subtree, if it exists.
        if (root->leftChild != NULL)
            // there is a left subtree - insert it
            result = insert(k, v, root->leftChild);
        else {
            // new Node becomes the left subtree
            Node *n = initNode(k,v);
            root->leftChild = n;
            result = BST_SUCCESS;
        }
    } else if (k > root->id) {			// test actually redundant
        // key is greater than this nodes key value, so value goes into right
        // subtree, if it exists
        if (root->rightChild != NULL)
            // there is a right subtree - insert new node
            result = insert(k,v,root->rightChild);
        else {
            // no right subtree - new node becomes right subtree
            Node*n = initNode(k,v);
            root->rightChild = n;
            result = BST_SUCCESS;
        }
    }
    return result;
}//insert()

Node *findMin(Node *root) {
    Node *current = root;

    while (current->leftChild != NULL) { //traverse left in the tree
        current = current->leftChild;
    }
    return (current);
}

Node *findMax(Node *root) {
    Node *current = root;

    while (current->rightChild != NULL) { //traverse left in the tree
        current = current->rightChild;
    }
    return (current);
}

Node *find (int k, Node *root)
{
    // termination conditions - either true, search is ended
    if ((root == NULL) || (root->id == k))	return root;
    // search continues.  Since this is a search tree, we know that
    // every key in the right subtree is bigger than the key in the tree's
    // root, and every key in the left subtree is smaller than the key in
    // the tree's root.  That allows us to choose the appropriate subtree
    // to search.
    if (k > root->id)
        // Key value sought is larger than current node key, so search right
        // subtree
        return find(k,root->rightChild);
    else
        // Key value sought is smaller than current node key (the equal case
        // was handled as a termination condition in the first line), so
        // search left subtree
        return find(k,root->leftChild);
}//find()

Node* findParentHelper (int k, Node* root)

// Help find parent of node with key == k. Parameter root is node with
// at least one child (see findParent()).
{
    if ((root->leftChild != NULL && root->leftChild->id == k) || (root->rightChild != NULL && root->rightChild->id == k))
        return root;
    else if (k > root->id && root->rightChild != NULL)
        return findParentHelper(k, root->rightChild);
    else if (k < root->id && root->leftChild != NULL)
        return findParentHelper(k, root->leftChild);

    return NULL;

}//findparenthelper()

Node *findParent(int k, Node *root)
//
{
    // Deal with special special cases which could only happen for root
    // of whole tree
    if (root == NULL)	return root;
    // real root doesn't have parent so we make it parent of itself
    if (root->id == k)	return root;
    // root has no children
    if ((root->leftChild == NULL) && (root->rightChild == NULL))
        return NULL;

    // Deal with cases where root has at least one child
    return findParentHelper(k, root);
}//findParent()

void delete (Node *p, Node *n){
    Node *deleteNode = n;
    Node *minNode;

    if((n->leftChild != NULL) && (n->rightChild == NULL)) { // Node has only a left child
        if (p->id > n->id) {
            p->leftChild = n->leftChild;
            free(n);
        }else{
            p->rightChild = n->leftChild;
            free(n);
        }
    }else if((n->rightChild != NULL) && (n->leftChild == NULL)){ // Node has only a right child
        if (p->id > n->id) {
            p->leftChild = n->rightChild;
            free(n);
        }else{
            p->rightChild = n->rightChild;
            free(n);
        }
    }else if ((n->rightChild != NULL) && (n->leftChild != NULL)) {	// Node has both left and right children
        minNode = findMin(n->rightChild);
        n->id = minNode->id;
        Node* minParent = findParent(minNode->id,n);
        delete(minParent,minNode);
    } else	{ // Case where the node is a leaf
        if (p->id > n->id){
            p->leftChild = NULL;
            free(n);
        }else{
            p->rightChild = NULL;
            free(n);
        }
    }
}

int withdraw(int k, Node* root, Node* n)
// Withdraw does two things:
//	return a copy of the node with key k (and value v)
//	Delete the node with key k from the tree while ensuring the tree remains BST_SUCCESS
{
    Node *p, *m;
    m = find(k, root);

    if (m != NULL)	{
        // create a copy of the node with the same key and value
        n = initNode(m->id,m->pass);
        p = findParent(k,root);
        // can delete the node
        delete(p,m);
        return 1;
    }
    return 0;
}//withdraw()

typedef struct Tree{
    Node *root;
} Tree;

Tree *initTree(int k, void *value){
    Tree *t = malloc(sizeof(Tree));
    if (t != NULL)
        t->root = initNode(k, value);
    return t;
}
int bstCheck(Node* root){ // My function to determine if the BST is BST_SUCCESS.
    if (root == NULL) { // Empty tree case
        return BST_SUCCESS;
    }
    if ((root->leftChild != NULL) && (findMax(root->leftChild)->id > root->id)){ // If to the left of the current node there is a value larger, BST_FAIL tree.
        return BST_FAIL;
    }
    if ((root->rightChild != NULL) && (findMin(root->rightChild)->id < root->id)){ // If to the right of the current node there is a value smaller, BST_FAIL tree.
        return BST_FAIL;
    }
    if ((bstCheck(root->leftChild) == BST_FAIL)|| (bstCheck(root->rightChild) == BST_FAIL)){ // Checks again (recursively) for the left and right children of the current node.
        return BST_FAIL;
    }
    return BST_SUCCESS; // If none of the other cases were reached, the whole tree was traversed and no errors were found, therefore it is a BST_SUCCESS tree.
}

int main(){
    Tree *myTree = {NULL};

    // read in the IDENTS file
    FILE* ptr = fopen("IDENTS.txt", "r");
    if (ptr == NULL) {
        printf("no such file.");
        return 0;
    }
    int employeeid;
    char password[30]; // Char array to store passwords as they are read in.
    int count = 0; // Count number of nodes added (id-password sets).

    while (fscanf(ptr, "%d", &employeeid) == 1) { // while lines are being read
        char ch;
        int i = 0;

        do {
            ch = fgetc(ptr);
        } while (ch == ' ');
        do {
            password[i] = ch;
            i++;
            ch = fgetc(ptr); // get next character
        } while (ch != '\r' && ch != '\n'); // For length of the string
        password[i] = '\0';

        if (count == 0) { // if it's the first time, initialize the tree
            myTree = initTree(employeeid, password);
            count++;
        }
        else{ // otherwise insert the nodes to the tree
            insert(employeeid, password, myTree->root);
            count++;
        }
    }
    fclose(ptr); //close file

    printf("Number of nodes before deletion: %d \n", count); // print the number of nodes
    if (bstCheck(myTree->root) == 1) //check if the BST is BST_SUCCESS. Print BST_SUCCESS BST if it is, otherwise exit the program
        printf("BST_SUCCESS\n");
    else {
        printf("BST_FAIL\n");
        return 0;
    }
    // Open the file with the deleting information
    FILE* ptrd = fopen("DELETES.txt", "r");

    Node *n = NULL;
    int c;
    while (fscanf(ptrd, "%d", &employeeid) == 1){ // if an employee id can be found
        c = withdraw(employeeid, myTree->root, n); //withdraw the value
        if (c == 1) //if the value is found and removed, remove 1 from the value of count
            count--;
        else printf("<NOT FOUND>");
    }
    fclose(ptrd); //close file

    printf("Number of nodes after deletion: %d \n", count); // print the number of nodes after the deletions
    if (bstCheck(myTree->root) == 1) //check if the tree is still BST_SUCCESS, if so print that it is, otherwise exit the code
        printf("BST_SUCCESS\n");
    else {
        printf("BST_FAIL\n");
        return 0;
    }

    FILE* ptrl = fopen("LOOKUPS.txt", "r"); // Opens the LOOKUPS file

    Node *f;
    while (fscanf(ptrl, "%d", &employeeid) == 1){ //while there are ids to be found
        f = find(employeeid, myTree->root); //find the node
        printf("ID %d PASSWORD %s \n", employeeid, f->pass); // Prints the id number and the password
    }
    fclose(ptrl); //close file


    return 0;
}
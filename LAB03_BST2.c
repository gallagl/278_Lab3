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

void delete (Node *p, Node *n)
// Delete node pointed to by n.
// Parameters:
//	n	- points to node to be deleted
//	p	- points to parent of node to be deleted.
{
    // Deletion has 3 cases - no subtrees, only left or right subtree, or both
    // left and right subtrees.
    Node *deleteNode = n;		// Save copy of pointer to node to delete;
    Node *temp;

    if ((n->leftChild != NULL) && (n->rightChild == NULL)) {			// there is left child
        if (p->id > n->id) {
            p->leftChild = n->leftChild;
            free(deleteNode);
        }
        else if (p->id < n->id){
            p->rightChild = n->leftChild;
            free(deleteNode);
        }

    } else if ((n->rightChild != NULL) && (n->leftChild == NULL)) {			// there is a right child
        if (p->id > n->id){
            p->leftChild = n->rightChild;
            free(deleteNode);
        }
        else if (p->id < n->id){
            p->rightChild = n->rightChild;
            free(deleteNode);
        }

    } else if ((n->rightChild == NULL) && (n->leftChild == NULL)){							// no children
        if (n->id >= p->id) {
            p->rightChild = NULL;
            free (deleteNode);
        }
        else if (n->id <= p->id){
            p->leftChild = NULL;
            free (deleteNode);
        }


    } else if ((n->rightChild != NULL) && (n->leftChild != NULL)){ //two children
        temp = findMin(n->rightChild);
        n->id = temp->id;
        n->pass = temp->pass;
        Node *rent = findParent(temp->id, n);

        delete(rent, temp);
    }
}//delete()

int withdraw(int k, Node* root, Node* n)
// Withdraw does two things:
//	return a copy of the node with key k (and value v)
//	Delete the node with key k from the tree while ensuring the tree remains valid
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

int treeChecker(Node* root){ //function to check the tree
    if (root == NULL)
        return BST_SUCCESS;
    if (root->leftChild != NULL && root->leftChild->id > root->id)
        return BST_FAIL;
    if (root->rightChild != NULL && root->rightChild->id < root->id)
        return BST_FAIL;
    return treeChecker(root->leftChild);
    return treeChecker(root->rightChild);
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
    char passwordbuffer[20];
    int count =0;

    while (fscanf(ptr, "%d", &employeeid) == 1) { // while lines are being read
        char ch;
        int i = 0;

        do {
            ch = fgetc(ptr);
        } while (ch == ' ');
        do {
            passwordbuffer[i] = ch;
            i++;
            ch = fgetc(ptr); // get next character
        } while (ch != '\r' && ch != '\n');
        passwordbuffer[i] = '\0';

        if (count == 0) { // if it's the first time, initialize the tree
            myTree = initTree(employeeid, passwordbuffer);
            count++;
        }
        else{ // otherwise insert the nodes to the tree
            insert(employeeid, passwordbuffer, myTree->root);
            count++;
        }
    }
    fclose(ptr); //close file

    printf("BST NODES: %d \n", count); // print the number of nodes
    if (treeChecker(myTree->root) == 1) //check if the BST is valid. Print valid BST if it is, otherwise exit the program
        printf("Valid BST \n\n");
    else
        return 0;

    // Open the file with the deleting information
    FILE* ptrd = fopen("DELETES.txt", "r");

    Node *n = NULL;
    int c;
    while (fscanf(ptrd, "%d", &employeeid) == 1){ // if an employee id can be found
        c = withdraw(employeeid, myTree->root, n); //withdraw the value
        if (c == 1) //if the value is found and removed, remove 1 from the value of count
            count--;
        else
            printf("ID %d <NOT FOUND>", employeeid); // if the value is not in the list output error message
    }
    fclose(ptrd); //close file

    printf("NODES AFTER DELETES: %d \n", count); // print the number of nodes after the deletions
    if (treeChecker(myTree->root) == 1) //check if the tree is still valid, if so print that it is, otherwise exit the code
        printf("Valid BST \n\n");
    else
        return 0;

    FILE* ptrl = fopen("LOOKUPS.txt", "r"); //open LOOKUPS file

    Node *f;
    while (fscanf(ptrl, "%d", &employeeid) == 1){ //while there are ids to be found
        f = find(employeeid, myTree->root); //find the node
        if (f == NULL) // if node not found, tell the user
            printf("ID %d PASSWORD <NOT FOUND>", employeeid);
        else
            printf("ID %d PASSWORD %s \n", employeeid, f->pass); //if the id is found, print the id number and the password
    }
    fclose(ptrl); //close file


    return 0;
}
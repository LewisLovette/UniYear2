#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class BinaryTree{
    public:
        int value;
        BinaryTree* left;
        BinaryTree* right;

        BinaryTree(int value){  //Constructor
            this->value = value;
            this->left = NULL;
            this->right = NULL;
        }
};

//Recursive, if left or right child isn't empty, call itself one place down each time until there's a free space
BinaryTree* insertNode(BinaryTree* node, int value){
    
    if(node == NULL){
        node = new BinaryTree(value);
    }
    if(value > node->value){
        if(node->right == NULL){
            node->right = new BinaryTree(value);
        }
        else{
            insertNode(node->right, value);
        }
    }
    else{
        if(node->left == NULL){
            node->left = new BinaryTree(value);
        }
        else{
            insertNode(node->left, value);
        }
    }
    return node;
}

BinaryTree* binaryTreeFindParent(BinaryTree* node, int value){
    if(node->value == value or node == 0){
        cout << node->value << endl;
        return node;
    }

    //Checks children, if child has the target then it returns the parent of the child.
    if(node->left != NULL){
        if(node->left->value == value){
            cout << "left child " << node->left->value << endl;
            return node;
        }
    }
    if(node->right != NULL){
        if(node->right->value == value){
            cout << "right child " << node->right->value << endl;
            return node;
        }
    }

    if(value < node->value){
        return binaryTreeFindParent(node->left, value);
    }
    else{
        return binaryTreeFindParent(node->right, value);
    }

    cout << node->value << endl;
    return node;
}

int countChildren(BinaryTree* node){
    int numOfChildren = 0;

    if(node->left != NULL) numOfChildren++;
    if(node->right != NULL) numOfChildren++;

    return numOfChildren;
}

//Deleting a value from the node - means we need to search for that value and then..
BinaryTree* deleteNode(BinaryTree* node, int value){ 
    //Set node to the parent of the node to be removed
    bool left = true;
    if(node->left->value != value) left = false;    //right child has the value;

    node = binaryTreeFindParent(node, value);
    int children = 0;

    if(left == true){
        countChildren(node->left);
    }
    else{
        countChildren(node->right);
    }
    
    if(children == 0){  //leaf, just remove the leaf
        (left == true) ? node->left = NULL : node->right = NULL;
    }
    else if(children == 1){ //branch, place parent equal to the branches child
        if(left == true){
            (node->left->left != NULL) ? node->left = node->left->left : node->left = node->left->right;
        }
        else{
            (node->right->right != NULL) ? node->right = node->right->right : node->right = node->right->left;
        }
    }
    else{
        
    }

    return node;
}

//Taken from CUMOODLE - START
void postorder(BinaryTree* tree) {
	if (tree->left != NULL)
		postorder(tree->left);
	if (tree->right != NULL)
		postorder(tree->right);
	cout << tree->value << endl;
}

void in_order(BinaryTree* tree) {
	if (tree->left != NULL)
		in_order(tree->left);
	cout << tree->value << endl;
	if (tree->right != NULL)
		in_order(tree->right);
}
//END

int main(){

    BinaryTree* t = insertNode(0, 6);
	insertNode(t, 10);
	insertNode(t, 5);
	insertNode(t, 2);
	insertNode(t, 3);
	insertNode(t, 4);
	insertNode(t, 11);
    in_order(t);

    //binaryTreeFindParent(t, 11);
    
    deleteNode(t, 10);
    in_order(t);

	return 0;
}
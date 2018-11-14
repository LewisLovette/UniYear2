#include<bits/stdc++.h>
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
}

//Deleting a value from the node - means we need to search for that value and then..
BinaryTree* deleteNode(BinaryTree* node, int value){ 
    //Note, should be reversed as needs to check if there are children from most to least children.

    return node;
}

BinaryTree* binaryTreeFindParent(BinaryTree* node, int value){

    if(node->left->value == value or node->right->value == value){
        return node;
    }
    else if(value < node->value){
        return binaryTreeFindParent(node->left, value);
    }
    else{
        return binaryTreeFindParent(node->right, value);
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

	return 0;
}
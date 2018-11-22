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
BinaryTree* insertNode(BinaryTree* tree, int item) {
	if (tree == NULL)
		tree = new BinaryTree(item);
	else
		if (item < tree->value)
			if (tree->left == NULL)
				tree->left = new BinaryTree(item);
			else
				insertNode(tree->left, item);
		else
			if (tree->right == NULL)
				tree->right = new BinaryTree(item);
			else
				insertNode(tree->right, item);
	return tree;

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
    int children = 0;
    if(node->value == value){   //if head node is the value
        cout << "Test 1" << endl;

        children = countChildren(node);

        BinaryTree* temp;

        if(children == 1){
            if(node->right != NULL){
                temp = node->right;    //setting temp to the position to be remove

                if(temp->left != NULL){
                    while(temp->left->left != NULL) temp = temp->left;

                    node->value = temp->left->value;
                    temp->left = NULL;
                }
                else{
                    node->value = node->left->value;
                    node->left = node->left->left;
                }
            }
        } 
        else{   //has 2 children
            temp = node->right;    //setting temp to the position to be remove

            if(temp->left != NULL){
                while(temp->left->left != NULL) temp = temp->left;

                node->value = temp->left->value;
                temp->left = temp->left->left;
            }
            else{
                node->value = node->right->value;
                node->right = node->right->right;
            }
        }
        
        return node;
    }

    //Set node to the parent of the node to be removed
    bool isLeft;
    node = binaryTreeFindParent(node, value);

    if(node->left != NULL){
        (node->left->value == value) ? isLeft = true : isLeft = false;  //value = to left or right of node
    }
    else{
        isLeft = false;
    }

    
    //Count number of children
    if(isLeft == true){
        children = countChildren(node->left);
    }
    else{
        children = countChildren(node->right);
    }

    cout << "Test 3:" << children << endl;

    
    if(children == 0){  //leaf, just remove the leaf
        cout << "Children == 0" << endl;
        if(isLeft == true){
            node->left = NULL;
        } 
        else{
            node->right = NULL;
        }
    }
    else if(children == 1){ //branch, place parent equal to the branches child
        cout << "Children == 1" << endl;
        if(isLeft == true){
            (node->left->left != NULL) ? node->left = node->left->left : node->left = node->left->right;
        }
        else{
            (node->right->right != NULL) ? node->right = node->right->right : node->right = node->right->left;
        }
    }
    else{   //the value has 2 children
        cout << "Children == 2" << endl;
        //Find min value from the left
        BinaryTree* temp;
        (isLeft == true) ? temp = node->left : temp = node->right;    //setting temp to the position to be remove
        temp = temp->right;

        //find parent of minimum value to the left
        if(temp->left == NULL){ //no values to the left
            //edge case where pointer left is NULL so first right value is the min
            if(isLeft == true){
                node->left->right->left = node->left->left; //so node->left->left child connects with node->left->right pointer
                node->left = node->left->right;
            }
            else{
                node->right->right->left = node->right->left; //so node->right->left child connects with node->right->right pointer
                node->right = node->right->right;
            }
        }
        else{
            while(temp->left->left != NULL) temp = temp->left;  //getting parent of the minimum value

            //swap
            (isLeft == true) ? node->left->value = temp->left->value : node->right->value = temp->left->value;

            temp->left = NULL;
        }
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

//TAKEN FROM - https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c - START
void printBT(const std::string& prefix, const BinaryTree* node, bool isLeft)
{
    if( node != NULL )
    {
        cout << prefix;

        cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        cout << node->value << endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}
//END

int main(){
    /*
    BinaryTree* t = insertNode(0, 30);
    insertNode(t, 15);
    insertNode(t, 7);
    insertNode(t, 9);
    insertNode(t, 31);
    insertNode(t, 37);
    insertNode(t, 40);
    insertNode(t, 39);
    insertNode(t, 8);
    insertNode(t, 33);
    */

    BinaryTree* t = insertNode(0, 20);
    insertNode(t, 10);
    insertNode(t, 5);
    insertNode(t, 15);
    insertNode(t, 18);
    insertNode(t, 16);
    insertNode(t, 30);
    insertNode(t, 28);
    insertNode(t, 40);
    insertNode(t, 35);
    insertNode(t, 32);
    insertNode(t, 33);
    insertNode(t, 46);

	int temp;

    printBT("", t, false);
    cout << endl;
    
    while(true){
        cin >> temp;
        if(temp == 0) break;
        deleteNode(t, temp);

        printBT("", t, false);
        cout << endl;
    }

	return 0;
}
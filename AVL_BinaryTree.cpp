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

}


int main(){



    return 0;
}
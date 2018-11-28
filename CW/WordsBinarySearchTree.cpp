#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

class BinaryTree{
    public:
        int frequency;
        string value;
        BinaryTree* left;
        BinaryTree* right;

        BinaryTree(string value){  //Constructor
            this->frequency = 1;
            this->value = value;
            this->left = NULL;
            this->right = NULL;
        }
};

//Recursive, if left or right child isn't empty, call itself one place down each time until there's a free space
BinaryTree* insertNode(BinaryTree* tree, string item) {
	if (tree == NULL)
		tree = new BinaryTree(item);
	else
        if(item == tree->value){
            tree->frequency += 1;
        }
		else if (item.compare(tree->value) < 0)
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

BinaryTree* findNode(BinaryTree* tree, string target) {

    if (tree == NULL){
		cout << endl << "NO" << endl;
        return tree;
    }
	else{
        if(target == tree->value){
            cout << target << endl << endl;
            cout << "YES" << endl << endl;
            return tree;
        }
		else if (target.compare(tree->value) < 0){
            cout << tree->value << endl;
            return findNode(tree->left, target);
        }
        else{
            cout << tree->value << endl;
            return findNode(tree->right, target);
        }
    }

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
	cout << tree->value  << " frequency: " << tree->frequency << endl;
	if (tree->right != NULL)
		in_order(tree->right);
}
//END

void preOrder(BinaryTree* tree) {
    cout << tree->value << endl;
	if (tree->left != NULL)
		preOrder(tree->left);
	if (tree->right != NULL)
		preOrder(tree->right);
}

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
    string temp;

    ifstream file("C:\\Users\\lewis\\Documents\\GitHub\\UniYear2\\210CT-CPP-Coursework\\bstWords.txt");
    if (!file.is_open()){
        cout << "Error reading file" << endl;
        return 0;
    }

    file >> temp;
    BinaryTree* t = insertNode(0, temp);

    int numberOfWords = 7;  //num of words - 1

    for(int i = 0; i < numberOfWords; i++){
        file >> temp;
        insertNode(t, temp);
    }

    file.close();

    printBT("", t, false);
    cout << endl;

    in_order(t);
    cout << endl;
    preOrder(t);
    cout << endl;

    cout << "Find Node: " << endl;
    findNode(t, "class");

    cout << "Find Node: " << endl;
    findNode(t, "do");

    return 0;
}
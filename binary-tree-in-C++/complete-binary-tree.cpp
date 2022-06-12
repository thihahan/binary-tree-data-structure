#include <iostream>
using namespace std;

// create Node
class Node{
public:
    int data;
    Node *left, *right;

    Node(){
        this->left = this->right = NULL;
    }
};

// search the number of nodes
int nodes(Node* root){
    if(root == NULL){
        return 0;
    }
    return 1+nodes(root->left) + nodes(root->right);
}

// check complete binary tree
bool isCbt(Node* root, int number_of_nodes, int index){
    if(root == NULL){
        return true;
    }
    if(index >= number_of_nodes){
        return false;
    }
    return isCbt(root->left, number_of_nodes, (2 * index) + 1) &&
        isCbt(root->right, number_of_nodes, (2 * index) + 2);
}

int main(){
    Node *root = new Node();
    root->data = 1;
    root->left = new Node();
    root->left->data = 2;
    root->right = new Node();
    root->right->data = 3;
    root->left->left = new Node();
    root->left->left->data = 4;
    root->left->left = new Node();
    root->left->left->data = 5;
    if(isCbt(root, nodes(root), 0)){
        cout << "This is complete binary tree" << endl;
    }else{
        cout << "This is not complete binary tree" << endl;
    }
    return 2;
}
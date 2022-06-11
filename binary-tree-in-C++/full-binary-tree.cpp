#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;

    Node(){
        this->left = this->right = NULL;
    }
};

// test is full binary tree
bool isFbt(Node* root){
    if(root == NULL){
        return true;
    }
    if(root->left && root->right){
        return isFbt(root->left) && isFbt(root->right);
    }
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    if(root->left || root->right){
        return false;
    }
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
    root->left->right = new Node();
    root->left->right->data = 5;
    root->right->left = new Node();
    root->right->left->data = 6;
    root->right->right = new Node();
    root->right->right->data = 7;
    if(isFbt(root)){
        cout << "This is full binary tree" << endl;
    }else{
        cout << "This is not full binary tree" << endl;
    }
    return 0;
}
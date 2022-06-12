#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;

    Node(int data){
        this->data = data;
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
    return false;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    if(isFbt(root)){
        cout << "This is full binary tree" << endl;
    }else{
        cout << "This is not full binary tree" << endl;
    }
    return 0;
}
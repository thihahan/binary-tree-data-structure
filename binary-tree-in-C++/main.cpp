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

// count the number of nodes
int count(Node* root){
    if(root == NULL){
        return 0;
    }else{
        return 1+count(root->left) + count(root->right);
    }
}

//finds the depth of the tree
int depth(Node* root){
    Node *temp = root;
    int i = 0;
    while (temp != NULL){
        temp = temp->left;
        i++;
    }
    return i;
}

//test perfect binary tree
bool isPbt(Node* root, int depth, int current_depth){
    if(root == NULL){
        return true;
    }
    if(root->left && root->right){
        return isPbt(root->left, depth, current_depth+1) && isPbt(root->right, depth, current_depth+1);
    }
    if(root->left == NULL && root->right == NULL){
        if(depth == current_depth){
            return true;
        }else{
            return false;
        }
    }
    if(root->left || root->right){
        return false;
    }
}

// test complete binary tree
bool isCbt(Node* root,int last_index, int current_index){
    if(root == NULL){
        return true;
    }
    if(root->left == NULL && root->right == NULL){
        if(last_index <= current_index){
            return false;
        }else{
            return true;
        }
    }
    if(root->left || root->right){
        return isCbt(root->left, last_index, 2*current_index+1) && isCbt(root->right,last_index, 2*current_index + 2);
    }
}

int main() {
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
    if(isCbt(root, count(root), 0)){
        cout << "This is complete binary Tree" << endl;
    }else{
        cout << "This is not complete binary Tree" << endl;
    }
    if(isPbt(root, depth(root), 1)){
        cout << "This is perfect binary tree" << endl;
    }else{
        cout << "This is not perfect binary tree" << endl;
    }
    return 0;
}
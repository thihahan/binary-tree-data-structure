#include <iostream>
using namespace std;

//create a node
class Node{
public:
    int data;
    Node *left, *right;

    Node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};

//check balanced binary tree
bool isBalancedBinaryTree(Node* root, int *height){
    int leftH = 0, rightH = 0;
    int l =0 , r = 0;
    if(root == NULL){
        *height = 0;
        return 1;
    }
    l = isBalancedBinaryTree(root->left, &leftH);
    r = isBalancedBinaryTree(root->right, &rightH);
    *height = (leftH > rightH ? leftH : rightH)+1;
    if((leftH - rightH >= 2) || (rightH - leftH >= 2)){
        return 0;
    }else{
        return l && r;
    }
}

int main(){
    int height = 0;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
//    root->left->left->left = new Node(6);
    if(isBalancedBinaryTree(root, &height)){
        cout << "This is balanced binary tree" << endl;
    }else{
        cout << "This is not balanced binary tree" << endl;

    }
}
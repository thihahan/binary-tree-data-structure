#include <iostream>
using namespace std;

// create Node
class Node{
public:
    int data;
    Node *left, *right;

    Node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};
// search depth
int depth(Node* root){
    Node* temp = root;
    int i=0;
    while(temp != NULL){
        temp = temp->left;
        i++;
    }
    return i;
}

//test perfect-binary-tree
bool isPbt(Node* root, int depth, int level){
    if(root == NULL){
        return true;
    }
    if(root->left == NULL && root->right == NULL){
        return depth == level+1;
    }
    if(root->left && root->right){
        return isPbt(root->left, depth, 1+level) && isPbt(root->right, depth, 1+level);
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
    bool is_perfect_binary_tree = isPbt(root, depth(root), 0);
    if(is_perfect_binary_tree){
        cout << "this is perfect binary tree" << endl;
    }else{
        cout << "this is not perfect binary tree" << endl;
    }
    return 1;
}
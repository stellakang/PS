#include <iostream>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
};

node* add(node* root, int number);
void postOrder(node* cur);
int main(){
    node* root=NULL;
    while(true){
        int number;
        cin>>number;
        if(cin.eof())break;
        root = add(root, number);
    }
    postOrder(root);
    return 0;
}
node* add(node* root, int number){
    if(root==NULL){
        root = new node;
        root->val = number;
        return root;
    }
    if(number<root->val){
        root->left = add(root->left, number);
    }
    else{
        root->right = add(root->right, number);
    }
    return root;
}
void postOrder(node* cur){
    if(cur->left){
        postOrder(cur->left);
    }
    if(cur->right){
        postOrder(cur->right);
    }
    cout<<cur->val<<"\n";
}

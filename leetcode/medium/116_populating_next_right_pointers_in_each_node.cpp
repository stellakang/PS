/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)return root;
        
        queue<pair<Node*, int>>qu;
        qu.push(make_pair(root,0));
        pair<Node*,int> pre = {NULL, 0};
        
        while(!qu.empty()){
            pair<Node*,int>p = qu.front();
            qu.pop();
            
            if(pre.first && pre.second==p.second){
                pre.first->next = p.first;
            }
            pre = p;
            if(p.first->left)
                qu.push(make_pair(p.first->left, p.second+1));
            if(p.first->right)
                qu.push(make_pair(p.first->right, p.second+1));
        }
        return root;
    }
};

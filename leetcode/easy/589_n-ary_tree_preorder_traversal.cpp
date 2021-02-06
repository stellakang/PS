/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {   
public:
    vector<int> preorder(Node* root) {
        stack<Node*>iter;
        iter.push(root);
        
        vector<int>res;
        while(!iter.empty()){
            Node* cur = iter.top();
            iter.pop();
            
            if(!cur)continue;
            res.push_back(cur->val);
            
            int sz = cur->children.size();
            for(int i=sz-1;i>=0;i--){
                iter.push(cur->children[i]);
            }
        }
        return res;
    }
};

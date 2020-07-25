/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*>qu;
        qu.push(root);
        qu.push(root);
        
        while(!qu.empty()){
            TreeNode* t1=qu.front();qu.pop();
            TreeNode* t2=qu.front();qu.pop();
            if(!t1&&!t2)continue;
            if(!t1||!t2)return false;
            if(t1->val!=t2->val)return false;
            qu.push(t1->left);
            qu.push(t2->right);
            qu.push(t1->right);
            qu.push(t2->left);
        }
        return true;
    }
};

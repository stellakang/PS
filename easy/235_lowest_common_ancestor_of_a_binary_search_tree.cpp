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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *left=p,*right=q;
        if(p->val>q->val){
            left=q;
            right=p;
        }
        
        if(root->val<left->val)
            return lowestCommonAncestor(root->right,left,right);
        else if(root->val>right->val)
            return lowestCommonAncestor(root->left,left,right);
        return root;
    }
};

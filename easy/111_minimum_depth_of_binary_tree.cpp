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
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        if(!root->left && !root->right)return 1;
        int minVal=0xfffffff;
        if(root->left)
            minVal=min(minVal,1+minDepth(root->left));
        if(root->right)
            minVal=min(minVal,1+minDepth(root->right));
        return minVal;
    }
};

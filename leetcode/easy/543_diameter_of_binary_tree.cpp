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
    int ans=0;
    int diameterOfBinaryTree(TreeNode* root) {
        getMaximumDepth(root);
        return ans;
    }
    
    int getMaximumDepth(TreeNode* root){
        if(root==NULL)return 0;
        
        int leftTree=0,rightTree=0;
        if(root->left!=NULL)leftTree=getMaximumDepth(root->left)+1;
        if(root->right!=NULL)rightTree=getMaximumDepth(root->right)+1;
        
        if(ans<leftTree+rightTree)
            ans=leftTree+rightTree;
        return max(leftTree,rightTree);
    }
};

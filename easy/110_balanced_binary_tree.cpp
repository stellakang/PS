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
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        bool leftNode,rightNode;
        int leftHeight=depth(root->left);
        int rightHeight=depth(root->right);
        if(leftHeight-rightHeight>1 || rightHeight-leftHeight>1)
            return false;
        leftNode=isBalanced(root->left);
        rightNode=isBalanced(root->right);
        return leftNode&&rightNode;
    }
    int depth(TreeNode* node){
        if(!node)return 0;
        return 1+max(depth(node->left),depth(node->right));
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int num = -2147483647;
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)return true;
        bool ret = true;
        if(root->left)
            ret = ret && isValidBST(root->left);
        if(num != -2147483647 && num >= root->val)
            ret = false;
        num = root->val;
        if(root->right)
            ret = ret && isValidBST(root->right);
        
        return ret;
    }
};

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
    int maxVal=INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        maxPathWithCurrent(root);
        return maxVal;
    }
    int maxPathWithCurrent(TreeNode* node){
        int update = node->val;
        int left=INT_MIN,middle,right=INT_MIN;
        if(node->left){
            left = maxPathWithCurrent(node->left);
            update = max(update, left+node->val);
        }
        if(node->right){
            right = maxPathWithCurrent(node->right);
            update = max(update, right+node->val);
        }
        if(node->right && node->left)
            maxVal = max(maxVal,left+right+node->val);
        maxVal = max(update,maxVal);
        return update;  
    }
};



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
    bool hasPathSum(TreeNode* root, int sum) {
        queue<pair<TreeNode*,int>>q;
        if(!root)return false;
        q.push(make_pair(root,root->val));
        while(!q.empty()){
            TreeNode* curNode=q.front().first;
            int curSum=q.front().second;
            q.pop();
            if(curSum==sum && (!curNode->left && !curNode->right))
                return true;
            if(curNode->left)
                q.push(make_pair(curNode->left,curSum+curNode->left->val));
            if(curNode->right)
                q.push(make_pair(curNode->right,curSum+curNode->right->val));
        }
        return false;
    }
};

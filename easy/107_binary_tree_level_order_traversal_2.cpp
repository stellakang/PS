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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        if(root)
            q.push(make_pair(root,0));
        vector<int> v;
        vector<vector<int>>levelOrder;
        int cnt=0;
        while(!q.empty()){
            TreeNode* frontNode=q.front().first;
            int lev=q.front().second;
            q.pop();
            if(cnt==lev)
                v.push_back(frontNode->val);
            else{
                levelOrder.push_back(v);
                v.clear();
                v.push_back(frontNode->val);
                cnt++; 
            }
            if(frontNode->left)
                q.push(make_pair(frontNode->left,lev+1));
            if(frontNode->right)
                q.push(make_pair(frontNode->right,lev+1));
        }
        if(v.size())
            levelOrder.push_back(v);
        reverse(levelOrder.begin(),levelOrder.end());
        return levelOrder;
    }
};

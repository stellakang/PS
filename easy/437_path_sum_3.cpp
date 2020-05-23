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
public:
    int pathSum(TreeNode* root, int sum) {
        int cnt=0;
        if(root){
            queue<pair<TreeNode*,int>>q;
            q.push(make_pair(root,sum));
            while(!q.empty()){
                TreeNode* node=q.front().first;
                int restSum=q.front().second;
                q.pop();
                if(restSum==node->val)cnt++;
                if(node->left)
                    q.push(make_pair(node->left,restSum-node->val));
                if(node->right)
                    q.push(make_pair(node->right,restSum-node->val));
            }
            cnt+=pathSum(root->left, sum);
            cnt+=pathSum(root->right, sum);
        }
        return cnt;
    }
};

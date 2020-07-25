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
    unordered_map<TreeNode*,TreeNode*>toParent;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K){
        dfs(root,NULL);
        queue<pair<TreeNode*,int>>q;
        unordered_map<int,bool>visit;
        vector<int> distNode;
        
        q.push(make_pair(target,K));
        visit[target->val]=true;
        
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int k=q.front().second;
            q.pop();
            if(k==0)
                distNode.push_back(node->val);
            
            TreeNode* leftNode=node->left;
            TreeNode* rightNode=node->right;
            TreeNode* parentNode=toParent[node];
            if(leftNode && !visit[leftNode->val]){
                q.push(make_pair(leftNode,k-1));
                visit[leftNode->val]=true;
            }
            if(rightNode && !visit[rightNode->val]){
                q.push(make_pair(rightNode,k-1));
                visit[rightNode->val]=true;
            }
            if(parentNode && !visit[parentNode->val]){
                q.push(make_pair(parentNode,k-1));
                visit[parentNode->val]=true;
            }
        }
        return distNode;
    }
    void dfs(TreeNode* node, TreeNode* parent){
        if(parent!=NULL)
            toParent[node]=parent;
        if(node->left)
            dfs(node->left,node);
        if(node->right)
            dfs(node->right,node);
    }
};

//solution1
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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL)return {};
        
        vector<int>inorder;
        unordered_map<TreeNode*,bool>um;
        
        stack<TreeNode*>st;
        st.push(root);
        um[root]=true;
        
        while(!st.empty()){
            TreeNode* node = st.top();
            if(node->left && !um[node->left]){
                st.push(node->left);
                um[node->left]=true;
                continue;
            }
            inorder.push_back(node->val);
            st.pop();
            if(node->right && !um[node->right]){
                st.push(node->right);
                um[node->right]=true;
            }
        }
        return inorder;
    }
};

//solution2
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        stack<TreeNode*>st;
        TreeNode* curr = root;
        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        return inorder;
    }
};

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
    vector<string>paths;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
         if(root==NULL)return {};
         findPaths(root, "");
         return paths;
    }
    void findPaths(TreeNode* node, string path){
        if(path.size()>0)
            path+="->";
        path+=to_string(node->val);
       
        if(node->left)
            findPaths(node->left,path);
        if(node->right)
            findPaths(node->right,path);
        if(node->left==NULL && node->right==NULL)
            paths.push_back(path);
    }
};

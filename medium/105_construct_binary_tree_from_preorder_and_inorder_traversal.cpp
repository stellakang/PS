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
    unordered_map<int,int>preToIndx,inToIndx;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* tree=NULL;
        if(preorder.size()==0)return tree;
        
        for(int i=0;i<preorder.size();i++)
            preToIndx[preorder[i]]=i;
        for(int i=0;i<inorder.size();i++)
            inToIndx[inorder[i]]=i;
        
        tree=buildTreeFunc(0,inorder.size()-1,preorder,inorder);
        return tree; 
    }
    TreeNode* buildTreeFunc(int start, int end, vector<int>&preorder, vector<int>&inorder){
        if(start>end)return NULL;
        int minPos=preToIndx[inorder[start]];
        for(int i=start+1;i<=end;i++){
            int pos=preToIndx[inorder[i]];
            if(minPos>pos)
                minPos=pos;
        }
        TreeNode* node=new TreeNode(preorder[minPos]);
        int point=inToIndx[preorder[minPos]];
        node->left=buildTreeFunc(start,point-1,preorder,inorder);
        node->right=buildTreeFunc(point+1,end,preorder,inorder);
        return node;
    }
};

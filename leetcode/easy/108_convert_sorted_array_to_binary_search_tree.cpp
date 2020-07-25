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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* node=sortedArrayToBST(nums,0,nums.size()-1);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
        if(start>end)return NULL;
        int mid=(start+end)/2;
        //TreeNode tmp(nums[mid]);
        TreeNode* node=new TreeNode(nums[mid]);
        node->left=sortedArrayToBST(nums,start,mid-1);
        node->right=sortedArrayToBST(nums,mid+1,end);
        return node;
    }
};


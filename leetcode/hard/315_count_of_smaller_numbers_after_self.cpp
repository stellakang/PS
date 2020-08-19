#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        int h = int(ceil(log2(n)));
        int sz = 1 << (h+1);
        vector<int>tree(sz);
        vector<pair<int, int>> pairs;
        for(int i=0;i<n;i++){
            pairs.push_back(make_pair(nums[i], i));
        }
        sort(pairs.begin(), pairs.end());
        vector<int>result;
        for(int i=0;i<n;i++){
            update(tree, 1, 0, n-1, pairs[i].second);
            int cnt = query(tree, 1, 0, n-1, pairs[i].second+1, n-1);
            result.push_back(cnt);
        }
        return result;
    }
    int update(vector<int>&tree, int node, int start, int end, int indx){
        if(indx<start || indx>end)return 0;
        if(start==end) return tree[node] = 1;
        int mid = (start+end)/2;
        int l = update(tree, node*2, start, mid, indx);
        int r = update(tree, node*2+1, mid+1, end, indx);
        return tree[node] = l + r;
    }
    int query(vector<int>&tree, int node, int start, int end, int left, int right){
        if(right<start || end<left)return 0;
        if(left<=start && end<=right)return tree[node];
        int mid = (start + end)/2;
        int l = query(tree, node*2, start, mid, left, right);
        int r = query(tree, node*2+1, mid+1, end, left, right);
        return l+r;
    }
};

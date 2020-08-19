//solution1 
//segment tree
typedef pii pair<int,int>;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return {};
        int h = int(ceil(log2(n)));
        int sz = 1 << (h+1);
        vector<int>tree(sz,0);
        vector<pii>pairs;
        for(int i=0;i<n;i++){
            pairs.push_back(make_pair(nums[i], i));
        }
        sort(pairs.begin(), pairs.end());
        for(int i=0;i<n;i++){
            update(tree, 1, 0, n-1, pairs[i].second);
            int cnt = query(tree, 1, 0, n-1, pairs[i].second+1, n-1);
            pairs[i].first = cnt;
        }
        sort(pairs.begin(), pairs.end(),[](pii a, pii b){
            return a.second<b.second;
        });
        vector<int>result;
        for(pii p: pairs){
            result.push_back(p.first);
        }
        return result;
    }
    int update(vector<int>&tree, int node, int start, int end, int indx){
        if(indx<start || end<indx)return tree[node];
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

//solution2
//binary search tree
struct bst{
    int val;
    int smaller;
    bst *left;
    bst *right;
};
int curSmaller;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n);
        bst* root = NULL;
        for(int i=n-1;i>=0;i--){
            curSmaller = 0;
            root = insert(root, nums[i]);
            result[i] = curSmaller;
        }
        return result;
    }
    bst* insert(bst *root, int number){
        if(root==NULL){
            bst * node = new bst();
            node->val = number;
            node->left = NULL;
            node->right = NULL;
            node->smaller = 0;
            return node;
        }
        if(root->val >= number){
            root->smaller++;
            root->left = insert(root->left, number);
        }
        else{
            curSmaller += root->smaller+1;
            root->right = insert(root->right, number);
        }
        return root;
    }
};

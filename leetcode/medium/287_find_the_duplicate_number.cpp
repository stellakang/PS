class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        vector<bool>check(n+1,false);
        for(int i=0;i<=n;i++){
            if(check[nums[i]])return nums[i];
            check[nums[i]] = true;
        }
        return -1;
    }
};

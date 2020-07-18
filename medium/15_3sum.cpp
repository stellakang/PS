class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int sz=nums.size();
        vector<vector<int>>ret;
        sort(nums.begin(),nums.end());
        for(int i=0;i<sz;){
            int left=i+1,right=sz-1;
            while(left<right){
                int sum=nums[left]+nums[right]+nums[i];
                if(sum==0){
                    ret.push_back({nums[i], nums[left], nums[right]});
                    int leftVal=nums[left++];
                    while(left<right && nums[left]==leftVal)
                        left++;
                }
                else if(sum>0)
                    right--;
                else
                    left++;
            }
            i++;
            while(i<sz && nums[i]==nums[i-1])
                i++;
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int sz=nums.size();
        sort(nums.begin(),nums.end());
        
        vector<vector<int>>quadruplets;
        for(int i=0;i<sz-3;){
            for(int j=i+1;j<sz-2;){
                int left=j+1,right=sz-1;
                while(left<right){
                    int sum=nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum<target)
                        left++;
                    else if(sum>target)
                        right--;
                    else{
                        quadruplets.push_back({nums[i],nums[j],nums[left],nums[right]});
                        int leftVal=nums[left++];
                        while(left<sz && nums[left]==leftVal)
                            left++;
                    }
                }
                j++;
                while(j<sz-2 && nums[j]==nums[j-1])
                    j++;
            }
            i++;
            while(i<sz-3 && nums[i]==nums[i-1])
                i++;
        }
        return quadruplets;
    }
};

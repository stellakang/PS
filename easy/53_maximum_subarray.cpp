class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
        if(sz==0)return 0;
        
        int max_num=nums[0];
        int prev=nums[0];
        
        for(int i=1;i<sz;i++){
            prev=max(prev+nums[i],nums[i]);
            if(max_num<prev)
                max_num=prev;
        }
        return max_num;
    }
};

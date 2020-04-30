class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int candidate;
        for(int i=0;i<n;i++){
            if(cnt==0)candidate=nums[i];
            if(nums[i]==candidate)
                cnt++;
            else
                cnt--;
        }
        return candidate;
    }
};

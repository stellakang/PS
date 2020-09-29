class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int numSz = nums.size();
        
        int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(left>=numSz || nums[left] != target)return {-1, -1};
        int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return {left, right-1};
    }
};

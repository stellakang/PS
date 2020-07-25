class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int sz = nums.size();
        unordered_map<int,int>checker;
        
        for(int i=0;i<sz;i++){
            if(checker.find(target-nums[i])!=checker.end()){
                return {checker[target-nums[i]],i};
            }
            checker.insert(make_pair(nums[i],i));
        }
        return {0};
    }
};

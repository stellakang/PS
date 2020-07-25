class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int sz=nums.size();
        unordered_set<int>num_list;
        for(int i=0;i<sz;i++){
            if(num_list.find(nums[i])!=num_list.end())return true;
            num_list.insert(nums[i]);
        }
        return false;
    }
};

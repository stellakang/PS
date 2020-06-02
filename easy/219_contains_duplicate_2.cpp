class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int sz=nums.size();
        unordered_map<int,int>numbers;
        for(int i=0;i<sz;i++){
            if(numbers[nums[i]]>0 && i-numbers[nums[i]]<k)return true;
            numbers[nums[i]]=i+1;
        }
        return false;
    }
};

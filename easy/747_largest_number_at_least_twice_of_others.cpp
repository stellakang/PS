class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max=-1;
        int ind=-1;
        for(int i=0;i<nums.size();i++){
            if(max<nums[i]){
                max=nums[i];
                ind=i;
            }
        }
        
        for(int i=0;i<nums.size();i++){
            if(i==ind)continue;
            if(nums[i]*2>max)
                return -1;
        }
        return ind;
    }
};

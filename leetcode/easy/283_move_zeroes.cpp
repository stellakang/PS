class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz=int(nums.size());
        int front_zero=0xfffffff;
        for(int i=0;i<sz;i++){
            if(nums[i]==0 && front_zero>i){
                front_zero=i;
            }
            else if(nums[i]!=0 && front_zero<i){
                swap(nums[i],nums[front_zero]);
                front_zero++;
            }
        }
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(cnt==0)
                cnt++;
            else if(nums[cnt-1]!=nums[i]){
                nums[cnt]=nums[i];
                cnt++;
            } 
        }
        return cnt;
    }
};

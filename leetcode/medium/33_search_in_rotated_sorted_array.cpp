class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        int dx = 1;
        if(target<nums[0])
            dx = -1;
        
        int n = sz;
        int i = 0;
        while(n--){
            if(target == nums[i]){
                return i;
            }
            else if(target > nums[i]){
                if(dx == -1)return -1;
            }
            else{
                if(dx==1)return -1;
            }
            int prev = i;
            i = (i + dx + sz)%sz;
            if(dx==1 && nums[i] < nums[prev])return -1;
            if(dx==-1 && nums[i] > nums[prev])return -1;
        }
        return -1;
    }
};

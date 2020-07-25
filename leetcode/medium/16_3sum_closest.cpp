class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sz=nums.size();
        sort(nums.begin(),nums.end());
        
        int sum=nums[0]+nums[1]+nums[2];
        for(int i=0;i<sz-2;i++){
            int left=i+1,right=sz-1;
            while(left<right){
                int v=nums[i]+nums[left]+nums[right];
                if(abs(target-sum)>=abs(target-v))
                    sum=v;
                if(v<target)
                    left++;
                else
                    right--;
            }
        }
        return sum;
    }
};

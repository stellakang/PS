class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> missing;
        int sz=nums.size();
        for(int i=0;i<sz;i++){
            if(nums[i]==i+1)continue;
            int indx=i;
            int number=nums[i];
            nums[i]=0;
            while(indx+1!=number && number!=0){
                int nextIndx=number-1;
                int nextNum=nums[nextIndx];
                nums[nextIndx]=number;
                
                number=nextNum;
                indx=nextIndx;
            }
        }
        for(int i=0;i<sz;i++){
            if(nums[i]==0)
                missing.push_back(i+1);
        }
        return missing;
    }
};

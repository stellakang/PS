class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3]={0,0,0};
        int sz = nums.size();
        for(int i=0;i<sz;i++){
            int c = nums[i];
            count[c]++;
        }
        int indx = 0;
        for(int i=0;i<3;i++){
            int c = count[i];
            for(int j=0;j<c;j++){
                nums[indx++] = i;
            }
        }
    }
};

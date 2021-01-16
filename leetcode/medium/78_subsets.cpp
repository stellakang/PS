vector<vector<int>>answer;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        answer.clear();
        int sz = nums.size();
        vector<int>tmp;
        for(int i=0;i<=sz;i++){
            combination(-1,0,i,tmp,nums);
        }
        return answer;
    }
    void combination(int indx, int cnt, int length, vector<int>&num, vector<int>&nums){
        if(cnt==length){
            answer.push_back(num);
            return;
        }
        for(int i=indx+1;i<=nums.size()-(length-cnt);i++){
            num.push_back(nums[i]);
            combination(i,cnt+1,length,num,nums);
            num.pop_back();
        }
    }
};

class Solution {
public:
    static bool cmp(int& a, int& b){
        string aa = to_string(a);
        string bb = to_string(b);
        return aa+bb>bb+aa;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        int n = nums.size();
        string ret = "";
        if(nums[0]==0)return "0";
        for(int i=0;i<n;i++){
            ret += to_string(nums[i]);
        }
        return ret;
    }
};

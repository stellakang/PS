class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left=nums.size();
        int right=-1;
        int sz=nums.size();
        
        stack<int>st;
        for(int i=0;i<sz;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                left=min(left, st.top());
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i=sz-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]){
                right=max(right, st.top());
                st.pop();
            }
            st.push(i);
        }
        if(right>=left)return right-left+1;
        return 0;
    }
};

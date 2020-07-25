class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int sz=nums.size();
        stack<int>st;
        vector<int>minArr;
        minArr.resize(sz);
        for(int i=0;i<sz;i++){
            if(i==0)
                minArr[i]=nums[i];
            else
                minArr[i]=min(nums[i],minArr[i-1]);
        }
        for(int i=sz-1;i>=0;i--){
            if(st.empty() || st.top()>=nums[i]){
                st.push(nums[i]);
                continue;
            }
            if(minArr[i]<st.top())
                return true;
            else{
                while(!st.empty() && minArr[i]>=st.top())
                    st.pop();
                if(!st.empty() && st.top()<nums[i] && minArr[i]<st.top())
                    return true;
                if(st.empty() || st.top()>nums[i])
                    st.push(nums[i]);
            }
        }
        return false;
    }
};

class Solution {
public:
    int compress(vector<char>& chars) {
        int sz=chars.size();
        int cnt=0;
        int indx=0;
        if(sz==0)return 0;
        for(int i=0;i<sz;i++){
            if(i==0 || (i!=0 && chars[i]!=chars[i-1])){
                if(cnt>1){
                    stack<char>st;
                    while(cnt){
                        st.push(cnt%10+'0');
                        cnt/=10;
                    }
                    while(!st.empty()){
                        chars[indx++]=st.top();
                        st.pop();
                    }
                }
                cnt=1;
                chars[indx++]=chars[i];
            }
            else
                cnt++;
            
        }
        if(cnt>1){
            stack<char>st;
            while(cnt){
                st.push(cnt%10+'0');
                cnt/=10;
            }
            while(!st.empty()){
                chars[indx++]=st.top();
                st.pop();
            }
        }
        return indx;
    }
};



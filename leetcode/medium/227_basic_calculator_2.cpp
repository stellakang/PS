class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int len = s.length();
        int result = 0;
        char op = '+';
        for(int i=0;i<len;i++){
            if(s[i]>='0' && s[i]<='9'){
                result = result*10 + (s[i]-'0');
            }
            if((s[i]!=' ' && (s[i]<'0'||s[i]>'9'))||i==len-1){
                if(op=='+'){
                    st.push(result);
                }
                else if(op=='-'){
                    st.push(-result);
                }
                else if(op=='*'){
                    st.top() = st.top()*result;
                }
                else if(op=='/' && result!=0){
                    st.top() = st.top()/result;
                }
                result = 0;
                op = s[i];
            }
        }
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        return result;
    }
};

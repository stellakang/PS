class Solution {
public:
    void reverseString(vector<char>& s) {
        int sz=s.size();
        for(int i=0;i<sz/2;i++){
            char tmp=s[sz-i-1];
            s[sz-i-1]=s[i];
            s[i]=tmp;
        }
    }
};

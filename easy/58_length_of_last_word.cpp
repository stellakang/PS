class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt=0;
        bool haveBig=false;
        for(int i=s.length()-1;i>=0;i--){
            if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z'))
                cnt++;
            else if(s[i]==' '){
                if(cnt>0)return cnt;
                cnt=0;
            }
        }
        return cnt;
    }
};

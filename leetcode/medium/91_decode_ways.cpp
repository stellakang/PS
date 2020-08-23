class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if(len==0)return 0;
        int dp[len+1];
        dp[0] = 1;
        for(int i=0;i<len;i++){
            dp[i+1] = 0;
            //one digit
            int number = s[i]-'0';
            if(number>=1 && number<=9){
                dp[i+1] += dp[i];
            }
            if(i==0)continue;
            //two digits
            number += (s[i-1]-'0')*10;
            if(number>=10 && number<=26){
                dp[i+1] += dp[i-1];
            }
        }
        return dp[len];
    }
};

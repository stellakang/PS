class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.length();
        string longest;
        if(len==0)return longest;
        
        bool dp[len][len];
        for(int i=0;i<len;i++)
            for(int j=0;j<len;j++)
                dp[i][j]=false;
        
        for(int i=0;i<len;i++){
            dp[i][i]=true;
            if(longest.length()<1)
                longest=s[i];
            if(i!=len-1 && s[i]==s[i+1]){
                dp[i][i+1]=true;
                if(longest.length()<2)
                    longest=s.substr(i,2);
            }
        }
        
        for(int i=2;i<len;i++){
            for(int j=0;j<len-i;j++){
                if(dp[j+1][j+i-1]==false)continue;
                if(s[j]==s[j+i]){
                    dp[j][j+i]=true;
                    if(i+1>longest.length())
                        longest=s.substr(j,i+1);
                }
            }
        }
        return longest;
    }
};

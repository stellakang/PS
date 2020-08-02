class Solution {
public:
    int numSquares(int n) {
        vector<int>dp;
        dp.resize(n+1,0x7fffffff);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i] = min(dp[i], 1 + dp[i-j*j]);
            }
        }
        return dp[n];
    }
};

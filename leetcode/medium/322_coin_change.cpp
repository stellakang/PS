class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        for(int i=0;i<=amount;i++){
            dp[i] = 0x7fffffff;
        }
        dp[0] = 0;
        int num = coins.size();
        for(int i=0;i<num;i++){
            int coin = coins[i];
            for(int j=1;j<=amount;j++){
                if(j-coin>=0 && dp[j-coin]!=0x7fffffff && dp[j-coin]+1<dp[j]){
                    dp[j] = dp[j-coin]+1;
                }
            }
        }
        if(dp[amount]==0x7fffffff)
            return -1;
        return dp[amount];
    }
};

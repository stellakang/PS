class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_val=0;
        int max_profit=0;
        for(int i=prices.size()-1;i>=0;i--){
            if(prices[i]>=max_val)
                max_val=prices[i];
            else{
                max_profit+=max_val-prices[i];
                max_val=prices[i];
            }
        }
        return max_profit;
    }
};

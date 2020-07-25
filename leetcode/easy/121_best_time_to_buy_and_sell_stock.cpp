class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfitVal=0;
        int minVal=0xfffffff;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minVal)
                minVal=prices[i];
            if(prices[i]-minVal>maxProfitVal)
                maxProfitVal=prices[i]-minVal;
        }
        return maxProfitVal;
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        
        for(int i=0;i<len;i++){
            int amount = 0;
            for(int j=i;j<i+len;j++){
                int indx = j%len;
                amount += gas[indx];
                amount -= cost[indx];
                if(amount<0)break;
            }
            if(amount>=0)return i;
        }
        return -1;
    }
};

class Solution {
public:
    int countPrimes(int n) {
        int cnt=0;
        vector<bool>primes(n,true);
        for(int i=2;i<n;i++){
            if(!primes[i])continue;
            int multiple=i;
            cnt++;
            while(multiple+i<n){
                multiple+=i;
                primes[multiple]=false;
            }
        }
        return cnt;
    }
};

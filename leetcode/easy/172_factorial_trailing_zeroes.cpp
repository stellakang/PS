class Solution {
public:
    int trailingZeroes(int n) {
        int two=0;
        int five=0;
        
        int num=2;
        while(num<=n){
            two+=n/num;
            if(num>INT_MAX/2)break;
            num*=2;
        }
        num=5;
        while(num<=n){
            five+=n/num;
            if(num>INT_MAX/5)break;
            num*=5;
        }
        return min(two,five);
    }
};

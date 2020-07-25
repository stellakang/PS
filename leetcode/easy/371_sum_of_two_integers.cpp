class Solution {
public:
    int getSum(int a, int b) {
        int sum=a^b;
        int c=((unsigned int)a&b)<<1;
        while(c!=0){
            int nextC=((unsigned int)sum&c)<<1;
            sum^=c;
            c=nextC;
        }
        return sum;
    }
};


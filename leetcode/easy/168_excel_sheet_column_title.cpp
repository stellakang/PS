class Solution {
public:
    string convertToTitle(int n) {
        string str;
        while(true){
            n--;
            int left=n%26;
            n/=26;
            char c='A'+left;
            str=c+str;
            if(n==0)break;
        }
        return str;
    }
};


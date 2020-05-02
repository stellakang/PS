class Solution {
public:
    int titleToNumber(string s) {
        int len=s.length();
        int number=0;
        for(int i=0;i<len;i++){
            int num=s[i]-'A'+1;
            number*=26;
            number+=num;
        }
        return number;
    }
};

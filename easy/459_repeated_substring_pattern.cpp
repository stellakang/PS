class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int length=s.length();
        for(int i=0;i<length/2;i++){
            if(length%(i+1))continue;
            string sub=s.substr(0,i+1);
            string mul;
            for(int j=0;j<length/(i+1);j++)
                mul+=sub;
            if(s==mul)return true;
        }
        return false;
    }
};

class Solution2 {
public:
    bool repeatedSubstringPattern(string s) {
        string s2=s+s;
        if(s2.find(s,1)<s.size())return true;
        return false;
    }
};

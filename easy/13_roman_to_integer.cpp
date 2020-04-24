class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>chartoInt={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},                                                  {'D',500},{'M',1000}};
        
        int ret=0;
        int length=s.length();
        for(int i=0;i<length;i++){
            char c = s.at(i);
            int num = chartoInt[c];
            if(i!=length-1 && num<chartoInt[s.at(i+1)])
                ret-=num;
            else
                ret+=num;
        }
        return ret;
    }
};


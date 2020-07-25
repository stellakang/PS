class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        
        string zigzag;
        int len=s.length();
        for(int i=1;i<=numRows;i++){
            int up=0,skip=1;
            for(int j=i-1;j<len;j+=skip){
                if(skip!=0)
                    zigzag+=s[j];
                if(up==0)
                    skip=(numRows-i)*2;
                else
                    skip=(i-1)*2;
                up=(up+1)%2;
            }
        }
        return zigzag;
    }
};

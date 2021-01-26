class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int strlen = s.length();
        int wlen = wordDict.size();
        
        vector<bool>check(strlen,false);
        
        for(int i=0;i<strlen;i++){
            for(int j=0;j<wlen;j++){
                int sz = wordDict[j].length();
                if(i-sz+1<0)continue;// out of range
                if(s.substr(i-sz+1,sz) != wordDict[j])continue;// different string
                if(i-sz+1==0 || check[i-sz])
                    check[i] = true;
            }
        }
        return check[strlen-1];
    }
};

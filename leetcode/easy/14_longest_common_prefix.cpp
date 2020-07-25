class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string lcp = "";
        int lcpLength=0;
        int strLength = strs.size();
        
        if(strLength == 0)
            return lcp;
        
        while(true){
            if(lcpLength>=strs[0].length())
                break;
            char c1 = strs[0].at(lcpLength);
            int i;
            for( i=1;i<strLength;i++){
                if(strs[i].length()<=lcpLength)break;
                char c2 = strs[i].at(lcpLength);
                if(c1 != c2)break;
            }
            if(i!=strLength)
                break;
            lcp+=c1;
            lcpLength++;
        }
        return lcp;
    }
};

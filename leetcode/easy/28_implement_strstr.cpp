class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int needleSize = needle.length();
        
        int indx = haystack.find(needle);
        if(indx==string::npos)return -1;
        else return indx;
    }
};

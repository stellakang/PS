class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int>mapS;
        unordered_map<char,int>mapT;
        
        if(s.length()!=t.length())return false;
        
        int sz=s.length();
        for(int i=0;i<sz;i++){
            if(mapS[s[i]]!=mapT[t[i]])return false;
            mapS[s[i]]=i+1;
            mapT[t[i]]=i+1;
        }
        return true;
    }
};

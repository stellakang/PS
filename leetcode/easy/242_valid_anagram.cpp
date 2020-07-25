class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>um;
        int slen=s.length();
        int tlen=t.length();
        for(int i=0;i<slen;i++)
            um[s[i]]++;
        for(int i=0;i<tlen;i++)
            um[t[i]]--;
        for(pair<int,int>ch:um){
            if(ch.second)return false;
        }
        return true;
    }
};

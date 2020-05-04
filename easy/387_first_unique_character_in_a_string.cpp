class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>um;
        int strlen=s.length();
        for(int i=0;i<strlen;i++)
            um[s[i]]++;
        
        for(int i=0;i<strlen;i++){
            if(um[s[i]]==1)return i;
        }
        return -1;
    }
};

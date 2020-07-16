class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>cnt;
        for(int i=0;i<magazine.length();i++)
            cnt[magazine[i]]++;
        for(int i=0;i<ransomNote.length();i++){
            char c=ransomNote[i];
            if(cnt[c]==0)
                return false;
            cnt[c]--;
        }
        return true;
    }
};

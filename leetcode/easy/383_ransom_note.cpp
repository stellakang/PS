class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int mlen=magazine.length();
        int rlen=ransomNote.length();
        unordered_map<char,int>cnt;
        for(int i=0;i<mlen;i++)
            cnt[magazine[i]]++;
        for(int i=0;i<rlen;i++){
            char c=ransomNote[i];
            if(cnt[c]==0)
                return false;
            cnt[c]--;
        }
        return true;
    }
};

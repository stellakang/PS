//solution1 
// O(N)/O(M) the number of unique words str
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        string token;
        stringstream ss(str);
        
        unordered_map<char,string>ctostr;
        unordered_map<string,char>strtoc;
        
        for(char c:pattern){
            if(getline(ss, token, ' ')){
                if(ctostr.find(c)==ctostr.end() && strtoc.find(token)==strtoc.end()){
                    ctostr[c]=token;
                    strtoc[token]=c;
                }
                else if(ctostr[c]!=token || strtoc[token]!=c)
                    return false;
            }
            else
                return false;
        }
        if(getline(ss, token, ' '))return false;
        return true;
    }
};

//solution2 
//O(N)/O(M)
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int num=1;
        string token;
        stringstream ss(str);
        unordered_map<string,int>mapping;
        
        for(int i=0;i<pattern.length();i++){
            string s(1,pattern[i]);
            s="char_"+s;
            if(getline(ss, token, ' ')){
                token = "string_"+token;
                if(mapping.find(s)==mapping.end() && mapping.find(token)==mapping.end()){
                    mapping[s]=num;
                    mapping[token]=num++;
                }
                else if(mapping[s]!=mapping[token])
                    return false;
            }
            else
                return false;
        }
        if(getline(ss, token, ' '))return false;
        return true;
    }
};

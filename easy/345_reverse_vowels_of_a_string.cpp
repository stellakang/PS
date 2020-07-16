class Solution {
public:
    string reverseVowels(string s) {
        int len=s.length();
        int start=0,end=len-1;
        
        while(start<end){
            char c1=s[start], c2=s[end];
            bool isvowel1=false,isvowel2=false;
            
            isvowel1=isVowelOrNot(c1);
            isvowel2=isVowelOrNot(c2);
            
            if(isvowel1 && isvowel2){
                s[start++]=c2;
                s[end--]=c1;
                continue;
            }
            if(!isvowel1)
                start++;
            if(!isvowel2)
                end--;   
        }
        return s;
    }
    bool isVowelOrNot(char c){
        if(c=='a'||c=='i'||c=='u'||c=='o'||c=='e')
            return true;
        if(c=='A'||c=='I'||c=='U'||c=='O'||c=='E')
            return true;
        return false;
    }
};

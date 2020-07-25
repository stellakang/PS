class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int spointer=0,tpointer=0;
        for(int i=0;i<S.length();i++){
            if(S[i]=='#'){
                if(spointer>0)
                    spointer--;
                continue;
            }
            S[spointer++]=S[i];
        }
        for(int i=0;i<T.length();i++){
            if(T[i]=='#'){
                if(tpointer>0)
                    tpointer--;
                continue;
            }
            T[tpointer++]=T[i];
        }
        if(spointer!=tpointer)return false;
        for(int i=0;i<spointer;i++){
            if(S[i]!=T[i])return false;
        }
        return true;
    }
};

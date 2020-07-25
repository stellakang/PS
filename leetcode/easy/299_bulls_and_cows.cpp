class Solution {
public:
    string getHint(string secret, string guess) {
        int a=0,b=0;
        int checker[10]={0};
        
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i])
                a++;
            else
                checker[secret[i]-'0']++;
        }
        for(int i=0;i<guess.size();i++){
            if(secret[i]!=guess[i] && checker[guess[i]-'0']>0){
                checker[guess[i]-'0']--;
                b++;
            }
        }
        string ret="";
        ret+=to_string(a);
        ret+='A';
        ret+=to_string(b);
        ret+='B';
        return ret;
    }
    
};

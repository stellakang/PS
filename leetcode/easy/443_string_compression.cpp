class Solution {
public:
    int compress(vector<char>& chars) {
        int sz=chars.size();
        int start=0;
        int indx=0;
        if(sz==0)return 0;
        for(int i=0;i<sz;i++){
            if(i+1==sz || chars[i]!=chars[i+1]){
                chars[indx++]=chars[i];
                if(i>start){
                    vector<char>c;
                    int cnt=i-start+1;
                    while(cnt){
                        c.push_back(cnt%10+'0');
                        cnt/=10;
                    }
                    for(int s=c.size()-1;s>=0;s--)
                        chars[indx++]=c[s];
                }
                start=i+1;
            }
        }
        return indx;
    }
};

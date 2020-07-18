class Solution {
public:
    int myAtoi(string str) {
        int i=0;
        int len=str.length();
        
        while(i<len && str[i]==' ')
            i++;
        
        int sign=1;
        if(i<len && (str[i]=='+'||str[i]=='-')){
            if(str[i]=='-')
                sign=-1;
            i++;
        }
        long long num=0;
        while(i<len && str[i]>='0' && str[i]<='9'){
            num=num*10+(str[i++]-'0');
            if(num*sign>INT_MAX)
                return INT_MAX;
            if(num*sign<INT_MIN)
                return INT_MIN;
        }
        return num*sign;
    }
};

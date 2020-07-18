class Solution {
public:
    string intToRoman(int num) {
        string roman;
        unordered_map<int,char>symbol={{1,'I'}, {5,'V'}, {10,'X'}, {50,'L'}, {100,'C'}, {500,'D'}, {1000,'M'}};
        
        int digit=1000;
        while(num){
            int val=num/digit;
            num%=digit;
            if(val==4 || val==9){
                roman+=symbol[digit];
                roman+=symbol[digit*(val+1)];
                val=0;
            }
            if(val>=5){
                roman+=symbol[digit*5];
                val-=5;
            }
            while(val--)
                roman+=symbol[digit];
            digit/=10;
        }
        return roman;
    }
};

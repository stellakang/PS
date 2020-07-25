class Solution {
public:
    string addBinary(string a, string b) {
        int carryBit=0;
        string sum;
        int pointA=a.length()-1;
        int pointB=b.length()-1;
        
        while(pointA>=0 || pointB>=0){
            int aval=0,bval=0;
            if(pointA>=0)aval=a[pointA--]-'0';
            if(pointB>=0)bval=b[pointB--]-'0';
            
            int sumval=carryBit+aval+bval;
            if(sumval==2 || sumval==3){
                carryBit=1;
                sumval-=2;
            }
            else
                carryBit=0;
            sum=to_string(sumval)+sum;
        }
        if(carryBit>0)
            sum='1'+sum;
        return sum;
    }
};

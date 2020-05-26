//solution1
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1)
            return true;
        if(n==0 || n%3!=0)
            return false;
        return isPowerOfThree(n/3);
    }
};

//solution2
class Solution {
public:
    bool isPowerOfThree(int n) {
        while(true){
            if(n==1)return true;
            if(n==0 || n%3!=0)return false;
            n/=3;
        }
        return false;
    }
};

//solution3
class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n>1){
            int b=n%3;
            n/=3;
            if(b!=0)return false;
        }
        if(n==1)return true;
        return false;
    }
};

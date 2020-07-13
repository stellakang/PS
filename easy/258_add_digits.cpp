// solution1
// O(1) maximum iteration number is 3/ O(1) 
class Solution {
public:
    int addDigits(int num) {
        int add = 0;
        while(num>0){
            add += num%10;
            num/=10;
        }
        
        if(add>=10)
            add = add%10 + add/10;
        if(add>=10)
            return add%10 + add/10;
        return add;
    }
};

// solution2
// O(1)/O(1)
class Solution {
public:
    int addDigits(int num) {
        if(num==0)return 0;
        
        int mod9=num%9;
        if(mod9==0)return 9;
        return mod9;
    }
};





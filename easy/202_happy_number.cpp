class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>nums;
        int number=n;
        while(true){
            int squareSum=0;
            if(nums.find(number)!=nums.end())return false;
            nums.insert(number);
            while(number){
                int s=number%10;
                squareSum+=s*s;
                number/=10;
            }
            if(squareSum==1)return true;
            number=squareSum;
        }
    }
};

class Solution {
public:
    bool isHappy(int num){
        int sum=0;
        while(true){
            if(num==0){
                if(sum==4||sum==1)
                    break;
                num=sum;
                sum=0;
            }
            sum+=(num%10)*(num%10);
            num=num/10;
        }
        if(sum==1)
            return true;
        else
            return false;
    }
};

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int start=1,end=num;
        while(start<=end){
            long long int mid = (start+end)/2;
            if(mid*mid>num)
                end=mid-1;
            else
                start=mid+1;
        }
        start--;
        if(start*start==num)
            return true;
        return false;  
    }
};

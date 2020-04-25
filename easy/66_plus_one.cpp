class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sz=digits.size();
        
        reverse(digits.begin(),digits.end());
        digits[0]++;
        digits.push_back(0);
        
        for(int i=0;i<sz;i++){
            if(digits[i]/10>0){
                digits[i+1]++;
                digits[i]%=10;
            }
        }
        if(digits[sz]==0)
            digits.pop_back();
        reverse(digits.begin(),digits.end());
        return digits;
    }
};

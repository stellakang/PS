class TwoSum {
    unordered_map<int,int>nums;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        nums[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(pair<int,int> num:nums){
            int number1=num.first;
            int number2=value-number1;
            if(nums.find(number2)==nums.end())continue;
            if(number1!=number2)return true;
            if(nums[number1]>=2)return true;     
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>strs;
        int i=3;
        if(!(i%3))cout<<"1";
        else cout<<"0";
        for(int i=1;i<=n;i++){
            if(i%3==0 && i%5==0)strs.push_back("FizzBuzz");
            else if(i%3==0)strs.push_back("Fizz");
            else if(i%5==0)strs.push_back("Buzz");
            else strs.push_back(to_string(i));
        }
        return strs;
    }
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int len=digits.length();
        if(len==0)return {};
        unordered_map<char,string>um={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        
        queue<string>q;
        q.push("");
        int numOfStr=1;
        for(int i=0;i<len;i++){
            string mapping=um[digits[i]];
            int numOfIter=numOfStr;
            while(numOfIter--){
                string topElement=q.front();
                q.pop();
                numOfStr--;
                for(char c:mapping){
                    numOfStr++;
                    q.push(topElement+c);
                }
            }
        }
        vector<string>v;
        while(numOfStr--){
            v.push_back(q.front());
            q.pop();
        }
        return v;
    }
};

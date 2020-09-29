//Naive solution
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>answer;
        int numOfElement = nums.size();
        if(numOfElement==0)return {{}};
        for(int i=0;i<numOfElement;i++){
            vector<int>remains;
            for(int j=0;j<numOfElement;j++){
                if(i==j)continue;
                remains.push_back(nums[j]);
            }
            vector<vector<int>>allCases = permute(remains);
            for(int j=0;j<allCases.size();j++){
                vector<int>permu;
                permu.push_back(nums[i]);
                permu.insert(permu.begin(), allCases[j].begin(), allCases[j].end());
                answer.push_back(permu);
            }
        }
        return answer;
    }
};

// backtracking
class Solution {
public:
    void backtracking(vector<vector<int>>&answer, vector<int>&nums, int i, int numSz){
        if(numSz == i){
            answer.push_back(nums);
            return;
        }
        for(int p=i; p<numSz; p++){
            swap(nums[p], nums[i]);
            backtracking(answer, nums, i+1, numSz);
            swap(nums[p], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>answer;
        int numOfElement = nums.size();
        backtracking(answer, nums, 0, numOfElement);
        return answer;
    }
};




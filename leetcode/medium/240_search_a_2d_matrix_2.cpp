class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i=0;i<m;i++){
            if(matrix[i][0]>target || matrix[i][n-1]<target)continue;
            int index = lower_bound(matrix[i].begin(), matrix[i].end(), target) - matrix[i].begin();
            if(index<n && matrix[i][index]==target)return true;
        }
        return false;
    }
};

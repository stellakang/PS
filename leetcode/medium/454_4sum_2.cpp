class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int>abSum;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<B.size();j++){
                int sum = A[i] + B[j];
                abSum[sum]++;
            }
        }
        int cnt = 0;
        for(int i=0;i<C.size();i++){
            for(int j=0;j<D.size();j++){
                int sum = C[i] + D[j];
                if(abSum.find(-sum)!=abSum.end())
                    cnt+=abSum[-sum];
            }
        }
        return cnt;
    }
};

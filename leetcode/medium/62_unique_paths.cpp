int C[105][105];
class Solution {
public:
    int uniquePaths(int m, int n) {
        int mm = m + n -2;
        int nn = n-1;
        return combination(mm,nn);
    }
    int combination(int m, int n){
        if(n==0 || m==n)return C[m][n] = 1;
        if(C[m][n]!=0)return C[m][n];
        return C[m][n] = combination(m-1,n-1) + combination(m-1,n);
    }
};

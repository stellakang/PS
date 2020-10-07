#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;

int main(){
    int N,M;
    cin>>N>>M;
    int val[N+2][M+2];
    int dp[N+2][M+2][3];
    //0:left 1:up 2:right
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>val[i][j];
        }
    }
    for(int i=0;i<=N+1;i++){
        for(int j=0;j<=M+1;j++){
            for(int k=0;k<3;k++){
                dp[i][j][k] = INT_MIN;
            }
        }
    }
    dp[0][1][0] = 0;
    dp[0][1][1] = 0;
    dp[0][1][2] = 0;
    dp[1][0][0] = 0;
    dp[1][0][1] = 0;
    dp[1][0][2] = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            int leftside[3] = {dp[i][j-1][0], dp[i][j-1][1], dp[i][j-1][2]};
            int upside[3] = {dp[i-1][j][0], dp[i-1][j][1], dp[i-1][j][2]};
            //dp[i][j][1]
            for(int k=0;k<3;k++){
                if(upside[k]!=INT_MIN){
                    dp[i][j][1] = max(dp[i][j][1], val[i][j] + upside[k]);
                }
            }
            //dp[i][j][0]
            for(int k=0;k<2;k++){
                if(leftside[k]!=INT_MIN){
                    dp[i][j][0] = max(dp[i][j][0], val[i][j] + leftside[k]);
                }
            }
        }
        for(int j=M;j>=1;j--){
            int rightside[3] = {dp[i][j+1][0], dp[i][j+1][1], dp[i][j+1][2]};
            //dp[i][j][2]
            for(int k=1;k<3;k++){
                if(rightside[k]!=INT_MIN){
                    dp[i][j][2] = max(dp[i][j][2], val[i][j] + rightside[k]);
                }
            }
        }
    }
    
    int answer = INT_MIN;
    for(int k=0;k<3;k++){
        if(dp[N][M][k]!=INT_MIN){
            answer = max(answer, dp[N][M][k]);
        }
    }
    cout<<answer<<"\n";
    return 0;
}


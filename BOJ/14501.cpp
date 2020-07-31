#include <iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    
    int T[N+1],P[N+1],DP[N+1];
    for(int i=1;i<=N;i++){
        cin>>T[i]>>P[i];
        DP[i]=0;
    }
    
    DP[0]=0;
    for(int i=1;i<=N;i++){
        if(DP[i]<DP[i-1])
            DP[i]=DP[i-1];
        if(i+T[i]-1<=N && DP[i-1]+P[i]>DP[i+T[i]-1])
            DP[i+T[i]-1]=DP[i-1]+P[i];
    }
    cout<<DP[N]<<"\n";
    return 0;
}


#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    int A[N],B[N],C[N],D[N];
    for(int i=0;i<N;i++){
        scanf("%d%d%d%d",&A[i],&B[i],&C[i],&D[i]);
    }
    unordered_map<int,int>cnt;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cnt[A[i]+B[j]]++;
        }
    }
    long long int answer=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int num = -C[i]-D[j];
            if(cnt.find(num)==cnt.end())continue;
            answer+=cnt[num];
        }
    }
    cout<<answer<<"\n";
    return 0;
}


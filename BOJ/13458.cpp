#include <iostream>
using namespace std;

long long int minimumNumOfSupervisor(int N, int arr[], int B, int C);
int main(){
    int N,B,C;
    cin>>N;
    
    int arr[N];
    for(int i=0;i<N;i++)
        cin>>arr[i];
    cin>>B>>C;
    
    cout<<minimumNumOfSupervisor(N,arr,B,C)<<endl;
    return 0;
}

long long int minimumNumOfSupervisor(int N, int arr[], int B, int C){
    long long int supervisors=N;
    for(int i=0;i<N;i++){
        if(B>=arr[i])
            arr[i]=0;
        else
            arr[i]-=B;
        supervisors+=(arr[i]/C);
        if(arr[i]%C>0)
            supervisors++;
    }
    return supervisors;
}



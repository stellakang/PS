#include <iostream>
#include <vector>
using namespace std;

bool primeNumber[4000001];

int main(){
    int N;
    scanf("%d",&N);
    
    vector<int>primeNumberList;
    
    for(int i=2;i<=N;i++){
        if(primeNumber[i]==false){
            primeNumberList.push_back(i);
        }
        for(int j=2*i;j<=N;j+=i){
            primeNumber[j] = true;
        }
    }
    int primeLen = primeNumberList.size();
    int count = 0;
    int sum = 0;
    int start=0,end=-1;
    
    while(start<primeLen && end<primeLen){
        if(sum==N){
            count++;
            sum -= primeNumberList[start++];
        }
        else if(sum>N){
            sum -= primeNumberList[start++];
        }
        else if(sum<N){
            sum += primeNumberList[++end];
        }
    }
    
    printf("%d\n",count);
    
    return 0;
}
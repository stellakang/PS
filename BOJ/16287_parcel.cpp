#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>

using namespace std;

unordered_map<int,bool>mark;
int main(){
    int w,n;
    cin>>w>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    for(int c=2;c<n-1;c++){
        for(int a=0;a<c-1;a++){
            mark[arr[a]+arr[c-1]] = true;
        }
        for(int d=c+1;d<n;d++){
            int sum = arr[c] + arr[d];
            if(mark[w-sum]){
                cout<<"YES\n";
                return 0;
            }
        }
    }
    cout<<"NO\n";
    return 0;
}

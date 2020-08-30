#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin>>N;

    vector<int>nums(N);
    vector<int>compress(N);
    for(int i=0;i<N;i++){
        cin>>nums[i];
        compress[i] = nums[i];
    }
    sort(compress.begin(), compress.end());
    compress.erase(unique(compress.begin(), compress.end()), compress.end());

    for(int i=0;i<N;i++){
        int idx = lower_bound(compress.begin(), compress.end(), nums[i])-compress.begin();
        cout<<idx<<" ";
    }
    cout<<"\n";
    return 0;
}

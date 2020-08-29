// time complexity: O(VE)
#include <iostream>
#include <vector>
#include <cstring>
#define SIZE 205
using namespace std;

int matched[SIZE];
bool visit[SIZE];
vector<vector<int> >cow;

bool dfs(int cowNum){
    if(visit[cowNum])return false;
    visit[cowNum] = true;
    for(int i=0;i<cow[cowNum].size();i++){
        int house = cow[cowNum][i];
        if(matched[house]==0 || dfs(matched[house])){
            matched[house] = cowNum;
            return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,M;
    cin>>N>>M;
    cow.resize(N+1);
    for(int i=1;i<=N;i++){
        int num;
        cin>>num;
        for(int j=0;j<num;j++){
            int sNum;
            cin>>sNum;
            cow[i].push_back(sNum);
        }
    }
    int count = 0;
    for(int i=1;i<=N;i++){
        memset(visit, 0, sizeof(visit));
        if(dfs(i)){
            count++;
        }
    }
    cout<<count<<"\n";
    return 0;
}

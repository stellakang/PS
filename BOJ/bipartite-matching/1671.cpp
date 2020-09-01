#include <iostream>
#include <vector>
#include <cstring>
#define SIZE 55
using namespace std;

struct shark{
    int sz, v, i; 
};

int d[SIZE];
bool visit[SIZE];
vector<vector<int> >eating(SIZE);
bool dfs(int number){
    if(visit[number])return false;
    visit[number] = true;
    for(int i=0;i<eating[number].size();i++){
        int to = eating[number][i];
        if(d[to]==0 || dfs(d[to])){
            d[to] = number;
            return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<shark>sh(n+1);
    for(int i=1;i<=n;i++){
        int sz, v, ii;
        cin>>sz>>v>>ii;
        sh[i].sz = sz;
        sh[i].v = v;
        sh[i].i = ii;
    }
    // create edge
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(sh[i].i==sh[j].i && sh[i].sz==sh[j].sz && sh[i].v==sh[j].v && i>j)continue;
            if(sh[i].i>=sh[j].i && sh[i].sz>=sh[j].sz && sh[i].v>=sh[j].v){
                eating[i].push_back(j);
            }
        }
    }
    for(int i=1;i<=n;i++){
        memset(visit, false, sizeof(visit));
        dfs(i);
        memset(visit, false, sizeof(visit));
        dfs(i);
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(d[i]==0){
            cnt++;
        }
    }
    cout<<cnt<<"\n";
    return 0;
}

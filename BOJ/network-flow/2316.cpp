#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define SIZE 805
#define INF 0x7fffffff
using namespace std;

int cap[SIZE][SIZE];
int flow[SIZE][SIZE];
vector<vector<int> >city(SIZE);

int edmondsKarp(int src, int dst){
    int total = 0;
    while(true){
        int pre[SIZE];
        memset(pre, -1, sizeof(pre));
        queue<int>qu;
        qu.push(src);
        while(!qu.empty()){
            int cur = qu.front();
            qu.pop();

            for(int i=0;i<city[cur].size();i++){
                int next = city[cur][i];
                if(pre[next]!=-1)continue;
                if(cap[cur][next]-flow[cur][next]>0){
                    qu.push(next);
                    pre[next] = cur;
                    if(next==dst)break;
                }
            }
        }
        if(pre[dst]==-1)break;
        int f = INF;
        for(int i=dst;i!=src;i=pre[i]){
            f = min(f, cap[pre[i]][i]-flow[pre[i]][i]);
        }
        for(int i=dst;i!=src;i=pre[i]){
            flow[pre[i]][i] += f;
            flow[i][pre[i]] -= f;
        }
        total += f;
    }
    return total;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,P;
    cin>>N>>P;

    for(int i=3;i<=N;i++){
        cap[i][N+i] = 1;
        city[i].push_back(N+i);
        city[N+i].push_back(i);
    }
    while(P--){
        int a,b;
        cin>>a>>b;
        int a_out = a;
        int b_out = b;
        if(a!=1 && a!=2){
            a_out = a+N;
        }
        if(b!=1 && b!=2){
            b_out = b+N;
        }
        city[a_out].push_back(b);
        city[b].push_back(a_out);
        city[b_out].push_back(a);
        city[a].push_back(b_out);
        cap[a_out][b]++;
        cap[b_out][a]++;
    }
    cout<<edmondsKarp(1, 2)<<"\n";
    return 0;
}

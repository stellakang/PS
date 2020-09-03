//time complexity: O(VE^2)
//증가경로 한번 flow 보낼때마다 최소한 간선 하나씩 포화되므로
//O(E)개의 증가경로를 갖고 bfs는 O(E)이므로 O(E^2)
//최단 경로의 길이는 V이하이니 O(VE^2) 
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define SIZE 58
#define INF 0x7fffffff
using namespace std;

int cap[SIZE][SIZE];
int flow[SIZE][SIZE];
vector<vector<int> >pipe(SIZE);

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        char a, b;
        int val;
        cin>>a>>b>>val;
        int from = a-'A';
        int to = b-'A';
        pipe[from].push_back(to);
        pipe[to].push_back(from);
        cap[from][to] += val;
        cap[to][from] += val;
    }
    int total = 0;
    int start = 0, end = 'Z'-'A';
    // 증가경로 없을때까지 
    while(true){
        queue<int>qu;
        qu.push(start);
        int pre[SIZE];
        memset(pre, -1, sizeof(pre));

        while(!qu.empty()){
            int cur = qu.front();
            qu.pop();
            for(int i=0;i<pipe[cur].size();i++){
                int next = pipe[cur][i];
                if(pre[next]!=-1)continue;
                if(cap[cur][next]-flow[cur][next]>0){
                    pre[next] = cur;
                    qu.push(next);
                    if(next==end)break;
                }
            }
        }
        //더이상 증가경로 없을때
        if(pre[end]==-1)break;

        int f = INF;
        for(int i=end;i!=start;i=pre[i]){
            f = min(f, cap[pre[i]][i]-flow[pre[i]][i]);
        }
        for(int i=end;i!=start;i=pre[i]){
            flow[pre[i]][i] += f;
            flow[i][pre[i]] -= f;
        }
        total += f;
    }
    cout<<total<<"\n";
    return 0;
}

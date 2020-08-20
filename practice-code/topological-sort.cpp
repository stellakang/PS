#include <iostream>
#include <vector>
#include <queue>
#define SIZE 1000005
using namespace std;

int N,M;
int indegree[SIZE+1];
//using bfs
void version1(vector<vector<int> >&graph){
    queue<int>qu;
    for(int i=1;i<=N;i++){
        if(indegree[i]==0){
            qu.push(i);
        }
    }
    while(!qu.empty()){
        int cur = qu.front();
        cout<<cur<<" ";
        qu.pop();
        for(int adj: graph[cur]){
            if(--indegree[adj]==0){
                qu.push(adj);
            }
        }
    }
    cout<<"\n";
    for(int i=1;i<=N;i++){
        if(indegree[i]!=0){
            cout<<"topological sort is impossible\n";
            break;
        }
    }
}
//using dfs
int visit[SIZE+1];
vector<int> result;
void dfs(int node, vector<vector<int> >&graph){
    for(int adj: graph[node]){
        if(visit[adj]==0){
            visit[adj] = 1;
            dfs(adj, graph);
            visit[adj] = 2;
        }
        else if(visit[adj]==1){
            cout<<"topological sort is impossible\n";
            exit(1);
        }
    }
    result.push_back(node);
}
void version2(vector<vector<int> >&graph){
    for(int i=1;i<=N;i++){
        if(visit[i]==0){
            visit[i] = 1;
            dfs(i, graph);
            visit[i] = 2;
        }
    }
    for(int i=N-1;i>=0;i--){
        cout<<result[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>N>>M;
    vector<vector<int> >graph(N+1);
    while(M--){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    version1(graph);
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int parent[100005][17];
int depth[100005];
bool visit[100005];
void dfs(vector<vector<int> >&graph, int node, int d){
    depth[node] = d;
    for(int i=0;i<graph[node].size();i++){
        int next = graph[node][i];
        if(!visit[next]){
            visit[next] = true;
            parent[next][0] = node;
            dfs(graph, next, d+1);
        }
    }
}
void initTreeInfo(vector<vector<int> >&graph){
    visit[1] = true;
    dfs(graph, 1, 0);
    for(int i=1;i<=16;i++){
        for(int j=1;j<=N;j++){
            parent[j][i] = parent[parent[j][i-1]][i-1];
        }
    }
}
int lca(int a, int b){
    if(depth[a]>depth[b])swap(a,b);
    for(int i=16;i>=0;i--){
        if(depth[b]-depth[a]>= (1<<i)){
            b = parent[b][i];
        }
    }
    if(a==b)return a;
    for(int i=16;i>=0;i--){
        if(parent[b][i]!=parent[a][i]){
            b = parent[b][i];
            a = parent[a][i];
        }
    }
    return parent[a][0];
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>N;
    vector<vector<int> >graph(N+1);
    for(int i=0;i<N-1;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    initTreeInfo(graph);
    int M;
    cin>>M;
    while(M--){
        int a,b;
        cin>>a>>b;
        cout<<lca(a, b)<<"\n";
    }
	return 0;
}

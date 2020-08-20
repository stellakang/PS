//Bellman ford algorithm
// time complexity: O(VE)
// space complexity: O(V)
// can solve graph with negative weight
// can find graph with negative cycle
// slower than dijkstra
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 0x7fffffff
#define NODE 20005
#define EDGE 300005
using namespace std;
typedef pair<int,int> pii;

struct edge{
    int from, to, weight;
};

int dist[NODE+1];
edge ed[EDGE+1];

void bellmanford(int V, int E, int src){
    for(int i=1;i<=V;i++){
        dist[i] = INF;
    }
    dist[src] = 0;
    for(int i=1; i<=V-1; i++){
        for(int j=0;j<E;j++){
            int u = ed[j].from;
            int v = ed[j].to;
            int w = ed[j].weight;
            if(dist[u] != INF && dist[u]+w <dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }
    for(int i=0; i<E; i++){
        int u = ed[i].from;
        int v = ed[i].to;
        int w = ed[i].weight;
        if(dist[u] != INF && dist[u] + w < dist[v]){
            cout<<"graph contains negative weight cycle\n";
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int v,e,k;
    cin>>v>>e>>k;
    for(int i=0;i<e;i++){
        cin>>ed[i].from>>ed[i].to>>ed[i].weight;
    }
    bellmanford(v, e, k);
    for(int i=1;i<=v;i++){
        if(dist[i]==INF)
            cout<<"INF\n";
        else
            cout<<dist[i]<<"\n";
    }
    return 0;
}

//dijkstra algorithm
//weak point : all weights should be positive
//priority queue log(V^2) = 2log(V) -> E updates each pop
//time complexity using heap O(ElogV)
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 0x7fffffff
using namespace std;
typedef pair<int,int> pii;
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int v,e,k;
    cin>>v>>e>>k;
    vector<vector<pii> >graph(v+1);
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(make_pair(v,w));
    }
    vector<int>dist(v+1, INF);
    dist[k] = 0;
    priority_queue<pii>pq;
    pq.push(make_pair(0, k));
    while(!pq.empty()){
        int cur = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();
        for(pii p: graph[cur]){
            int nextNode = p.first;
            int nextDist = distance + p.second;
            if(nextDist < dist[nextNode]){
                dist[nextNode] = nextDist;
                pq.push(make_pair(-nextDist, nextNode));
            }
        }
    }
    for(int i=1;i<=v;i++){
        if(dist[i]==INF)
            cout<<"INF\n";
        else
            cout<<dist[i]<<"\n";
    }
    return 0;
}

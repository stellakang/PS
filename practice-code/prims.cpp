#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define SIZE 10005

using namespace std;

typedef pair<int,int> pii;

bool visit[SIZE];
vector<vector<pii> >graph;

// prim's algorithm
// time complexity : O(ElogV)
void primAlgorithm(){
    // start node: 1
    int start = 1;
    visit[start] = true;
    priority_queue<pii, vector<pii>, greater<pii> >pq;

    for(int i=0;i<graph[start].size();i++){
        int next = graph[start][i].first;
        int cost = graph[start][i].second;
        pq.push(make_pair(cost, next));
    }
    int result = 0;
    while(!pq.empty()){
        int cur = pq.top().second;
        int curCost = pq.top().first;
        pq.pop();
        if(visit[cur])continue;
        visit[cur] = true;
        result += curCost;
        for(int i=0;i<graph[cur].size();i++){
            int next = graph[cur][i].first;
            int cost = graph[cur][i].second;
            if(visit[next])continue;
            pq.push(make_pair(cost, next));
        }
    }
    cout<<result<<"\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,M;
    cin>>N>>M;
    graph.resize(N+1);
    for(int i=0;i<M;i++){
        int from, to, val;
        cin>>from>>to>>val;
        graph[from].push_back(make_pair(to, val));
        graph[to].push_back(make_pair(from, val));
    }
    primAlgorithm();
    return 0;
}

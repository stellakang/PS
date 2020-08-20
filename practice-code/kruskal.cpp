#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define SIZE 1000005
using namespace std;
//kruskal's algorithm
//time complexity: ElogE (sorting edges)
struct edge{
    int from;
    int to;
    int val;
};
vector<edge>edges;
int root[SIZE];
int ranks[SIZE];

bool comp(edge e1, edge e2){
    return e1.val<e2.val;
}
void init(){
    for(int i=0;i<SIZE;i++){
        root[i] = i;
    }
}
int find(int x){
    if(root[x] == x){
        return x;
    }
    return root[x] = find(root[x]);
}
void unions(int x, int y){
    x = find(x);
    y = find(y);

    if(x==y)return;

    if(ranks[x]<ranks[y]){
        root[x] = y;
    }
    else{
        root[y] = x;
        if(ranks[x]==ranks[y]){
            ranks[x]++;
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        edge e;
        cin>>e.from>>e.to>>e.val;
        edges.push_back(e);
    }
    sort(edges.begin(), edges.end(), comp);
    int result = 0;
    init();
    for(int i=0;i<M;i++){
        int x = edges[i].from;
        int y = edges[i].to;
        if(find(x)!=find(y)){
            unions(x,y);
            result += edges[i].val;
        }
    }
    cout<<result<<"\n";
    return 0;
}

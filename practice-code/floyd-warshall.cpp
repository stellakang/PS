// FLoyd warshall algorithm
// time complexity: O(V^3)
// can solve graph with negative weight
// can find distance between all pairs
#include <iostream>
#include <vector>
#include <algorithm>
#define NODE 105
#define INF 0x7fffffff
using namespace std;

int dist[NODE+1][NODE+1];

void floydwarshall(int V){
    for(int k=1;k<=V;k++){
        for(int i=1;i<=V;i++){
            for(int j=1;j<=V;j++){
                if(dist[i][k]==INF || dist[k][j]==INF)continue;
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            dist[i][j] = INF;
        }
    }
    for(int i=0;i<m;i++){
        int a, b, c;
        cin>>a>>b>>c;
        dist[a][b] = min(dist[a][b], c);
    }
    floydwarshall(n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j]==INF){
                cout<<"0 ";
            }
            else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int N,M,D;
int maxVal = 0;
int grid[20][20];

struct pos{
    int x,y;
};

int getDist(pos a, pos b){
    return abs(a.x-b.x) + abs(a.y-b.y);
}

int process(vector<pos>&archer){
    int copy[20][20];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            copy[i][j] = grid[i][j];
        }
    }
    int answer = 0;
    while(true){
        int cnt = 0;
        bool check[N][M];
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                check[i][j] = false;
                if(copy[i][j]==1)
                    cnt++;
            }
        }
        if(cnt==0)break;
        for(pos p:archer){
            pos enemy;
            int dist = N+M+1;
            for(int j=0;j<M;j++){
                for(int i=N-1;i>=0;i--){
                    if(copy[i][j]==1){
                        int distance = getDist({i,j}, p);
                        if(distance>D)continue;
                        if(distance<dist){
                            enemy.x = i;
                            enemy.y = j;
                            dist = distance;
                        }
                    }
                }
            }
            if(dist!=N+M+1){
                check[enemy.x][enemy.y] = true;
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(check[i][j]){
                    copy[i][j] = 0;
                    answer ++;
                }
            }
        }
        for(int j=0;j<M;j++){
            for(int i=N-1;i>=0;i--){
                if(copy[i][j]==1){
                    if(i+1<N){
                        copy[i+1][j] = 1;
                    }
                    copy[i][j] = 0;
                }
            }
        }
    }
    return answer;
}

void chooseArcher(vector<pos>&archer, int cnt){
    if(cnt==3){
        int enemies = process(archer);
        if(maxVal<enemies){
            maxVal = enemies;
        }
        return;
    }
    pos prev;
    if(cnt==0){
        prev.x = 0;
        prev.y = -1;
    }
    else
        prev = archer[cnt-1];
    for(int i=prev.y+1;i<M;i++){
        archer.push_back({N,i});
        chooseArcher(archer, cnt+1);
        archer.pop_back();
    }
}

int main(){
    cin>>N>>M>>D;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>grid[i][j];
        }
    }
    vector<pos>p;
    chooseArcher(p, 0);
    cout<<maxVal<<"\n";
    return 0;
}


#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

char puyo[12][6];
bool visit[12][6];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool findConnection(int x, int y){
    queue<pair<int,int>>qu;
    vector<pair<int,int>>pos;
    qu.push(make_pair(x,y));
    int count = 0;
    while(!qu.empty()){
        pair<int,int>p = qu.front();
        qu.pop();
        if(++count>=4){
            for(pair<int,int> pre: pos){
                visit[pre.first][pre.second] = false;
            }
            return true;
        }
        for(int i=0;i<4;i++){
            int xi = p.first + dx[i];
            int yi = p.second + dy[i];

            if(xi<0 || yi<0 || xi>=12 || yi>=6)continue;
            if(visit[xi][yi])continue;
            if(puyo[xi][yi]==puyo[x][y]){
                qu.push(make_pair(xi, yi));
                pos.push_back(make_pair(xi, yi));
                visit[xi][yi] = true;
            }
        }
    }
    return false;
}

void popPuyos(int x, int y){
    queue<pair<int,int>>qu;
    qu.push(make_pair(x,y));
    char c = puyo[x][y];
    while(!qu.empty()){
        pair<int,int>p = qu.front();
        qu.pop();
        puyo[p.first][p.second] = '.';

        for(int i=0;i<4;i++){
            int xi = p.first + dx[i];
            int yi = p.second + dy[i];

            if(xi<0 || yi<0 || xi>=12 || yi>=6)continue;
            if(visit[xi][yi])continue;
            if(puyo[xi][yi]==c){
                qu.push(make_pair(xi, yi));
                visit[xi][yi] = true;
            }
        }
    }
}
void pushDown(){
    for(int i=10;i>=0;i--){
        for(int j=0;j<6;j++){
            int row = i;
            while(row<11 && puyo[row][j]!='.' && puyo[row+1][j]=='.'){
                puyo[row+1][j] = puyo[row][j];
                puyo[row][j] = '.';
                row++;
            }
        }
    }
}
int main(){
    
    for(int i=0;i<12;i++){
        for(int j=0;j<6;j++){
            cin>>puyo[i][j];
        }
    }
    int answer = 0;
    while(true){
        // 4이상인거 찾기
        memset(visit, 0, sizeof(visit));
        bool popped = false;
        for(int i=0;i<12;i++){
            for(int j=0;j<6;j++){
                if(!visit[i][j] && puyo[i][j]!='.'){
                    visit[i][j] = true;
                    if(findConnection(i,j)){
                        popPuyos(i,j);
                        popped = true;
                    }
                }
            }
        }
        if(popped == false)break;
        pushDown();
        answer++;
    }
    cout<<answer<<"\n";
    return 0;
}

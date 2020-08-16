#include <iostream>
#include <queue>
using namespace std;

struct pos{
    int x,y;
    int type;
};
int R,C;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
char forest[55][55];
queue<pair<pos,int> >qu;
bool canGo(pos cur);
void nextStep(pos cur, int time);
int main(){
    cin>>R>>C;
    pos start;
    for(int i=0;i<R;i++){
        cin>>forest[i];
        for(int j=0;j<C;j++){
            if(forest[i][j]=='S'){
                start.x = i;
                start.y = j;
                start.type = 1;
            }
            else if(forest[i][j]=='*'){
                pos tmp={i,j,-1};
                qu.push(make_pair(tmp,0));
            }
        }
    }
    qu.push(make_pair(start,0));
    while(!qu.empty()){
        pos cur = qu.front().first;
        int time = qu.front().second;
        qu.pop();
        if(forest[cur.x][cur.y]=='D'){
            cout<<time<<"\n";
            return 0;
        }
        nextStep(cur, time);
    }
    cout<<"KAKTUS\n";
    return 0;
}
void nextStep(pos cur, int time){
    for(int i=0;i<4;i++){
        int xi = cur.x+dx[i];
        int yi = cur.y+dy[i];
        if(xi<0 || yi<0 || xi>=R || yi>=C)continue;
        char c = forest[cur.x][cur.y];
        pos tmp ={xi, yi, 0};
        if(cur.type==1){
            if(forest[xi][yi]=='.'||forest[xi][yi]=='D'){
                if(forest[xi][yi]=='.'){
                    forest[xi][yi]='S';
                }
                tmp.type = 1;
                qu.push(make_pair(tmp,time+1));
            }
        }
        else{
            if(forest[xi][yi]=='.'||forest[xi][yi]=='S'){
                tmp.type = -1;
                forest[xi][yi] = '*';
                qu.push(make_pair(tmp,time+1));
            }
        }
    }
}

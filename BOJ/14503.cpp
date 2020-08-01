#include <iostream>
using namespace std;

struct pos{
    int x,y;
};

void cleaning(int N, int M, pos po, int dir);
int rotateLeft(int dir);
void cleanCurrLocation(pos p);
bool isCleanedOrWall(int N, int M, pos po, int dir);
pos goOneBlock(pos p, int dir);
pos goBackOneBlock(pos p, int dir);
bool canGoBack(int N, int M, pos po, int dir);

int space[55][55];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int main(){
    int N,M;
    cin>>N>>M;
    
    int r,c,d;
    cin>>r>>c>>d;
    
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>space[i][j];
    
    cleaning(N,M,{r,c},d);
    int cnt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(space[i][j]==2)
                cnt++;
        }
    }
    cout<<cnt<<"\n";
    return 0;
}
//cur location: x, y in the given direction
void cleaning(int N, int M, pos p, int dir){
    cleanCurrLocation(p);
    int i;
    for(i=0;i<4;i++){
        dir = (dir-1+4)%4;
        if(isCleanedOrWall(N,M,p,dir))continue;
        p = goOneBlock(p, dir);
        cleaning(N, M, p, dir);
        break;
    }
    if(i==4){
        if(canGoBack(N, M, p, dir)){
            p = goBackOneBlock(p,dir);
            cleaning(N,M,p,dir);
        }
    }
}
int rotateLeft(int dir){
    return (dir-1+4)%4;
}
pos goBackOneBlock(pos p, int dir){
    p.x-=dx[dir];
    p.y-=dy[dir];
    return p;
}
pos goOneBlock(pos p, int dir){
    p.x+=dx[dir];
    p.y+=dy[dir];
    return p;
}
void cleanCurrLocation(pos p){
    int x = p.x;
    int y = p.y;
    if(space[x][y]==0)
        space[x][y]=2;
}
bool isCleanedOrWall(int N, int M, pos p, int dir){
    p.x+=dx[dir];
    p.y+=dy[dir];
    if(p.x<0 || p.y<0 || p.x>=N || p.y>=M)return true;
    if(space[p.x][p.y]==0)return false;
    return true;
}
bool canGoBack(int N, int M, pos p, int dir){
    p = goBackOneBlock(p, dir);
    if(p.x<0 || p.y<0 || p.x>=N || p.y>=M)return false;
    if(space[p.x][p.y]==1)return false;
    return true;
}

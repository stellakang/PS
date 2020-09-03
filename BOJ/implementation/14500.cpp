#include <iostream>
using namespace std;

struct pos{
    int x,y;
};

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int grid[505][505];
bool visit[505][505];

bool isOutOfBound(int N,int M,int x,int y);
bool isOutOfBound2(int N,int M,int x,int y,int x2,int y2);
int sumOfTetromino(int N, int M, int x, int y, int sum, int num);

int main(){
    int N,M;
    cin>>N>>M;

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>grid[i][j];
    
    int maxSum=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int sum = sumOfTetromino(N,M,i,j,0,1);
            if(maxSum<sum)
                maxSum = sum;
        }
    }
    cout<<maxSum<<"\n";
    return 0;
}
int sumOfTetromino(int N, int M,int x, int y, int sum, int num){
    visit[x][y]=true;
    sum+=grid[x][y];
    
    if(num==4){
        visit[x][y]=false;
        return sum;
    }
    int max=0;
    //case ㄹ,ㅣ,ㅁ,ㄴ
    for(int i=1;i<4;i++){
        int xx = x+dx[i];
        int yy = y+dy[i];
        if(isOutOfBound(N, M, xx, yy) || visit[xx][yy])continue;
        int value = sumOfTetromino(N, M, xx, yy, sum, num+1);
        if(max<value)
            max=value;
    }
    //case ㅏ
    //go 2 blocks more
    if(num==2){
        pos r = {x+dx[1],y+dy[1]};//right
        pos b = {x+dx[2],y+dy[2]};//bottom
        pos l = {x+dx[3],y+dy[3]};//left
        
        int value=0;
        //right and bottom
        if(!isOutOfBound2(N, M, r.x, r.y, b.x, b.y)&&!visit[r.x][r.y]&&!visit[b.x][b.y])
            value = sum+grid[r.x][r.y]+grid[b.x][b.y];
        //left and bottom
        if(!isOutOfBound2(N, M, b.x, b.y, l.x, l.y)&&!visit[b.x][b.y]&&!visit[l.x][l.y]){
            int value2 = sum+grid[b.x][b.y]+grid[l.x][l.y];
            if(value<value2)
                value=value2;
        }
        //right and left
        if(!isOutOfBound2(N, M, r.x, r.y, l.x, l.y)&&!visit[l.x][l.y]&&!visit[r.x][r.y]){
            int value3 = sum+grid[l.x][l.y]+grid[r.x][r.y];
            if(value<value3)
                value=value3;
        }
        if(max<value)
            max=value;
    }
    visit[x][y]=false;
    return max;
}
bool isOutOfBound(int N,int M,int x,int y){
    if(x<0 || x>=N || y<0 || y>=M)
        return true;
    return false;
}
bool isOutOfBound2(int N,int M,int x,int y,int x2,int y2){
    if(x<0 || x>=N || y<0 || y>=M)
        return true;
    if(x2<0 || x2>=N || y2<0 || y2>=M)
        return true;
    return false;
}


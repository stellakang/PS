#include <iostream>
using namespace std;

struct pos{
    int x,y;
};
int map[10][10];
int mapCopy[10][10];

int findSafeArea(int N, int M, pos p1, pos p2, pos p3, int cnt);
bool isContainVirus(pos p1, pos p2, pos p3);
bool isContainWall(pos p1,pos p2,pos p3);
void copyArray(int N, int M);
void makeThreeNewWalls(pos p1, pos p2, pos p3);

template<typename T>
class Queue{
private:
    int frontIndx,rearIndx;
    int sz;
    T* value;
public:
    Queue(int len=65){
        sz=len;
        frontIndx=0;
        rearIndx=0;
        value = new T[sz];
    }
    T front(){
        return value[frontIndx];
    }
    void push(T element){
        
        value[rearIndx]=element;
        rearIndx = (rearIndx+1)%sz;
    }
    bool isFull(){
        return (rearIndx-frontIndx+sz)%sz==sz;
    }
    void pop(){
        if(!empty())
            frontIndx = (frontIndx+1)%sz;
    }
    bool empty(){
        return (rearIndx-frontIndx+sz)%sz==0;
    }
};

int main(){
    int N,M,cnt=0;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
            if(map[i][j]==0)
                cnt++;
        }
    }
    int maxArea = 0;
    for(int i=0;i<N*M;i++){
        for(int j=i+1;j<N*M;j++){
            for(int k=j+1;k<N*M;k++){
                pos p1 = {i/M, i%M};
                pos p2 = {j/M, j%M};
                pos p3 = {k/M, k%M};
                if(isContainVirus(p1,p2,p3) || isContainWall(p1,p2,p3))continue;
                int area = findSafeArea(N, M, p1, p2, p3, cnt-3);
                if(maxArea<area)
                    maxArea = area;
            }
        }
    }
    cout<<maxArea<<"\n";
    return 0;
}

int findSafeArea(int N, int M, pos p1, pos p2, pos p3, int cnt){
    copyArray(N, M);
    makeThreeNewWalls(p1, p2, p3);
    
    Queue<pos>qu;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(mapCopy[i][j]==2)
                qu.push({i,j});
        }
    }
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    while(!qu.empty()){
        pos virus = qu.front();
        qu.pop();
        for(int i=0;i<4;i++){
            pos p = {virus.x+dx[i], virus.y+dy[i]};
            if(p.x<0 || p.x>=N || p.y<0 || p.y>=M)continue;
            if(mapCopy[p.x][p.y]==0){
                qu.push({p.x,p.y});
                mapCopy[p.x][p.y]=2;
                cnt--;
            }
        }
    }
    return cnt;
}
bool isContainVirus(pos p1,pos p2,pos p3){
    if(map[p1.x][p1.y]==2)return true;
    if(map[p2.x][p2.y]==2)return true;
    if(map[p3.x][p3.y]==2)return true;
    return false;
}
bool isContainWall(pos p1,pos p2,pos p3){
    if(map[p1.x][p1.y]==1)return true;
    if(map[p2.x][p2.y]==1)return true;
    if(map[p3.x][p3.y]==1)return true;
    return false;
}
void copyArray(int N, int M){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            mapCopy[i][j]=map[i][j];
        }
    }
}
void makeThreeNewWalls(pos p1, pos p2, pos p3){
    mapCopy[p1.x][p1.y]=1;
    mapCopy[p2.x][p2.y]=1;
    mapCopy[p3.x][p3.y]=1;
}


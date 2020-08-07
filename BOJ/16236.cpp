#include <iostream>
#define QUEUE_SIZE 450
using namespace std;

template<typename T>
class Queue{
private:
    int size,fIndx,rIndx;
    T* values;
public:
    Queue(){
        size = QUEUE_SIZE;
        fIndx = 0;
        rIndx = 0;
        values = new T[QUEUE_SIZE];
    }
    bool isFull(){
        return (rIndx-fIndx)==size;
    }
    bool empty(){
        return (rIndx-fIndx)==0;
    }
    void pop(){
        if(!empty()){
            fIndx++;
        }
    }
    void push(T element){
        if(!isFull()){
            values[rIndx++] = element;
        }
    }
    T front(){
        return values[fIndx];
    }
};

struct pos{
    int x,y;
    int sec;
};

pos cur;//current position
int sea[21][21];
bool visit[21][21];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

void initVisit(int N);
int findFish(int N, int size);
void updateCurPos(int minSec, int sec, int x, int y);

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>sea[i][j];
            if(sea[i][j]==9){
                cur = {i,j,0};
                sea[i][j] = 0;
            }
        }
    }
    int size = 2;
    int times = 0;
    int numFish = 0;
    while(true){
        initVisit(N);
        int minSec = findFish(N, size);
        if(minSec!=0x7fffffff){
            sea[cur.x][cur.y] = 0;
            if(++numFish == size){
                size++;
                numFish = 0;
            }
            times += minSec;
        }
        else
            break;
    }
    cout<<times<<"\n";
    return 0;
}
void initVisit(int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            visit[i][j] = false;
        }
    }
}
int findFish(int N, int size){
    int minSec = 0x7fffffff;
    visit[cur.x][cur.y] = true;
    Queue<pos> qu;
    qu.push({cur.x, cur.y, 0});
    while(!qu.empty()){
        int x = qu.front().x;
        int y = qu.front().y;
        int sec = qu.front().sec;
        qu.pop();
        if(minSec < sec) break;
        if(sea[x][y] >= 1 && sea[x][y] < size){
            updateCurPos(minSec, sec, x, y);
            minSec = sec;
            continue;
        }
        for(int i=0;i<4;i++){
            int xi = x + dx[i];
            int yi = y + dy[i];
            if(xi<0 || yi<0 || xi>=N || yi>=N)continue;
            if(sea[xi][yi] > size || visit[xi][yi])continue;
            visit[xi][yi] = true;
            qu.push({xi, yi, sec+1});
        }
    }
    return minSec;
}
void updateCurPos(int minSec, int sec, int x, int y){
    if(minSec>sec){
        cur = {x, y, 0};
    }
    else if(minSec==sec){
        if(cur.x > x){
            cur = {x, y, 0};
        }
        else if(cur.x == x && cur.y > y){
            cur = {x, y, 0};
        }
    }
}


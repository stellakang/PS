#include <iostream>
using namespace std;

template<typename T>
class Queue{
    private:
        int fr, rear;
        int size;
        T* values;
    public:
        Queue(int sz = 10000){
            fr = 0;
            rear = 0;
            size = sz;
            values = new T[size];
        }
        void push(T element){
            values[rear++] = element;
        }
        T front(){
            return values[fr];
        }
        bool empty(){
            return (rear-fr)==0;
        }
        void pop(){
            fr++;
        }
};

struct pos{
    int x,y,time;
};

int N,M;
int minTime = 0x7fffffff;
int numVirus,numBlank;
//M: total 
int grid[55][55];
bool check[15];
pos viruses[15];

void backTracking(int num, int curIndx);
int spreadVirus();
int main(){
    //input
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>grid[i][j];
            // save virus position
            if(grid[i][j]==2){
                viruses[numVirus].x = i;
                viruses[numVirus].y = j;
                viruses[numVirus++].time = 0;
            }
            else if(grid[i][j]==0){
                numBlank++;
            }
        }
    }
    if(numBlank==0){
        cout<<0<<"\n";
    }
    else{
        backTracking(0, -1);
        if(minTime==0x7fffffff){
            cout<<-1<<"\n";
        }
        else{
            cout<<minTime<<"\n";
        }
    }
    return 0;
}
void backTracking(int num, int curIndx){
    if(M==num){
        // chose M active virus
        int time = spreadVirus();
        if(time!=-1 && time<minTime){
            minTime = time;
        }
        return;
    }
    for(int i=curIndx+1;i<numVirus;i++){
        check[i] = true;
        backTracking(num+1, i);
        check[i] = false;
    }
}
int spreadVirus(){
    //copy
    int grid2[55][55];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            grid2[i][j] = grid[i][j];
        }
    }
    Queue<pos>qu;
    for(int i=0;i<numVirus;i++){
        if(check[i]){
            grid2[viruses[i].x][viruses[i].y] = 3;
            qu.push(viruses[i]);
        }
    }
    int blank = numBlank;
    int time = -1;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    while(!qu.empty()){
        //current position
        pos cur = qu.front();
        qu.pop();
        //search for 4 direction
        //push '0' and '*' and change them to 2
        //if 0 -> blank--
        //if blank ==0 cur.time+1
        for(int k=0;k<4;k++){
            int xi = cur.x + dx[k];
            int yi = cur.y + dy[k];
            if(xi<0 || yi<0 || xi>=N || yi>=N)continue;
            pos next = {xi, yi, cur.time+1};
            if(grid2[xi][yi]==0){
                grid2[xi][yi] = 3;
                qu.push(next);
                if(--blank==0){
                    time = next.time;
                    break;
                }
            }
            else if(grid2[xi][yi]==2){
                grid2[xi][yi] = 3;
                qu.push(next);
            }
        }
        if(blank==0)break;
    }
    return time;
}

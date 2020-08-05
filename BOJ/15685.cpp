#include <iostream>
using namespace std;
#define MAX_POINT 1025
#define MAX_SIZE 101
struct pos{
    int x,y;
};

int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

bool check[MAX_SIZE][MAX_SIZE];
void drawDragonCurv(pos start, int d, int gen);
pos rotate(pos center, pos p);
int countSquare(int N);

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int x,y,d,g;
        cin>>x>>y>>d>>g;
        drawDragonCurv({x,y},d,g);
    }
    cout<<countSquare(N)<<"\n";
    return 0;
}
void drawDragonCurv(pos start, int d, int gen){
    pos point[MAX_POINT];
    point[0] = start;
    point[1] = {start.x+dx[d], start.y+dy[d]};
    int cnt=2;
    for(int g=1;g<=gen;g++){
        pos center = point[cnt-1];
        int st = cnt-2;
        for(int i=st; i>=0; i--){
            point[cnt++] = rotate(center, point[i]);
        }
    }
    for(int i=0;i<cnt;i++){
        int x = point[i].x;
        int y = point[i].y;
        check[x][y]=true;
    }
}
pos rotate(pos center, pos p){
    int diffx = center.x - p.x;
    int diffy = center.y - p.y;
    return {center.x + diffy, center.y - diffx};
}
int countSquare(int N){
    int cnt=0;
    for(int i=0;i<MAX_SIZE-1;i++){
        for(int j=0;j<MAX_SIZE-1;j++){
            if(check[i][j]&&check[i][j+1]&&check[i+1][j]&&check[i+1][j+1])
                cnt++;
        }
    }
    return cnt;
}


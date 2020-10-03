#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int minMovement = 0x7fffffff;
int maze[5][5][5];
bool check[5];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

//x,y : current position
//cnt : the number of movement

struct pos{
    int x,y;
    int indx;
    int cnt;
};

void rotate(int indx){
    for(int i=0;i<5;i++){
        for(int j=0;j<i;j++){
            swap(maze[i][j][indx], maze[j][i][indx]);
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<2;j++){
            swap(maze[i][j][indx], maze[i][4-j][indx]);
        }
    }
}

void escapeFromMaze(vector<int>&orders){
    if(maze[0][0][orders[0]]==0)return;

    bool visit[5][5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                visit[i][j][k] = false;
            }
        }
    }

    queue<pos>qu;
    qu.push({0,0,0,0});
    visit[0][0][0] = true;
    while(!qu.empty()){
        pos cur = qu.front();
        qu.pop();

        if(cur.indx==4 && cur.x==4 && cur.y==4){
            if(minMovement>cur.cnt){
                minMovement = cur.cnt;
            }
            return;
        }

        for(int k=0;k<4;k++){
            int nextX = cur.x + dx[k];
            int nextY = cur.y + dy[k];
            if(nextX<0 || nextX>=5 || nextY<0 || nextY>=5)continue;
            if(visit[nextX][nextY][cur.indx])continue;
            if(maze[nextX][nextY][orders[cur.indx]]==0)continue;
            visit[nextX][nextY][cur.indx] = true;
            qu.push({nextX, nextY, cur.indx, cur.cnt+1});
        }
        if(cur.indx-1>=0 && maze[cur.x][cur.y][orders[cur.indx-1]]==1 && !visit[cur.x][cur.y][cur.indx-1]){
            visit[cur.x][cur.y][cur.indx-1] = true;
            qu.push({cur.x, cur.y, cur.indx-1, cur.cnt+1});
        }
        if(cur.indx+1<5 && maze[cur.x][cur.y][orders[cur.indx+1]]==1 && !visit[cur.x][cur.y][cur.indx+1]){
            visit[cur.x][cur.y][cur.indx+1] = true;
            qu.push({cur.x, cur.y, cur.indx+1, cur.cnt+1});
        }
    }
}

void rotateAllBoards(vector<int>&orders){
    for(int i=0;i<4;i++){
        rotate(0);
        for(int j=0;j<4;j++){
            rotate(1);
            for(int k=0;k<4;k++){
                rotate(2);
                for(int l=0;l<4;l++){
                    rotate(3);
                    for(int m=0;m<4;m++){
                        rotate(4);
                        escapeFromMaze(orders);
                    }
                }
            }
        }
    }  
}

void findPermutation(vector<int>&orders){
    if(orders.size()==5){
        rotateAllBoards(orders);
        return;
    }
    for(int i=0;i<5;i++){
        if(check[i]==false){
            check[i] = true;
            orders.push_back(i);
            findPermutation(orders);
            check[i] = false;
            orders.pop_back();
        }
    }
}

int main(){
    for(int k=0;k<5;k++){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                cin>>maze[i][j][k];
            }
        }
    }
    
    vector<int>order;
    findPermutation(order);
    if(minMovement==0x7fffffff){
        cout<<"-1\n";
    }
    else{
        cout<<minMovement<<"\n";
    }
    return 0;
}


#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int grid[20][20];
bool visit[20][20];
vector<int>enemy[20];

int dist(int x,int y, int x2, int y2){
    return abs(x-x2)+abs(y-y2);
}
void resetVisit(){
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            visit[i][j] = false;
        }
    }
}
int countVisit(){
    int count = 0;
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(visit[i][j])
                count++;
        }
    }
    return count;
}

int main(){
    int n,m,d;
    scanf("%d %d %d",&n,&m,&d);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&grid[i][j]);
            if(grid[i][j]==1){
                enemy[i].push_back(j);
            }
        }
    }

    int answer = 0;
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            for(int k=j+1;k<m;k++){
                for(int row=n-1;row>=0;row--){
                    int minDist[3] = {0xffffff,0xffffff,0xffffff};
                    int minPoint[3][2] = {{-1,-1}, {-1, -1}, {-1, -1}};
                    for(int r=row;r>=0;r--){
                        for(int c: enemy[r]){
                            if(visit[r][c])continue;
                            int distance[3];
                            distance[0] = dist(row+1,i,r,c);
                            distance[1] = dist(row+1,j,r,c);
                            distance[2] = dist(row+1,k,r,c);
                            for(int archer=0;archer<3;archer++){
                                if(minDist[archer]>=distance[archer] && distance[archer]<=d){
                                    if(minDist[archer]==distance[archer] && minPoint[archer][1]<c)continue;
                                    minDist[archer] = distance[archer];
                                    minPoint[archer][0] = r;
                                    minPoint[archer][1] = c;
                                }
                            }
                        }
                        
                    }
                    for(int archer=0;archer<3;archer++){
                        int x = minPoint[archer][0];
                        int y = minPoint[archer][1];
                        if(x==-1 || y==-1)continue;
                        visit[x][y] = true;
                    }
                }
                int numOfDefeat = countVisit();
                if(answer<numOfDefeat){
                    answer = numOfDefeat;
                }
                resetVisit();
            }
        }
    }
    printf("%d\n",answer);

    return 0;
}
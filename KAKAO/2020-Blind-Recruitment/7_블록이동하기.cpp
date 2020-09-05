#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct point{
    int x, y;
    point operator+(point second) {
		return { x + second.x, y + second.y };
	}

	point operator-(point second) {
		return { x - second.x, y - second.y };
	}
};
struct pos{
    point p1, p2;
    int sec;
};

point d[4] = {{0,-1}, {-1,0}, {0,1}, {1,0}};
bool visit[105][105][105][105];

bool isOutOfRange(int N, vector<vector<int>> board, vector<point>p){
    point p1 = p[0];
    point p2 = p[1];
    if(p1.x<0 || p1.y<0 || p1.x>=N || p1.y>=N)return true;
    if(p2.x<0 || p2.y<0 || p2.x>=N || p2.y>=N)return true;
    if(board[p1.x][p1.y]==1 || board[p2.x][p2.y]==1)return true;
    if(visit[p1.x][p1.y][p2.x][p2.y])return true;
    return false;
}
bool comp(point p1, point p2){
    if(p1.y==p2.y){
        return p1.x<p2.x;
    }
    else{
        return p1.y<p2.y;
    }
}
int solution(vector<vector<int>> board) {
    int N = board.size();
    visit[0][0][0][1] = true;
    queue<pos>qu;
    qu.push({{0, 0},{0, 1}, 0});
    while(!qu.empty()){
        pos cur = qu.front();
        qu.pop();
        point p[2];
        p[0] = cur.p1;
        p[1] = cur.p2;
        int sec = cur.sec;
        if((p[0].x==N-1 && p[0].y==N-1)||(p[1].x==N-1 && p[1].y==N-1)){
            return sec;
        }
        // move
        vector<point>n(2);
        for(int i=0;i<4;i++){
            n[0] = p[0]+d[i];
            n[1] = p[1]+d[i];
            sort(n.begin(), n.end(), comp);
            if(isOutOfRange(N, board, n))continue;
            visit[n[0].x][n[0].y][n[1].x][n[1].y] = true;
            qu.push({n[0], n[1], sec+1});
        }
        // rotate
        for(int i=0;i<2;i++){
            int indx = (i+1)%2;
            int dx = p[indx].x - p[i].x;
            int dy = p[indx].y - p[i].y;
            int k;
            for(int j=0;j<4;j++){
                if(d[j].x == dx && d[j].y == dy){
                    k = j;
                    break;
                }
            }
            for(int j=-1;j<=1;j+=2){
                int ro = (k+j+4)%4;
                n[0] = p[i] + d[ro];
                n[1] = p[i];
                sort(n.begin(), n.end(), comp);
                point diag = p[i]+d[ro]+d[k];
                if(isOutOfRange(N, board, n)==false && board[diag.x][diag.y]==0){
                    visit[n[0].x][n[0].y][n[1].x][n[1].y] = true;
                    qu.push({n[0], n[1], sec+1});
                }
            }
        }
    }
    return 0;
}

#include <string>
#include <vector>

using namespace std;

bool row[105][105];
bool col[105][105];

bool canInstall(int n, int x, int y, int type){
    if(x<0 || y>n)return true;
    //type 0: 기둥, 1: 보
    if(type==0){
        if(col[x][y]==false)return true;
        if(y==0)return true;
        if((x-1>=0 && row[x-1][y]) || row[x][y] || (y-1>=0 && col[x][y-1]))
            return true;
    }
    else{
        if(row[x][y]==false)return true;
        if((y-1>=0 && col[x][y-1]) || (x+1<=n && y-1>=0 && col[x+1][y-1]))return true;
        if(x+1<=n && row[x+1][y] && x-1>=0 && row[x-1][y])return true;
    }
    return false;
}
void remove(int n, int x, int y, int type){
    if(type==0){
        col[x][y] = false;
        if(canInstall(n, x, y+1, 0) && canInstall(n, x, y+1, 1) && canInstall(n, x-1, y+1, 1)){
            return;
        }
        col[x][y] = true;
    }
    else{
        row[x][y] = false;
        if(canInstall(n, x, y, 0) && canInstall(n, x+1, y, 0) && canInstall(n, x-1, y, 1)&& canInstall(n, x+1, y, 1))return;
        row[x][y] = true;
    }
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    int sz = build_frame.size();
    for(vector<int>fr : build_frame){
        int x = fr[0];
        int y = fr[1];
        int type = fr[2];
        if(fr[3]==0){
            //삭제
            remove(n, x, y, type);
        }
        else{
            //설치
            if(type==0){
                col[x][y] = true;
                if(!canInstall(n, x, y, type)){
                    col[x][y] = false;
                }
            }
            else{
                row[x][y] = true;
                if(!canInstall(n, x, y, type)){
                    row[x][y] = false;
                }
            }
            
        }
    }
    vector<vector<int>> answer;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(col[i][j]){
                answer.push_back({i,j,0});
            }
            if(row[i][j]){
                answer.push_back({i,j,1});
            }
        }
    }
    return answer;
}

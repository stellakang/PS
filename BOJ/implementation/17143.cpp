#include <iostream>
using namespace std;

struct shark{
    int r,c,s,d,z;
};

int R,C,M;
int total;
int grid[105][105];
shark sh[10005];

void catchShark(int cur);
void moveShark();
int switchDir(int dir);
int main(){
    cin>>R>>C>>M;
    for(int i=1;i<=M;i++){
        int r,c,s,d,z;
        cin>>r>>c>>s>>d>>z;
        sh[i].r = r;
        sh[i].c = c;
        sh[i].s = s;
        sh[i].d = d;
        sh[i].z = z;
        if(d==1 || d==2)
            sh[i].s = s%(2*R-2);
        else
            sh[i].s = s%(2*C-2);
        grid[r][c] = i;
    }
    for(int cur=1;cur<=C;cur++){
        catchShark(cur);
        moveShark();
    }
    cout<<total<<"\n";
    return 0;
}
void catchShark(int cur){
    for(int i=1;i<=R;i++){
        if(grid[i][cur]>0){
            int indx = grid[i][cur];
            total += sh[indx].z;
            grid[i][cur] = 0;
            sh[indx].r = 0;
            sh[indx].c = 0;
            return;
        }
    }
}
void moveShark(){
    int dx[5] = {0,-1,1,0,0};
    int dy[5] = {0,0,0,1,-1};
    for(int i=1;i<=M;i++){
        shark s = sh[i];
        if(s.r==0 && s.c==0)continue;//died
        // move s
        int xi = s.r;
        int yi = s.c;
        for(int j=0;j<s.s;j++){
            xi += dx[s.d];
            yi += dy[s.d];
            if(xi<=0 || yi<=0 || xi>R || yi>C){
                sh[i].d = switchDir(s.d);
                s.d = sh[i].d;
                xi += 2*dx[s.d];
                yi += 2*dy[s.d];
            }
        }
        //erase past position
        if(grid[s.r][s.c]==i){
            grid[s.r][s.c] = 0;
        }
        int curShark = grid[xi][yi];
        //already assigned
        if(curShark>0 && curShark<i){
            //choose the biggest shark 
            if(s.z > sh[curShark].z){
                grid[xi][yi] = i;
                sh[curShark].r = 0;
                sh[curShark].c = 0;
                sh[i].r = xi;
                sh[i].c = yi;
            }
            else{
                // died
                sh[i].r = 0;
                sh[i].c = 0;
            }
        }
        else{
            //not assigned yet
            grid[xi][yi] = i;
            sh[i].r = xi;
            sh[i].c = yi;
        }
    }
}
int switchDir(int dir){
    if(dir==4)
        return 3;
    else if(dir==3)
        return 4;
    else if(dir==1)
        return 2;
    else if(dir==2)
        return 1;
    return 0;
}

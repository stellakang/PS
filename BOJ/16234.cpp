#include <iostream>
using namespace std;

int N,L,R;
int sum, cnt;
int popul[55][55];
bool visit[55][55];
bool asso[55][55];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool moving();
void initVisit();
bool findAssociation(int x, int y);
void assignPeople(int x, int y, int each);
int abs(int a, int b);

int main(){
    cin>>N>>L>>R;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>popul[i][j];
        }
    }
    int movingNum=0;
    while(true){
        initVisit();
        if(!moving())
            break;
        movingNum++;
    }
    cout<<movingNum<<"\n";
    return 0;
}
bool moving(){
    bool moved=false;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visit[i][j])continue;
            cnt = 0;
            sum = 0;
            if(findAssociation(i,j)){
                assignPeople(i,j,sum/cnt);
                moved = true;
            }
            else{
                asso[i][j]=false;
            }
        }
    }
    return moved;
}
bool findAssociation(int x, int y){
    cnt++;
    sum += popul[x][y];
    asso[x][y] = true;
    visit[x][y] = true;
    for(int i=0;i<4;i++){
        int xi = x + dx[i];
        int yi = y + dy[i];
        if(xi<0 || yi<0 || xi>=N || yi>=N)continue;
        if(visit[xi][yi])continue;
        int diff = abs(popul[x][y],popul[xi][yi]);
        if(diff>=L && diff<=R){
            findAssociation(xi, yi);
        }
    }
    return cnt>1;
}
void assignPeople(int x, int y, int each){
    asso[x][y] = false;
    popul[x][y] = each;
    for(int i=0;i<4;i++){
        int xi = x + dx[i];
        int yi = y + dy[i];
        if(xi<0 || yi<0 || xi>=N || yi>=N)continue;
        if(asso[xi][yi]){
            assignPeople(xi, yi, each);
        }
    }
}
void initVisit(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            visit[i][j] = false;
        }
    }
}
int abs(int a, int b){
    if(a>b)return a-b;
    return b-a;
}

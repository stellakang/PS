#include <iostream>
using namespace std;

struct pos{
    int b,a;
};
int cnt=-1;
int N,M,H;
bool ladder[15][35];
bool isComplete();
void ladderGame();
void choosePoint(int total, int num, pos cur);

int main(){
    cin>>N>>M>>H;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        ladder[b][a]=true;
    }
    ladderGame();
    cout<<cnt<<"\n";
    return 0;
}
bool isComplete(){
    for(int i=1;i<=N;i++){
        int cur = i;
        for(int j=1;j<=H;j++){
            if(ladder[cur][j])
                cur++;
            else if(ladder[cur-1][j])
                cur--;
        }
        if(cur!=i)
            return false;
    }
    return true;
}

void ladderGame(){
    for(int i=0;i<=3;i++){
        choosePoint(i,0,{0,0});
        if(cnt!=-1)return;
    }
}
void choosePoint(int total, int num, pos cur){
    if(total==num){
        if(isComplete()){
            cnt=total;
        }
        return;
    }
    for(int i=1;i<N;i++){
        for(int j=1;j<=H;j++){
            if(cur.b>i || (cur.b==i && cur.a>=j))continue;
            if(ladder[i][j]==true)continue;
            if(ladder[i+1][j] || ladder[i-1][j])continue;
            ladder[i][j]=true;
            choosePoint(total, num+1, {i,j});
            ladder[i][j]=false;
        }
    }
}


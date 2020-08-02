#include <iostream>
using namespace std;

int N,L;
int road[105][105];
int countValidRoad(int dir);

void getPath(int dir, int lineNum, int path[]);
bool canGoDown(int indx, int cur, int path[]);
bool canGoUp(int indx, int prev, int path[]);

int main(){
    cin>>N>>L;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>road[i][j];
        }
    }
    //dir=1 row by row
    //dir=2 columb by column
    cout<<countValidRoad(1)+countValidRoad(2)<<"\n";
    
    return 0;
}
int countValidRoad(int dir){
    int roadNum=0;
    for(int i=0;i<N;i++){
        int indx=-1;
        int path[N];
        getPath(dir, i, path);
        int prev = path[0];
        while(++indx<N){
            int cur = path[indx];
            if(cur==prev)continue;
            if(cur!=prev+1&&cur!=prev-1)break;//not a path
            if(cur==prev+1){
                //go up
                if(!canGoUp(indx,prev,path))
                    break;
            }
            else if(cur==prev-1){
                //go down
                if(canGoDown(indx,cur,path))
                    indx+=L-1;
                else
                    break;
            }
            prev=cur;
        }
        if(indx>=N)
            roadNum++;
    }
    return roadNum;
}
void getPath(int dir, int lineNum, int path[]){
    for(int i=0;i<N;i++){
        if(dir==1)
            path[i]=road[lineNum][i];
        else if(dir==2)
            path[i]=road[i][lineNum];
    }
}
bool canGoDown(int indx, int cur, int path[]){
    if(indx+L>N)return false;
    int cnt=0;
    for(int j=indx;j<indx+L;j++){
        if(path[j]==cur)
            cnt++;
        path[j]=-1;
    }
    if(cnt==L)return true;
    return false;
}
bool canGoUp(int indx, int prev, int path[]){
    if(indx-L<0)return false;
    int cnt=0;
    for(int j=indx-L;j<indx;j++){
        if(path[j]==prev)
            cnt++;
        path[j]=-1;
    }
    if(cnt==L)return true;
    return false;
}


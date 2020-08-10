#include <iostream>
using namespace std;
int R,C;
int dust[55][55];
int add[55][55];

void spreadDust();
void blowDustUnClockwise(int x, int y);
void blowDustClockwise(int x, int y);

int main(){
    int T,x,y;
    cin>>R>>C>>T; 
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>dust[i][j];
            if(dust[i][j]==-1){
                x = i;
                y = j;
            }
        }
    }
    while(T--){
        spreadDust();
        blowDustUnClockwise(x-1,y);
        blowDustClockwise(x,y);
    }
    int total = 0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(dust[i][j]>0)
                total += dust[i][j];
        }
    }
    cout<<total<<"\n";
    return 0;
}
void spreadDust(){
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(dust[i][j]>0){
                int num = 0;
                int amount = dust[i][j]/5;
                for(int k=0;k<4;k++){
                    int xi = i+dx[k];
                    int yi = j+dy[k];
                    if(xi<0 || yi<0 || xi>=R || yi>=C)continue;
                    if(dust[xi][yi]==-1)continue;
                    add[xi][yi] += amount;
                    num++;
                }
                dust[i][j] -= amount*num;
            }
        }
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            dust[i][j] += add[i][j];
            add[i][j] = 0;
        }
    }
}
void blowDustUnClockwise(int x, int y){
    int column = 0;
    for(int i=x-1;i>=0;i--){
        dust[i+1][column] = dust[i][column];
    }
    dust[x][column] = -1;
    int row = 0;
    for(int i=1;i<C;i++){
        dust[row][i-1] = dust[row][i];
    }
    column = C-1;
    for(int i=1;i<=x;i++){
        dust[i-1][column] = dust[i][column];
    }
    row = x;
    for(int i=C-2;i>=0;i--){
        dust[row][i+1] = dust[row][i];
    }
    dust[row][1] = 0;
}
void blowDustClockwise(int x, int y){
    int column = 0;
    for(int i=x+1;i<R;i++){
        dust[i-1][column] = dust[i][column];
    }
    dust[x][column] = -1;
    int row = R-1;
    for(int i=1;i<C;i++){
        dust[row][i-1] = dust[row][i];
    }
    column = C-1;
    for(int i=R-2;i>=x;i--){
        dust[i+1][column] = dust[i][column];
    }
    row = x;
    for(int i=C-2;i>=0;i--){
        dust[row][i+1] = dust[row][i];
    }
    dust[row][1] = 0;
}

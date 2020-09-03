#include <iostream>
using namespace std;

int dx[5]={0,0,0,-1,1};
int dy[5]={0,1,-1,0,0};
int map[21][21];

bool isOutOfRange(int N, int M, int x, int y, int direction);
void moveDice(int direction, int dice[]);
int getUpperSideOfDice(int dice[],int x,int y,int direction);

int main(){
    int N,M,K,x,y;
    cin>>N>>M>>x>>y>>K;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>map[i][j];
    
    int direction[K];
    for(int i=0;i<K;i++)
        cin>>direction[i];
    
    int dice[6]={0,0,0,0,0,0};
    for(int i=0;i<K;i++){
        if(isOutOfRange(N,M,x,y,direction[i]))continue;
        x+=dx[direction[i]];
        y+=dy[direction[i]];
        cout<<getUpperSideOfDice(dice,x,y,direction[i])<<"\n";
    }
    return 0;
}
bool isOutOfRange(int N, int M, int x, int y, int direction){
    x+=dx[direction];
    y+=dy[direction];
    if(x<0||x>=N||y<0||y>=M)return true;
    return false;
}
//get upper side value
int getUpperSideOfDice(int dice[],int x,int y, int direction){
    moveDice(direction, dice);
    //change value
    if(map[x][y]==0)
        map[x][y]=dice[3];
    else{
        dice[3]=map[x][y];
        map[x][y]=0;
    }
    return dice[1];
}
//move dice in the given direction
void moveDice(int direction, int dice[]){
    int copy[6];
    for(int i=0;i<6;i++)
        copy[i]=dice[i];
    
    switch(direction){
        case 1:
            dice[1]=copy[4];
            dice[3]=copy[5];
            dice[4]=copy[3];
            dice[5]=copy[1];
            break;
        case 2:
            dice[1]=copy[5];
            dice[3]=copy[4];
            dice[4]=copy[1];
            dice[5]=copy[3];
            break;
        case 3:
            dice[0]=copy[1];
            dice[1]=copy[2];
            dice[2]=copy[3];
            dice[3]=copy[0];
            break;
        case 4:
            dice[0]=copy[3];
            dice[1]=copy[0];
            dice[2]=copy[1];
            dice[3]=copy[2];
            break;
        default:
            break;
    }
}


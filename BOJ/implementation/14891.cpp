#include <iostream>
using namespace std;
int wheel[5][8];
void rotation(int num, int dir);
void rotateWheel(int num, int dir);
int getTotalScore();

int main(){
    for(int i=1;i<=4;i++){
        char state[8];
        cin>>state;
        for(int j=0;j<8;j++){
            if(state[j]=='0')
                wheel[i][j]=0;
            else
                wheel[i][j]=1;
        }
    }
    int K;
    cin>>K;
    for(int i=0;i<K;i++){
        int num,dir;
        cin>>num>>dir;
        rotation(num,dir);
    }
    cout<<getTotalScore()<<"\n";
    return 0;
}
void rotation(int num, int dir){
    int direction[5];
    direction[num]=dir;
    
    for(int i=num-1;i>=1;i--){
        int rightWheel = wheel[i+1][6];
        int curWheel = wheel[i][2];
        if(rightWheel==curWheel){
            direction[i] = 0;
        }
        else{
            direction[i] = direction[i+1]*(-1);
        }
    }
    for(int i=num+1;i<=4;i++){
        int leftWheel = wheel[i-1][2];
        int curWheel = wheel[i][6];
        if(leftWheel==curWheel){
            direction[i] = 0;
        }
        else{
            direction[i] = direction[i-1]*(-1);
        }
    }
    for(int i=1;i<=4;i++){
        rotateWheel(i,direction[i]);
    }
}
void rotateWheel(int num, int dir){
    int wh[8];
    for(int i=0;i<8;i++){
        wh[i]=wheel[num][i];
    }
    if(dir==1){
        //rotate right
        for(int i=0;i<8;i++){
            wheel[num][i]=wh[(i-1+8)%8];
        }
    }
    else if(dir==-1){
        //rotate left
        for(int i=0;i<8;i++){
            wheel[num][i]=wh[(i+1)%8];
        }
    }
    else{
        //do nothing
    }
}
int getTotalScore(){
    int score=0;
    if(wheel[1][0]==1)
        score+=1;
    if(wheel[2][0]==1)
        score+=2;
    if(wheel[3][0]==1)
        score+=4;
    if(wheel[4][0]==1)
        score+=8;
    return score;
}

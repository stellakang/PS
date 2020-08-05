#include <iostream>
using namespace std;

//dice
int dice[6][9];
int sideIndx[6][4]={
    {5,1,4,3},{0,5,2,4},{1,5,3,4},{2,5,0,4},{1,2,3,0},{0,3,2,1}
};
int rotateIndx[6][12]={
    {2,5,8,0,1,2,6,3,0,8,7,6},
    {8,7,6,0,1,2,0,1,2,0,1,2},
    {8,7,6,6,3,0,0,1,2,2,5,8},
    {8,7,6,8,7,6,0,1,2,8,7,6},
    {6,3,0,6,3,0,6,3,0,6,3,0},
    {2,5,8,2,5,8,2,5,8,2,5,8}
};

void initDice();
void printUpper();
char colorIntToChar(int color);
int charToDiceNum(char c);
int charToDirection(char c);
void rotation(int num, int direction);

int main(){
    int tcase;
    cin>>tcase;
    while(tcase--){
        initDice();
        int N;
        cin>>N;
        while(N--){
            char d,dir;
            cin>>d>>dir;
            int diceNum = charToDiceNum(d);
            int direction = charToDirection(dir);
            rotation(diceNum, direction);
        }
        printUpper();
    }
    return 0;
}
void initDice(){
    //w:0, r:1, y:2, o:3, g:4, b:5
    for(int i=0;i<6;i++){
        for(int j=0;j<9;j++){
            dice[i][j]=i;
        }
    }
}
int charToDiceNum(char c){
    if(c=='U')
        return 0;
    else if(c=='D')
        return 2;
    else if(c=='F')
        return 1;
    else if(c=='B')
        return 3;
    else if(c=='L')
        return 4;
    else
        return 5;
}
int charToDirection(char c){
    // clockwise: 1
    // unclockwise: -1
    return c=='+'? 1:-1;
}
void rotation(int num, int direction){
    //init previous dice value
    int prevIndx = (4-direction)%4;
    int prevNum = sideIndx[num][prevIndx];
    int prevColor[3];
    for(int i=0;i<3;i++){
        int indx = rotateIndx[num][prevIndx*3+i];
        prevColor[i] = dice[prevNum][indx];
    }
    
    //rotate and change color
    int curColor[3];
    int i=0,cnt=4;
    while(cnt--){
        //current dice number
        int curNum = sideIndx[num][i];
        for(int j=0;j<3;j++){
            int indx = rotateIndx[num][i*3+j];
            curColor[j] = dice[curNum][indx];
            dice[curNum][indx] = prevColor[j];
            prevColor[j] = curColor[j];
        }
        i = (i+direction+4)%4;
    }
    
    //change num th dice color
    int tmp[9];
    for(int i=0;i<9;i++){
        tmp[i] = dice[num][i];
    }
    if(direction==1){
        int indx[9]={6,3,0,7,4,1,8,5,2};
        for(int i=0;i<9;i++){
            dice[num][i]=tmp[indx[i]];
        }
    }
    else{
        int indx[9]={2,5,8,1,4,7,0,3,6};
        for(int i=0;i<9;i++){
            dice[num][i]=tmp[indx[i]];
        }
    }
}
char colorIntToChar(int color){
    if(color==0)
        return 'w';
    else if(color==1)
        return 'r';
    else if(color==2)
        return 'y';
    else if(color==3)
        return 'o';
    else if(color==4)
        return 'g';
    else//color=5
        return 'b';
}
void printUpper(){
    for(int i=0;i<9;i++){
        cout<<colorIntToChar(dice[0][i]);
        if(i%3==2)
            cout<<"\n";
    }
}


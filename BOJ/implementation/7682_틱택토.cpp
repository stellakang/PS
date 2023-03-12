#include <iostream>
#include <string>
using namespace std;

int numO,numX;
int tictactoe[3][3];

int checkBingo(){
    int bingoO = 0;
    int bingoX = 0;
    for(int i=0;i<3;i++){
        if(tictactoe[i][0]==1 && tictactoe[i][1]==1 && tictactoe[i][2]==1)bingoO++;
        if(tictactoe[i][0]==2 && tictactoe[i][1]==2 && tictactoe[i][2]==2)bingoX++;
        if(tictactoe[0][i]==1 && tictactoe[1][i]==1 && tictactoe[2][i]==1)bingoO++;
        if(tictactoe[0][i]==2 && tictactoe[1][i]==2 && tictactoe[2][i]==2)bingoX++;
    }
    if(tictactoe[0][0]==2 && tictactoe[1][1]==2 && tictactoe[2][2]==2)bingoX++;
    if(tictactoe[0][2]==2 && tictactoe[1][1]==2 && tictactoe[2][0]==2)bingoX++;
    if(tictactoe[0][0]==1 && tictactoe[1][1]==1 && tictactoe[2][2]==1)bingoO++;
    if(tictactoe[0][2]==1 && tictactoe[1][1]==1 && tictactoe[2][0]==1)bingoO++;
    if(bingoO>=1 && bingoX==0)return 1;
    if(bingoO==0 && bingoX>=1)return 2;
    if(bingoO==0 && bingoX==0)return 0;
    return -1;
}

bool checkValid(){
    if(numO+numX==9){
        if(numO+1==numX){
            int bingo = checkBingo();
            if(bingo==0 || bingo==2)return true;
        }
    }
    else{
        if(numO==numX){
            if(checkBingo()==1)return 1;
        }
        else if(numO+1==numX){
            if(checkBingo()==2)return true;
        }
    }
    return false;
}

int main(){
    while(true){
        string str;
        cin>>str;
        if(str=="end")break;
        numO = 0;
        numX = 0;
        for(int i=0;i<9;i++){
            int row=i/3;
            int col = i%3;
            int val = 0;
            if(str[i]=='O'){
                val = 1;
                numO++;
            }
            else if(str[i] == 'X'){
                val = 2;
                numX++;
            }
            
            tictactoe[row][col] = val;
        }
        if(checkValid())
                printf("valid\n");
        else
            printf("invalid\n");
    }
    
    return 0;
}
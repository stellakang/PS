#include <iostream>
#include <string>
#include <vector>

using namespace std;

int row,col;

bool canFill(int i, int j, vector<vector<int>>&board){
    for(int r=0;r<i;r++){
        if(board[r][j]!=0)return false;
    }
    return true;
}
bool haveShape1(int i, int j, vector<vector<int>>&board){
    int num = board[i+1][j];
    if(num==0)return false;
    if(num==board[i][j] && num==board[i+1][j+1] && num==board[i+1][j+2]){
        if(board[i][j+1]==0 && board[i][j+2]==0){
            if(canFill(i, j+1, board) && canFill(i, j+2, board))return true;
        }
        return false;
    }
    if(num==board[i+1][j+1] && num==board[i+1][j+2] && num==board[i][j+2]){
        if(board[i][j]==0 && board[i][j+1]==0){
            if(canFill(i, j, board) && canFill(i, j+1, board))return true;
        }
        return false;
    }
    if(num==board[i+1][j+1] && num==board[i+1][j+2] && num==board[i][j+1]){
        if(board[i][j]==0 && board[i][j+2]==0){
            if(canFill(i, j, board) && canFill(i, j+2, board))return true;
        }
    }
    return false;
}
bool haveShape2(int i, int j, vector<vector<int>>&board){
    int num = board[i+2][j];
    if(num==0)return false;
    if(num==board[i][j] && num==board[i+1][j] && num==board[i+2][j+1]){
        if(board[i][j+1]==0 && board[i+1][j+1]==0){
            if(canFill(i, j+1, board) && canFill(i+1, j+1, board))return true;
        }
        return false;
    }
    if(num==board[i+2][j+1] && num==board[i+1][j+1] && num==board[i][j+1]){
        if(board[i][j]==0 && board[i+1][j]==0){
            if(canFill(i, j, board) && canFill(i+1, j, board))return true;
        }
    }
    return false;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    row = board.size();
    col = board[0].size();
    
    while(true){
        int count = 0;
        for(int i=0;i<row-1;i++){
            for(int j=0;j<col-1;j++){
                if(i+2<=row && j+3<=col){
                    if(haveShape1(i, j, board)){
                        count++;
                        answer++;
                        for(int a=i;a<i+2;a++)
                            for(int b=j;b<j+3;b++)
                                board[a][b] = 0;
                        break;
                    }  
                }
                if(i+3<=row && j+2<=col){
                    if(haveShape2(i, j, board)){
                        count++;
                        answer++;
                        for(int a=i;a<i+3;a++)
                            for(int b=j;b<j+2;b++)
                                board[a][b] = 0;
                        break;
                    }
                }
            }
            if(count>0)break;
        }
        if(count==0)break;
    }
    return answer;
}

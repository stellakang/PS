#include <iostream>
using namespace std;
struct pos{
    int x,y;
};
int numBlank;
int sudoku[9][9];
pos blank[81];
bool row[9][10];
bool col[9][10];
bool square[9][10];
void checkCandidates();
bool backTracking(int num);

int main(){
    //input
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%d",&sudoku[i][j]);
            // save blank position
            if(sudoku[i][j]==0){
                blank[numBlank].x = i;
                blank[numBlank++].y = j;
            }
        }
    }
    //chooseCandidate
    checkCandidates();
    //backtracking
    backTracking(0);
    return 0;
}
void checkCandidates(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(sudoku[i][j]==0)continue;
            int num = sudoku[i][j];
            row[i][num] = true;
            col[j][num] = true;
            int indx = (i/3)*3 + j/3;
            square[indx][num] = true;
        }
    }
}
bool backTracking(int num){
    if(numBlank==num){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<sudoku[i][j]<<" ";
            }
            cout<<"\n";
        }
        return true;
    }
    int x = blank[num].x;
    int y = blank[num].y;
    for(int i=1;i<=9;i++){
        //check if it is candidates
        int indx = (x/3)*3 + (y/3);
        if(!row[x][i] && !col[y][i] && !square[indx][i]){
            row[x][i] = true;
            col[y][i] = true;
            square[indx][i] = true;
            sudoku[x][y] = i; 
            if(backTracking(num+1))
                return true;
            row[x][i] = false;
            col[y][i] = false;
            square[indx][i] = false;
        }
    }
    return false;
}

#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
bool visit[35][35];
int erase(int n, int m, vector<string>& board){
    for(int i=0;i<m-1;i++){
        for(int j=0;j<n-1;j++){
            if(board[i][j]=='.')continue;
            if(board[i][j]==board[i+1][j] && board[i][j]==board[i][j+1] && board[i][j]== board[i+1][j+1]){
                visit[i][j] = true;
                visit[i][j+1] = true;
                visit[i+1][j] = true;
                visit[i+1][j+1] = true;
            }
        }
    }
    int num = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visit[i][j]){
                board[i][j] = '.';
                num++;
                visit[i][j] = false;
            }
        }
    }
    return num;
}
void push(int n, int m, vector<string>& board){
    for(int i=0;i<n;i++){
        for(int j=m-1;j>=0;j--){
            if(board[j][i]=='.')continue;
            int cur = j;
            while(cur+1<m && board[cur+1][i]=='.'){
                board[cur+1][i] = board[cur][i];
                board[cur][i] = '.';
                cur++;
            }
        }
    }
}
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while(true){
        int removed = erase(n, m, board);
        if(removed == 0)break;
        answer += removed;
        push(n, m, board);
    }
    return answer;
}

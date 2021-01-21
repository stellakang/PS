class Solution {
public:
    bool checkRow(int i, vector<vector<char>>& board){
        long long sum = 0;
        for(int j=0;j<9;j++){
            if(board[i][j]=='.')continue;
            long long num = (1 << (board[i][j]-'0'-1));
            if((sum & num) > 0)return false;
            sum |= num;
        }
        return true;
    }
    bool checkCol(int j, vector<vector<char>>& board){
        long long sum = 0;
        for(int i=0;i<9;i++){
            if(board[i][j]=='.')continue;
            long long num = 1 << (board[i][j]-'0'-1);
            if((sum & num) > 0)return false;
            sum |= num;
        }
        return true;
    }
    bool checkSquare(int i, int j, vector<vector<char>>& board){
        long long sum = 0;
        for(int a =i; a<i+3;a++){
            for(int b=j;b<j+3;b++){
                if(board[a][b]=='.')continue;
                long long num = 1 << (board[a][b]-'0'-1);
                if((sum & num) > 0)return false;
                sum |= num;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            if(!checkRow(i, board))return false;
        }
        for(int j=0;j<9;j++){
            if(!checkCol(j, board))return false;
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                if(!checkSquare(i, j, board))return false;
            }
        }
        return true;
    }
};

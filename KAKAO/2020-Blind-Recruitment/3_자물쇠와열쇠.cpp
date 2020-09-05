#include <string>
#include <vector>

using namespace std;

void rotate(int M, vector<vector<int>>&key){
    vector<vector<int>>temp(M, vector<int>(M,0));
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            temp[i][j] = key[M-j-1][i];
        }
    }  
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            key[i][j] = temp[i][j];
        }
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int N = lock.size();
    int M = key.size();
    
    for(int k=0;k<4;k++){
        for(int x = -M+1; x<=N-1; x++){
            for(int y = -M+1; y<=N-1; y++){
                int count = 0;
                for(int i=0;i<N;i++){
                    for(int j=0;j<N;j++){
                        int ki = i-x;
                        int kj = j-y;
                        if(ki>=0 && ki<M && kj>=0 && kj<M){
                            //서로 반대
                            if(key[ki][kj]==0 && lock[i][j]==1)count++;
                            if(key[ki][kj]==1 && lock[i][j]==0)count++;
                        }
                        else{
                            if(lock[i][j]==1)count++;
                        }
                    }
                }  
                if(count == N*N)return true;
            }
        }
        rotate(M, key);
    }
    return false;
}

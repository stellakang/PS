//solution1
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0)return 0;
        
        int N = grid.size();
        int M = grid[0].size();
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        int islands = 0;
        queue<pair<int,int>>qu;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j]=='0')continue;
                islands++;
                qu.push(make_pair(i,j));
                while(!qu.empty()){
                    pair point = qu.front();
                    qu.pop();
                    for(int k=0;k<4;k++){
                        int xi = point.first+dx[k];
                        int yi = point.second+dy[k];
                        if(xi<0 || yi<0 || xi>=N || yi>=M)continue;
                        if(grid[xi][yi]=='1'){
                            qu.push(make_pair(xi,yi));
                            grid[xi][yi]='0';
                        }
                    }
                }
            }
        }
        return islands;
    }
};

//solution2
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0)return 0;
        
        int N = grid.size();
        int M = grid[0].size();
        
        int islands=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    dfs(N,M,{i,j},grid);
                }       
            }
        }
        return islands;              
    }
    void dfs(int N, int M, pair<int,int>po, vector<vector<char>>& grid){
        grid[po.first][po.second]='0';
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        for(int k=0;k<4;k++){
            int xi = po.first+dx[k];
            int yi = po.second+dy[k];
            
            if(xi<0 || xi>=N || yi<0 || yi>=M) continue;
            if(grid[xi][yi]=='0')continue;
            dfs(N, M, {xi,yi}, grid);
        }
    }
};


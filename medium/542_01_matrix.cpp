//sol1
class Solution {
public:
    struct position{
        int xpos,ypos,distance;
    };
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        queue<position>qu;
        
        int row=matrix.size();
        int column=matrix[0].size();
        
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(matrix[i][j]!=0){
                    int dist=0xfffffff;
                    qu.push({i,j,0});
                    while(!qu.empty()){
                        position pos=qu.front();
                        qu.pop();
                        for(int k=0;k<4;k++){
                            int xNext=pos.xpos+dx[k];
                            int yNext=pos.ypos+dy[k];
                            if(xNext<0||xNext>=matrix.size()||yNext<0||yNext>=matrix[i].size())continue;
                            if(matrix[xNext][yNext]==0 && dist>pos.distance+1){
                                dist=pos.distance+1;
                                break;
                            }
                            else if(dist>pos.distance+1)
                                qu.push({xNext,yNext,pos.distance+1});  
                        }   
                    }
                    matrix[i][j]=dist;
                }
            }
        }
        return matrix;
    }
};

//sol2

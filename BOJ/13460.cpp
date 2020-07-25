#include <iostream>
using namespace std;

struct Position{
    int x,y;
};

int moveBeads(int N, int M, Position r, Position b, int iters, int direction);
void updatePosition(int &x, int &y, int xmove, int ymove);
bool isEqual(int x1, int y1, int x2, int y2);

char** board;

int main(int argc, const char * argv[]) {
    int N,M;
    cin>>N>>M;
    
    board = new char*[N];
    for(int i=0;i<N;i++)
        board[i]=new char[M];
    
    Position r,b;
    for(int i=0;i<N;i++){
        cin>>board[i];
        for(int j=0;j<M;j++){
            if(board[i][j]=='R')
                r={i,j};
            else if(board[i][j]=='B')
                b={i,j};
        }
    }

    int answer=0xfffffff;
    for(int i=0;i<4;i++){
        int num=moveBeads(N,M,r,b,1,i);
        if(num!=-1 && num<answer)
            answer=num;
    }
    if(answer==0xfffffff)
        answer=-1;
    cout<<answer<<endl;
    return 0;
}
void updatePosition(int &x, int &y, int xmove, int ymove){
    x+=xmove;
    y+=ymove;
}
bool isEqual(int x1, int y1, int x2, int y2){
    return (x1==x2) && (y1==y2);
}
int moveBeads(int N, int M, Position r, Position b, int iters, int direction){
    if(iters>10)return -1;
    
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int xmove=dx[direction];
    int ymove=dy[direction];
    
    bool isRedInHole=false;
    bool redStop=false,blueStop=false;
    while(true){
        if(!redStop && board[r.x+xmove][r.y+ymove]=='#')
            redStop=true;
        if(!blueStop && board[b.x+xmove][b.y+ymove]=='#')
            blueStop=true;
        
        if(redStop && blueStop)
            break;
        else if(redStop){
            if(isEqual(r.x,r.y,b.x+xmove,b.y+ymove))
                blueStop=true;
            else
                updatePosition(b.x, b.y, xmove, ymove);
        }
        else if(blueStop){
            if(isEqual(b.x,b.y,r.x+xmove,r.y+ymove))
                redStop=true;
            else
                updatePosition(r.x, r.y, xmove, ymove);
        }
        else{
            updatePosition(r.x, r.y, xmove, ymove);
            updatePosition(b.x, b.y, xmove, ymove);
        }
        if(board[b.x][b.y]=='O')return -1;
        if(isRedInHole==false && board[r.x][r.y]=='O'){
            isRedInHole=true;
            redStop=true;
            r.x=-1;
            r.y=-1;
        }
    }
    if(isRedInHole)return iters;

    int iteration=0xfffffff;
    int nextStep[2];
    nextStep[0]=moveBeads(N,M,r,b,iters+1,(direction+1)%4);
    nextStep[1]=moveBeads(N,M,r,b,iters+1,(direction+3)%4);
    for(int i=0;i<2;i++){
        if(nextStep[i]!=-1 && iteration>nextStep[i])
            iteration=nextStep[i];
    }
    if(iteration==0xfffffff)return -1;
    return iteration;
}



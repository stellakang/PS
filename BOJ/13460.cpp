#include <iostream>
using namespace std;

struct Position{
    int xpos,ypos;
};

int move(int N, int M, Position r, Position b, int iters, int direction);
void updatePosition(int &x, int &y, int xmove, int ymove);
bool isEqual(int x1, int y1, int x2, int y2);

char** board;

int main(int argc, const char * argv[]) {
    int N,M;
    scanf("%d%d",&N,&M);
    
    board = new char*[N];
    for(int i=0;i<N;i++)
        board[i]=new char[M];
    
    char tmp;
    scanf("%c",&tmp);
    
    Position r,b;
    for(int i=0;i<N;i++){
        scanf("%s",board[i]);
        for(int j=0;j<M;j++){
            if(board[i][j]=='R'){
                r.xpos=i;
                r.ypos=j;
            }
            else if(board[i][j]=='B'){
                b.xpos=i;
                b.ypos=j;
            }
        }
        scanf("%c",&tmp);
    }

    int iters=0xfffffff;
    for(int i=0;i<4;i++){
        int num=move(N,M,r,b,1,i);
        if(num!=-1 && num<iters)
            iters=num;
    }
    if(iters==0xfffffff)
        iters=-1;
    cout<<iters<<endl;
    return 0;
}
void updatePosition(int &x, int &y, int xmove, int ymove){
    x+=xmove;
    y+=ymove;
}
bool isEqual(int x1, int y1, int x2, int y2){
    if(x1==x2 && y1==y2)
        return true;
    else
        return false;
}
int move(int N, int M, Position r, Position b, int iters, int direction){
    if(iters>10)return -1;
 
    int rx=r.xpos;
    int ry=r.ypos;
    int bx=b.xpos;
    int by=b.ypos;
    
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int xmove=dx[direction];
    int ymove=dy[direction];
    
    bool isRedInHole=false;
    bool redStop=false,blueStop=false;
    while(true){
        if(!redStop && board[rx+xmove][ry+ymove]=='#')
            redStop=true;
        if(!blueStop && board[bx+xmove][by+ymove]=='#')
            blueStop=true;
        
        if(redStop && blueStop)
            break;
        else if(redStop){
            if(isEqual(rx,ry,bx+xmove,by+ymove))
                blueStop=true;
            else
                updatePosition(bx, by, xmove, ymove);
        }
        else if(blueStop){
            if(isEqual(bx,by,rx+xmove,ry+ymove))
                redStop=true;
            else
                updatePosition(rx, ry, xmove, ymove);
        }
        else{
            updatePosition(rx, ry, xmove, ymove);
            updatePosition(bx, by, xmove, ymove);
        }
        if(board[bx][by]=='O')return -1;
        if(isRedInHole==false && board[rx][ry]=='O'){
            isRedInHole=true;
            redStop=true;
            rx=-1;
            ry=-1;
        }
    }
    if(isRedInHole)return iters;
    
    r.xpos=rx;
    r.ypos=ry;
    b.xpos=bx;
    b.ypos=by;
    
    int iteration=0xfffffff;
    int nextStep[2];
    nextStep[0]=move(N,M,r,b,iters+1,(direction+1)%4);
    nextStep[1]=move(N,M,r,b,iters+1,(direction+3)%4);
    for(int i=0;i<2;i++){
        if(nextStep[i]!=-1 && iteration>nextStep[i])
            iteration=nextStep[i];
    }
    if(iteration==0xfffffff)return -1;
    return iteration;
}



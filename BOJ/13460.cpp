#include <iostream>
using namespace std;

//save red, blue position
struct Position{
    int x,y;
};
//set direction
struct Move{
    int xmove,ymove;
};

void updatePosition(Position &p, Move m);
bool isInFrontOf(Position p1, Position p2, Move m);
bool moveOneStep(Position &r, Position &b, Move m);
int moveUntilStop(Position &r, Position &b, Move m);
int run(Position r, Position b, int iters, int direction);

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
    //search for 4 directions at first and print answer
    int answer=0xfffffff;
    for(int i=0;i<4;i++){
        int num=run(r,b,1,i);
        if(num!=-1 && answer>num)
            answer=num;
    }
    if(answer==0xfffffff)
        answer=-1;
    cout<<answer<<endl;
    return 0;
}
//update position based on structure m
void updatePosition(Position &p, Move m){
    p.x+=m.xmove;
    p.y+=m.ymove;
}
//to check whether p1 is in front of p2 or not
bool isInFrontOf(Position p1, Position p2, Move m){
    return (p1.x==p2.x + m.xmove) && (p1.y==p2.y+m.ymove);
}
//whether moving one step is possible or not 
bool moveOneStep(Position &r, Position &b, Move m){
    char red=board[r.x][r.y];
    char redMove=board[r.x+m.xmove][r.y+m.ymove];
    char blueMove=board[b.x+m.xmove][b.y+m.ymove];
    
    if((red=='O' || redMove=='#') && blueMove=='#')return false;
    if(red!='O' && redMove=='#' && isInFrontOf(r,b,m))return false;
    if(red!='O' && blueMove=='#' && isInFrontOf(b,r,m))return false;
    
    if(red=='O' || redMove=='#')
        updatePosition(b,m);
    else if(blueMove=='#')
        updatePosition(r,m);
    else{
        updatePosition(r,m);
        updatePosition(b,m);
    }
    return true;
}
//move red and blue beads until they stops
int moveUntilStop(Position &r, Position &b, Move m){
    bool isRedInHole=false;
    while(moveOneStep(r,b,m)){
        if(board[b.x][b.y]=='O')return -1;
        if(board[r.x][r.y]=='O')
            isRedInHole=true;
    }
    if(isRedInHole)
        return 1;
    return 0;
}
//move to given direction at each iteration recursively 
int run(Position r, Position b, int iteration, int direction){
    if(iteration>10)return -1;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    
    int move = moveUntilStop(r,b,{dx[direction],dy[direction]});
    if(move==1) return iteration;
    if(move==-1) return -1;
    
    int minIteration=0xfffffff;
    int nextStep[2];
    nextStep[0]=run(r,b,iteration+1,(direction+1)%4);
    nextStep[1]=run(r,b,iteration+1,(direction+3)%4);
    for(int i=0;i<2;i++){
        if(nextStep[i]!=-1 && minIteration>nextStep[i])
            minIteration=nextStep[i];
    }
    if(minIteration==0xfffffff)return -1;
    return minIteration;
}

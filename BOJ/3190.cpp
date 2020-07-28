#include <iostream>
using namespace std;
//save rotation info
struct rotation{
    int time;
    char direction;
};
//save position
struct position{
    int x,y;
};
//deque implementation
template<typename T>class Deque{
private:
    int head,tail;
    int sz;
    T* values;
public:
    Deque(){
        sz = 101;
        values = new T[sz];
        head = 0;
        tail = 0;
    }
    void push_back(const T& element){
        values[tail] = element;
        tail = (tail + 1)%sz;
    }
    void push_front(const T& element){
        head = (head-1+sz)%sz;
        values[head] = element;
    }
    T& front(){
        return values[head];
    }
    T& back(){
        return values[(tail-1+sz)%sz];
    }
    void pop_back(){
        if(!empty())
        tail = (tail-1+sz)%sz;
    }
    void pop_front(){
        if(!empty())
        head = (head+1)%sz;
    }
    bool empty(){
        if(tail==head)
        return true;
        else
        return false;
    }
    int size(){
        return tail-head;
    }
};
void initBooleanArray(bool** &array, int N);
int dummyGame(int time, int N, position head, int direction, Deque<rotation> ro, Deque<position> snake);//play dummyGame

bool** apples;//check apples' location
bool** board;//check snake's body
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

int main(){
    int N,K,L,x,y,t;
    char d;
    cin>>N>>K;
    initBooleanArray(apples, N);
    initBooleanArray(board, N);
    for(int i=0;i<K;i++){
        cin>>x>>y;
        apples[x][y]=true;
    }
    cin>>L;
    Deque<rotation> ro;
    for(int i=0;i<L;i++){
        cin>>t>>d;
        ro.push_back({t,d});
    }
    Deque<position> snake;
    snake.push_back({1,1});
    board[1][1]=true;
    cout<<dummyGame(1,N,{1,1},1,ro,snake)<<"\n";
    return 0;
}
void initBooleanArray(bool** &array, int N){
    array = new bool*[N+1];
    for(int i=0;i<=N;i++){
        array[i] = new bool[N+1];
        for(int j=0;j<=N;j++)
            array[i][j]=false;
    }
}
int dummyGame(int time, int N, position head, int direction, Deque<rotation> ro, Deque<position> snake){
    //move head
    head.x += dx[direction];
    head.y += dy[direction];
    //check if the snake hit a wall
    if(head.x<=0 || head.x>N || head.y<=0 || head.y>N)
        return time;
    //check if the snake hit its body
    if(board[head.x][head.y])
        return time;
    //apply next move
    snake.push_front({head.x,head.y});
    board[head.x][head.y]=true;
    //if no apple, move tail
    if(!apples[head.x][head.y]){
        position back=snake.back();
        board[back.x][back.y]=false;
        snake.pop_back();
    }
    else
        apples[head.x][head.y]=false;
    //rotation change if it is in ro
    if(!ro.empty()){
        rotation r = ro.front();
        if(r.time==time){
            if(r.direction=='L')
            direction = (direction-1+4)%4;
            else
            direction = (direction+1)%4;
            ro.pop_front();
        }
    }
    return dummyGame(time+1, N, head, direction, ro, snake);
}


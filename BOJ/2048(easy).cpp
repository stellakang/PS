#include <iostream>
#define MAXVALUE 21
using namespace std;

//queue implementation
template<class T>class Queue{
private:
    int head;
    int tail;
    int sz;
    T *values;
public:
    Queue(){
        sz = MAXVALUE;
        values = new T[sz];
        head=0;
        tail=0;
    }
    ~Queue(){
        delete[] values;
    }
    void push(T element){
        values[tail] = element;
        tail = (tail + 1)%sz;
    }
    int front(){
        return values[head];
    }
    void pop(){
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
int run(int N, int block[21][21], int iteration);
int move(int N, int block[21][21], int iteration, int direction);
int toLeft(int N, int block[21][21]);
int toRightOrLeft(int N, int block[21][21], int start, int dj);
int toUpOrDown(int N, int block[21][21], int start, int dj);
void copyArray(int N, int copy[21][21], int block[21][21]);
int findMaxNum(int N, int block[21][21]);

int main(){
    int N;
    scanf("%d",&N);
    
    int block[21][21];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>block[i][j];
    cout<<run(N,block,1)<<endl;
    return 0;
}
int run(int N, int block[21][21], int iteration){
    if(iteration>5)return -1;
    int copy[21][21];
    copyArray(N, copy, block);
    int maxNum=0;
    //search for 4 directions
    for(int d=0;d<4;d++){
        copyArray(N, block, copy);
        int num=move(N,block,iteration,d);
        if(maxNum<num)
            maxNum=num;
    }
    return maxNum;
}
int move(int N, int block[21][21], int iteration, int direction){
    int maxNum=0;
    int num=0;
    //move block in the given direction
    if(direction==0)
        num = toRightOrLeft(N, block, 0, 1);//left
    else if(direction==1)
        num = toRightOrLeft(N, block, N-1, -1);//right
    else if(direction==2)
        num = toUpOrDown(N, block, 0, 1);//up
    else if(direction==3)
        num = toUpOrDown(N, block, N-1, -1);//down
    if(maxNum<num)
        maxNum=num;
    //next iteration
    int nextMove=run(N,block,iteration+1);
    return nextMove>maxNum? nextMove:maxNum;
}
int findMaxNum(int N, int block[21][21]){
    int maxNum=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(maxNum<block[i][j])
                maxNum = block[i][j];
        }
    }
    return maxNum;
}
void copyArray(int N, int copy[21][21], int block[21][21]){
    //copy block array to copy array
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            copy[i][j]=block[i][j];
}
int toUpOrDown(int N, int block[21][21], int start, int dj){
    for(int i=0;i<N;i++){
        Queue<int>qu;
        int j=start;
        while(true){
            if(block[j][i]){
                qu.push(block[j][i]);
                block[j][i]=0;
            }
            j+=dj;
            if(start==0 && j==N)break;//up
            if(start==N-1 && j==-1)break;//down
        }
        bool merge=false;
        for(int j=start;!qu.empty();){
            int num=qu.front();
            qu.pop();
            if(j==start){
                block[j][i]=num;
                j+=dj;
            }
            else if(!merge && block[j-dj][i]==num){
                merge=true;
                block[j-dj][i]+=num;
            }
            else{
                merge=false;
                block[j][i]=num;
                j+=dj;
            }
        }
    }
    return findMaxNum(N, block);
}
int toRightOrLeft(int N, int block[21][21], int start, int dj){
    for(int i=0;i<N;i++){
        Queue<int>qu;
        int j=start;
        while(true){
            if(block[i][j]){
                qu.push(block[i][j]);
                block[i][j]=0;
            }
            j+=dj;
            if(start==0 && j==N)break;//left
            if(start==N-1 && j==-1)break;//right
        }
        bool merge=false;
        for(int j=start;!qu.empty();){
            int num=qu.front();
            qu.pop();
            if(j==start){
                block[i][j]=num;
                j+=dj;
            }
            else if(!merge && block[i][j-dj]==num){
                merge=true;
                block[i][j-dj]+=num;
            }
            else{
                merge=false;
                block[i][j]=num;
                j+=dj;
            }
        }
    }
    return findMaxNum(N, block);
}


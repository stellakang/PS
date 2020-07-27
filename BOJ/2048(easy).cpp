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
int toRight(int N, int block[21][21]);
int toUp(int N, int block[21][21]);
int toDown(int N, int block[21][21]);
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
        num = toLeft(N, block);
    else if(direction==1)
        num = toRight(N, block);
    else if(direction==2)
        num = toUp(N, block);
    else if(direction==3)
        num = toDown(N, block);
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
int toUp(int N, int block[21][21]){
    Queue<int>up;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(block[j][i]){
                up.push(block[j][i]);
                block[j][i]=0;
            }
        }
        bool merge=false;
        for(int j=0;!up.empty();){
            int num=up.front();
            up.pop();
            if(j==0)
                block[j++][i]=num;
            else if(merge==false && block[j-1][i]==num){
                merge=true;
                block[j-1][i]+=num;
            }
            else{
                merge=false;
                block[j++][i]=num;
            }
        }
    }
    return findMaxNum(N, block);
}
int toDown(int N, int block[21][21]){
    Queue<int>down;
    for(int i=0;i<N;i++){
        for(int j=N-1;j>=0;j--){
            if(block[j][i]){
                down.push(block[j][i]);
                block[j][i]=0;
            }
        }
        bool merge=false;
        for(int j=N-1;!down.empty();){
            int num=down.front();
            down.pop();
            if(j==N-1)
                block[j--][i]=num;
            else if(!merge && block[j+1][i]==num){
                merge=true;
                block[j+1][i]+=num;
            }
            else{
                merge=false;
                block[j--][i]=num;
            }
        }
    }
    return findMaxNum(N, block);
}
int toLeft(int N, int block[21][21]){
    Queue<int>left;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(block[i][j]){
                left.push(block[i][j]);
                block[i][j]=0;
            }
        }
        bool merge=false;
        for(int j=0;!left.empty();){
            int num=left.front();
            left.pop();
            if(j==0)
                block[i][j++]=num;
            else if(!merge && block[i][j-1]==num){
                merge=true;
                block[i][j-1]+=num;
            }
            else{
                merge=false;
                block[i][j++]=num;
            }
        }
    }
    return findMaxNum(N, block);
}
int toRight(int N, int block[21][21]){
    Queue<int>right;
    for(int i=0;i<N;i++){
        for(int j=N-1;j>=0;j--){
            if(block[i][j]){
                right.push(block[i][j]);
                block[i][j]=0;
            }
        }
        bool merge=false;
        for(int j=N-1;!right.empty();){
            int num=right.front();
            right.pop();
            if(j==N-1)
                block[i][j--]=num;
            else if(!merge && block[i][j+1]==num){
                merge=true;
                block[i][j+1]+=num;
            }
            else{
                merge=false;
                block[i][j--]=num;
            }
        }
    }
    return findMaxNum(N, block);
}


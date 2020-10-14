#include <iostream>
using namespace std;

template<typename T>
class Queue{
private:
    int frontIndx,rearIndx;
    int capacity;
    int sz;
    T* value;
public:
    Queue(int len=10){
        frontIndx=0,rearIndx=0;
        value=new T[len];
        capacity=len;
        sz = 0;
    }
    ~Queue(){
        delete[] value;
    }
    void push(const T& num){
        if(sz==capacity){
            cout<<"error: queue is full\n";
            exit(1);
        }
        value[rearIndx]=num;
        rearIndx=(rearIndx+1)%capacity;
        sz++;
    }
    void pop(){
        if(sz==0){
            cout<<"error: queue is empty\n";
            exit(1);
        }
        frontIndx=(frontIndx+1)%capacity;
        sz--;
    }
    T front(){
        if(sz==0){
            cout<<"error: queue is empty\n";
            exit(1);
        }
        return value[frontIndx];
    }
    int size(){
        return sz;
    }
    bool empty(){
        return sz==0;
    }
};

int main(int argc, const char * argv[]) {
    Queue<int>qu;
    qu.push(1);
    cout<<qu.front()<<endl;
    qu.push(2);
    qu.pop();
    cout<<qu.size()<<endl;
    
    return 0;
}


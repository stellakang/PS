#include <iostream>
using namespace std;

template<typename T>
class Queue{
private:
    int frontIndx,rearIndx;
    int sz;
    T* value;
public:
    Queue(int len=10){
        frontIndx=0,rearIndx=0;
        value=new T[len];
        sz=len;
    }
    ~Queue(){
        delete[] value;
    }
    void push(const T& num){
        value[rearIndx]=num;
        rearIndx=(rearIndx+1)%sz;
    }
    void pop(){
        frontIndx=(frontIndx+1)%sz;
    }
    T front(){
        return value[frontIndx];
    }
    int size(){
        return rearIndx-frontIndx;
    }
    bool empty(){
        return rearIndx-frontIndx==0;
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


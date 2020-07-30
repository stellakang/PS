#include <iostream>
using namespace std;

template<typename T>
class Stack{
private:
    int topIndx;
    int sz;
    T* value;
public:
    Stack(int len=10){
        topIndx=-1;
        value=new T[len];
 	sz=len;
    }
    ~Stack(){
        delete[] value;
    }
    void push(const T& num){
	topIndx=(topIndx+1)%sz;
        value[topIndx]=num;
    }
    void pop(){
	topIndx=(topIndx-1+sz)%sz;
    }
    T top(){
        return value[topIndx];
    }
    int size(){
        return topIndx+1;
    }
    bool empty(){
        return topIndx==-1;
    }
};

int main(int argc, const char * argv[]) {
    Stack<int>st;
    st.push(1);
    cout<<st.top()<<endl;
    st.push(2);
    st.pop();
    cout<<st.size()<<endl;
    
    return 0;
}


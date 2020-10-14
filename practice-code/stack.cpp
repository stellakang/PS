#include <iostream>
using namespace std;

template<typename T>
class Stack{
private:
    int topIndx;
    int capacity;
    int sz;
    T* value;
public:
    Stack(int len=10){
        topIndx=-1;
        value=new T[len];
 	capacity=len;
	sz = 0;
    }
    ~Stack(){
        delete[] value;
    }
    void push(const T& num){
	if(sz==capacity){
	    cout<<"error: stack is full\n";
	    exit(1);
	}
	topIndx=(topIndx+1)%capacity;
        value[topIndx]=num;
	sz++;
    }
    void pop(){
	if(sz==0){
	    cout<<"error: stack is empty\n";
	    exit(1);
	}
	sz--;
	topIndx=(topIndx-1+capacity)%capacity;
    }
    T top(){
	if(sz==0){
	    cout<<"error: stack is empty\n";
	    exit(1);
	}
        return value[topIndx];
    }
    int size(){
        return sz;
    }
    bool empty(){
        return sz==0;
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


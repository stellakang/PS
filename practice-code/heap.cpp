#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
class MinHeap{
private:
    vector<int>h;
    int size;
public:
    MinHeap():size(0){
        h.push_back(-1);
    }
    void push(T item){
        h.push_back(item);
        int curr = ++size;
        while(curr>=1 && h[curr/2]>h[curr]){
            swap(h[curr/2], h[curr]);
            curr /= 2;
        }
    }
    T pop(){
        if(size == 0){
            cout<<"Heap is empty\n";
            exit(1);
        }
        T val = h[1];
        h[1] = h[size--];
        h.pop_back();

        int curr = 0;
        while(curr*2<=size){
            int child = curr*2;
            if(child+1<=size && h[child]>h[child+1])child++;
            if(h[curr] > h[child]){
                swap(h[curr], h[child]);
                curr = child;
            }
            else
                break;
        }
        cout<<"element: "<<val<<"\n";
        return val;
    }

};
int main(){
    MinHeap<int> heap;
    heap.push(12345678);
    heap.push(1);
    heap.push(2);
    heap.pop();
    heap.pop();
    heap.pop();
    heap.push(32);
    return 0;
}


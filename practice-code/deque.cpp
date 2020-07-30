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
    ~Deque(){
        delete[] values;
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
        return (tail-head+sz)%sz;
    }
};

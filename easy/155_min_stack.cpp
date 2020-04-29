class MinStack {
    vector<int> minStack;
    vector<pair<int,int>> minVal;
    int minStackPoint;
    int minValPoint;
public:
    /** initialize your data structure here. */
    MinStack() {   
        minStackPoint=-1;
        minValPoint=-1;
    }
    
    void push(int x) {
        minStack.push_back(x);
        minStackPoint++;
        if(minValPoint<0 || (minValPoint>=0 && minVal[minValPoint].first>x)){
            minVal.push_back(make_pair(x,1));
            minValPoint++;
        }
        else
            minVal[minValPoint].second+=1;
    }
    
    void pop() {
        if(minStackPoint>=0){
            minStack.pop_back();
            minStackPoint--;
            if(--minVal[minValPoint].second==0){
                minVal.pop_back();
                minValPoint--;
            }
        }
        else
            printf("pop() : empty stack\n");
    }
    
    int top() {
        if(minStackPoint>=0)
            return minStack[minStackPoint];
        else{
            printf("top() error : empty stack\n");
            return -1;
        }
    }
    
    int getMin() {
        if(minValPoint>=0)
            return minVal[minValPoint].first;    
        else{
            printf("getMin() error : empty stack\n");
            return -1;
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

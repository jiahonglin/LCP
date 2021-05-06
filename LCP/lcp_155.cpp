class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min.push(INT_MAX);
    }
    
    void push(int val) {
        data.push(val);
        if(min.top() >= val){
            min.push(val);
        }
    }
    
    void pop() {
        if(top() == min.top()){
            min.pop();
        }
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min.top();
    }
private:
    stack<int> data;
    stack<int> min;
    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

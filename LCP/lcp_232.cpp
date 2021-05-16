class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        elenum = 0;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
        elenum++;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int sol;
        while(!s1.empty()){
            sol = s1.top();
            s2.push(sol);
            s1.pop();
        }
        s2.pop();
        while(!s2.empty()){
            int tmp;
            tmp=s2.top();
            s2.pop();
            s1.push(tmp);
        }
        elenum--;
        return sol;
    }
    
    /** Get the front element. */
    int peek() {
        int sol;
        while(!s1.empty()){
            sol = s1.top();
            s2.push(sol);
            s1.pop();
        }
        while(!s2.empty()){
            int tmp;
            tmp=s2.top();
            s2.pop();
            s1.push(tmp);
        }
        return sol;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return elenum==0?true:false;
    }
private:
    stack<int> s1;
    stack<int> s2;
    int elenum;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

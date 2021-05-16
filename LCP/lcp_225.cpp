class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        elenum=0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
        elenum++;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int cnt=0;
        int sol=0;
        while(cnt<elenum-1){
            int tmp;
            tmp = q1.front();
            q1.pop();
            q2.push(tmp);
            cnt++;
        }
        sol = q1.front();
        q1.pop();
        while(!q2.empty()){
            int tmp;
            tmp = q2.front();
            q1.push(tmp);
            q2.pop();
        }
        elenum--;
        return sol;
    }
    
    /** Get the top element. */
    int top() {
        int sol=0;
        while(!q1.empty()){
            sol = q1.front();
            q1.pop();
            q2.push(sol);
        }
        while(!q2.empty()){
            int tmp;
            tmp = q2.front();
            q1.push(tmp);
            q2.pop();
        }
        return sol;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return (elenum==0)?true:false;
    }
private:
    queue<int> q1;
    queue<int> q2;
    int elenum;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

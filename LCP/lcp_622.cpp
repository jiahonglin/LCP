class MyCircularQueue {
private:
    int head=0,tail=0;
    int maxsize;
    vector<int> myqueue;
public:
    MyCircularQueue(int k) {
        for(int i=0;i<k;i++) myqueue.push_back(-1);
        maxsize=k;
    }
    
    bool enQueue(int value) {
        bool ret=false;
        if(myqueue[tail] == -1){
            myqueue[tail] = value;
            ret = true;
            ((tail+1)<maxsize)?tail++:tail=0;
        }
        return ret;
    }
    
    bool deQueue() {
        bool ret = false;
        if(myqueue[head] != -1){
            myqueue[head]=-1;
            ret = true;
            ((head+1)<maxsize)?head++:head=0;
        }
        return ret;
    }
    
    int Front() {
        return myqueue[head];
    }
    
    int Rear() {
        if(tail-1<0){
            return myqueue[maxsize-1];
        }
        else{
            return myqueue[tail-1];
        }
    }
    
    bool isEmpty() {
        for(int i=0;i<maxsize;i++){
            if(myqueue[i]!=-1){
                return false;
            }
        }
        return true;
    }
    
    bool isFull() {
        for(int i=0;i<maxsize;i++){
            if(myqueue[i]==-1){
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

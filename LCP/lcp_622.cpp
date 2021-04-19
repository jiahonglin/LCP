class MyCircularQueue {
private:
    int head=0,tail=0,cnt=0;
    int maxsize;
    vector<int> myqueue;
public:
    MyCircularQueue(int k) {
        myqueue.resize(k);
        head = k-1;
        tail = 0;
        cnt=0;
        maxsize=k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        myqueue[tail] = value;
        cnt++;
        tail = (tail+1)%maxsize;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        cnt--;
        head = (head+1)%maxsize;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return myqueue[(head+1)%maxsize];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return myqueue[(tail-1+maxsize)%maxsize];
    }
    
    bool isEmpty() {
        return (cnt==0)?true:false;
    }
    
    bool isFull() {
        return (cnt>=maxsize)?true:false;
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

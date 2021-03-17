class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        Head = NULL;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= size) return -1;
        Node *cur=Head;
        for(int i=0; i<index;i++){
            cur = cur->next;
        }
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *cur = new Node(val, Head);
        Head = cur;
        if(size==0) {
            Tail = cur;
        }
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *cur = new Node(val,NULL);
        if(size == 0){
            Tail = cur;
            Head = cur;
        }
        Tail->next = cur;
        Tail = cur;
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index == size) addAtTail(val);
        else if (index == 0) addAtHead(val);
        else if (index > size) return;
        else{
            Node *cur=Head;
            for(int i=0; i<index-1;i++){
                cur=cur->next;
            }
            Node *ins = new Node(val, cur->next);
            cur->next = ins;
            size++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= size) return;
        else if (index == 0){
            Head = Head->next;
            size--;
        }
        else{
            Node *cur = Head;
            for(int i=0;i<index-1;i++){
                cur = cur->next;
            }
            cur->next = cur->next->next;
            if(index == size-1) Tail = cur;
            size--;
        }
    }
private:
    struct Node {
        int val;
        Node *next;
        Node(int x, Node *n):val(x), next(n){}
    };
    Node *Head, *Tail;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

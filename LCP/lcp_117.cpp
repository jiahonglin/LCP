/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        Node* p = root->next;
        while(p){
            if(p->left){
                p = p->left;
                break;
            }
            if(p->right){
                p = p->right;
                break;
            }
            p = p->next;
        }
        if(root->left) root->left->next = (root->right)?root->right:p;
        if(root->right) root->right->next = p;
        
        connect(root->right);
        connect(root->left);

        return root;
    }
/*
    Node* connect(Node* root) {
        Node* dummy = new Node(-1);
        Node* cur = dummy;
        Node* head = root;
        while(root){
            if(root->left){
                cur->next = root->left;
                cur = cur->next;
            }
            if(root->right){
                cur->next = root->right;
                cur = cur->next;
            }
            root = root->next;
            if(!root){
                root = dummy->next;
                dummy->next = NULL;
                cur = dummy;
            }
        }
        return head;
    }
*/
/*
    Node* connect(Node* root) {
        if(!root) return {};
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            Node* cur = NULL;
            for(int i=0;i<sz;i++){
                Node* t = q.front();
                if(cur == NULL){
                    cur = t;
                }
                else{
                    cur->next = t;
                    cur = cur->next;
                }
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                q.pop();
            }
        }
        return root;
    }
*/
};

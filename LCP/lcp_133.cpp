/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    /*BFS*/
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> m;
        if(!node) return NULL;
        queue<Node*> q{{node}};
        m[node] = new Node(node->val);
        while(!q.empty()){
            Node* t = q.front(); q.pop();
            for(Node* neighbor:t->neighbors){
                if(!m.count(neighbor)){
                    m[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                m[t]->neighbors.push_back(m[neighbor]);
            }
        }
        return m[node];
    }
    
    /*DFS*/
    /*
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> m;
        return startClone(node, m);
    }
    
    Node* startClone(Node* node, unordered_map<Node*, Node*> &m){
        if(!node) return NULL;
        if(m.count(node)) return m[node];
        Node* n = new Node(node->val);
        m[node] = n;
        for(int i=0;i< node->neighbors.size();i++){
            Node* neighbor = (node->neighbors)[i];
            n->neighbors.push_back(startClone(neighbor,m));
        }
        return n;
    }
    */
};

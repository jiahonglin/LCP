class TrieNode {
    public:
        TrieNode* node[26];
        bool isEnd;
        TrieNode() {
            isEnd = false;
            for(auto &a:node) a=NULL;
        }
};

class Trie {
public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* p=root;
        for(auto c:word){
            int index=c-'a';
            if(!p->node[index]){
                p->node[index] = new TrieNode();
            }
            p=p->node[index];
        }
        p->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* p = root;
        for(auto c:word){
            int index = c-'a';
            if(!p->node[index]) return false;
            p = p->node[index];
        }
        return p->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for(auto c:prefix){
            int index = c-'a';
            if(!p->node[index]) return false;
            p=p->node[index];
        }
        return true;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

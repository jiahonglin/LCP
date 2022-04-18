class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<unordered_set<int>> adj(n);
        queue<int> q;
        vector<int> res;
        for(auto e:edges){
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }
        for(int i=0;i<n;i++){
            if(adj[i].size() == 1){
                q.push(i);
            }
        }
        while(n > 2){
            int size = q.size();
            n-=size;
            for(int i = 0;i < size;i++){
                int leaf = q.front();q.pop();
                for(auto a:adj[leaf]){
                    adj[a].erase(leaf);
                    if(adj[a].size() == 1) q.push(a);
                }
            }
        }
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};

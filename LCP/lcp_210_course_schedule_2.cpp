class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> entry(numCourses,0);
        vector<int> topology;
        queue<int> q;
        for(auto &a:prerequisites){
            graph[a[1]].push_back(a[0]);
            entry[a[0]]++;
        }
        for(int i=0;i<numCourses;i++){
            if(entry[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int step=q.front();q.pop();
            topology.push_back(step);
            for(auto &a:graph[step]){
                entry[a]--;
                if(entry[a] == 0) q.push(a);
            }
        }
        if(topology.size() != numCourses) topology.clear();
        return topology;
    }
};

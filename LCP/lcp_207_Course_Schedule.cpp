class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> inCourse(numCourses,0);
        queue<int> q;
        for(auto a:prerequisites){
            graph[a[1]].push_back(a[0]);
            inCourse[a[0]]++;
        }
        for(int i=0;i<numCourses;i++){
            if(inCourse[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int c = q.front();q.pop();
            for(auto a:graph[c]){
                inCourse[a]--;
                if(inCourse[a] == 0) q.push(a);
            }
        }
        for(int i=0;i<numCourses;i++){
            if(inCourse[i] != 0) return false;
        }
        return true;
    }
};

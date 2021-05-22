class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int totalRooms = rooms.size();
        vector<int> visited(totalRooms,0);
        stack<int> s;
        for(int i = 0;i<rooms[0].size();i++){
            s.push(rooms[0][i]);
        }
        visited[0]=1;
        while(!s.empty()){
            int keys = s.top();s.pop();
            for(int i=0;i<rooms[keys].size();i++){
                if(visited[rooms[keys][i]] == 0 && keys != rooms[keys][i]){
                    s.push(rooms[keys][i]);
                }
            }
            visited[keys]=1;
        }
        for(int m=0;m<totalRooms;m++){
            if(visited[m] == 0) return false;
        }
        return true;
    }
};

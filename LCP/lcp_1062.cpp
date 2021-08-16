class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int sol=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) continue;
                grid[i][j] = 201;
                if(i>0) grid[i][j] = min(grid[i][j],grid[i-1][j]+1);
                if(j>0) grid[i][j] = min(grid[i][j], grid[i][j-1]+1);
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==1) continue;
                if(i<n-1) grid[i][j] = min(grid[i][j], grid[i+1][j]+1);
                if(j<n-1) grid[i][j] = min(grid[i][j], grid[i][j+1]+1);
                sol = max(sol,grid[i][j]);
            }
        }
        return sol==201?-1:sol-1;
        /*BFS*/
        /*
        queue<vector<int>> q;
        vector<vector<int>> dirs{{-1,0},{1,0},{0,-1},{0,1}};
        int steps=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[i][j] == 1)
                    q.push(vector<int>{i,j});
            }
        }

        if(q.empty() || q.size()==grid.size()*grid.size()) return -1;
        while(!q.empty()){
            steps++;
            for(int k=q.size();k>0;k--){
                vector<int> t = q.front();q.pop();
                int m=t[0]; int n = t[1];
                for(auto dir:dirs){
                    if(m+dir[0]<0 || m+dir[0]>=grid.size() || n+dir[1]<0 || n+dir[1]>grid.size() || grid[m+dir[0]][n+dir[1]]!=0) continue;
                    grid[m+dir[0]][n+dir[1]] = steps;
                    q.push({m+dir[0],n+dir[1]});
                }
            }
        }
        return steps-1;
        */
    }    
};

class Solution {
public:
    /**BFS**/
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m=grid.size(), n=grid[0].size(), res=0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        int dirX[4] = {-1,0,1,0};
        int dirY[4] = {0,-1,0,1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='0' || visited[i][j]) continue;
                visited[i][j]=true;
                res++;
                queue<int> q;
                q.push(i*n+j);
                while(q.size()>0){
                    int tmp = q.front();
                    q.pop();
                    for(int s=0;s<4;s++){
                        int x = tmp/n + dirX[s];
                        int y = tmp%n + dirY[s];
                        if(x<0 || x >=m || y<0 || y>=n || grid[x][y]=='0' || visited[x][y]) continue;
                        visited[x][y]=true;
                        q.push(x*n+y);
                    }
                }
            }
        }
        return res;
    }
    /**DFS**/
    /*
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size(), res=0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='0' || visited[i][j]) continue;
                checkAdjacent(grid, visited, i, j);
                res++;
            }
        }
        return res;
    }
    void checkAdjacent(vector<vector<char>>& grid, vector<vector<bool>> &visited, int x, int y) {
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]=='0' || visited[x][y]) return;
        visited[x][y] = true;
        checkAdjacent(grid, visited, x-1, y);
        checkAdjacent(grid, visited, x+1, y);
        checkAdjacent(grid, visited, x, y-1);
        checkAdjacent(grid, visited, x, y+1);
    }
    */
};

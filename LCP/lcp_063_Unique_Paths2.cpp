class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return findPaths(obstacleGrid,0,0,dp);
    }
    int findPaths(vector<vector<int>>& Grid, int x, int y, vector<vector<int>>& dp){
        if(x >= Grid.size() || y>= Grid[0].size() || Grid[x][y]!=0) return 0;
        if(x == Grid.size()-1 && y == Grid[0].size()-1){
            return 1;
        }
        if(dp[x][y] != -1) return dp[x][y];
        dp[x][y]=findPaths(Grid,x+1,y,dp)+findPaths(Grid,x,y+1,dp);
        return dp[x][y];
    }
};

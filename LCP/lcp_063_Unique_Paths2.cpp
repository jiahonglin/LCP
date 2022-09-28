class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return cal(obstacleGrid,dp,m-1,n-1);
    }
    int cal(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp, int m, int n){
        if(dp[m][n] != -1) return dp[m][n];
        if(obstacleGrid[m][n] == 1) return dp[m][n]=0;
        if(m==0 && n==0) return dp[m][n]=1;
    
        int ans=0;
        if(m>0) ans+=cal(obstacleGrid,dp,m-1,n);
        if(n>0) ans+=cal(obstacleGrid,dp,m,n-1);
        return dp[m][n] = ans;
    }
        /*
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j] == 1){
                    obstacleGrid[i][j]=0;
                    continue;
                }
                if(i-1 >= 0  && j-1 >= 0){
                    obstacleGrid[i][j] = obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
                }
                else if(i-1>=0){
                    obstacleGrid[i][j] = obstacleGrid[i-1][j];
                }
                else if(j-1>=0){
                    obstacleGrid[i][j] = obstacleGrid[i][j-1];
                }
                else{
                    obstacleGrid[i][j]=1;
                }
            }
        }
        return obstacleGrid[m-1][n-1];
    }
    */
/*
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
*/
};

class NumMatrix {
public:
    vector<vector<int>> dp;
    int m = 0;
    int n = 0;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        dp.resize(m+1, vector<int>(n+1, 0));
        for(int x=1;x<=m;x++){
            for(int y=1;y<=n;y++){
                dp[x][y] = dp[x][y-1]+dp[x-1][y]-dp[x-1][y-1]+matrix[x-1][y-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1]-dp[row1][col2+1]-dp[row2+1][col1]+dp[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

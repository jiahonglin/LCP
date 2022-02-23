class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0) dp[i][j] = matrix[i][j]-'0';
                else if(matrix[i][j] == '1') dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                ans = max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }

    /*Method 1:*/
    /*
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++){
            vector<int> v(n,0);
            for(int j = i; j < m; j++){
                for(int k = 0; k < n; k++){
                    if(matrix[j][k] == '1') v[k]++;
                }
                ans = max(ans, getSquare(v,j-i+1));
            }
        }
        return ans;
    }
    int getSquare(vector<int>& v, int k){
        int count = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i] != k) count = 0;
            else count++;
            if(count == k) return k*k;
        }
        return 0;
    }
    */
};

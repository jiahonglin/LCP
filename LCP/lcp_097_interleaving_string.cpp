class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;
        int n1 = s1.length();
        int n2 = s2.length();
        vector<vector<bool>> dp(n1+1,vector<bool>(n2+1,false));
        dp[0][0] = true;

        for(int j=1; j<=n2; j++){
            dp[0][j] = (dp[0][j-1] && s2[j-1] == s3[j-1]);
        }
        for(int i=1; i<=n1; i++){
            dp[i][0] = (dp[i-1][0] && s1[i-1] == s3[i-1]);
        }
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                dp[i][j] = ((dp[i][j-1] && s2[j-1] == s3[j-1+i]) || (dp[i-1][j] && s1[i-1] == s3[i-1+j]));
            }
        }
        return dp[n1][n2];
    }

    /*
    bool isInterleave(string s1, string s2, string s3) {
        int l1=s1.length();
        int l2=s2.length();
        int l3=s3.length();
        if(l1+l2 != l3) return false;
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(l1+1,vector<bool>(l2+1,false));
        q.push({0,0});
        while(!q.empty()){
            auto p = q.front(); q.pop();
            if(p.first == l1 && p.second == l2) return true;
            if(visited[p.first][p.second]) continue;
            if(p.first < l1 && s1[p.first] == s3[p.first+p.second]) q.push({p.first+1,p.second});
            if(p.second < l2 && s2[p.second] == s3[p.first+p.second]) q.push({p.first,p.second+1});
            visited[p.first][p.second]=true;
        }
        return false;
        
    }
    */
};

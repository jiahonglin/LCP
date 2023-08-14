class Solution {
public:
    int numSquares(int n) {
        while(n%4==0) n/=4;
        if(n%8 == 7) return 4;
        for(int i=0;i*i<=n;i++){
            int j = sqrt(n-i*i);
            if(i*i+j*j==n) return !!i+!!j;
        }
        return 3;
    }
    /*
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i=0;i<=n;i++){
            for(int j=1;i+j*j<=n;j++){
                dp[i+j*j] = min(dp[i+j*j],dp[i]+1);
            }
        }
        return dp.back();
    }
    */
};

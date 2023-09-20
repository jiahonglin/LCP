class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n==1) return 1;
        vector<int> dp;
        vector<int> cnt(primes.size(),0);
        dp.push_back(1);
        while(dp.size() < n){
            vector<long long int> tmp(primes.size(),0);
            for(int i=0;i<primes.size();i++){
                tmp[i]=(long long int)primes[i]*dp[cnt[i]];
            }
            int minimum = INT_MAX;
            for(int i=0;i<primes.size();i++){
                if(tmp[i] < minimum){
                    minimum = tmp[i];
                }
            }
            for(int i=0;i<primes.size();i++){
                if(tmp[i]==minimum) cnt[i]++;
            }
            dp.push_back(minimum);
        }
        return dp.back();
    }
    /*
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n);
        if(n==1) return 1;
        dp[0]=1;
        vector<int> dp_pri(primes.size(),0),candidate(primes);
        for(int j=1;j<n;j++)
        {
            int mm=INT_MAX;
            for(int k=0;k<primes.size();k++)
            {
                if(candidate[k]==dp[j-1])
                {
                    dp_pri[k]++;
                    candidate[k]=primes[k]*dp[dp_pri[k]];
                }
                mm=min(mm,candidate[k]);
            }
            dp[j]=mm;
        }
        return dp[n-1];
    }
    */
};

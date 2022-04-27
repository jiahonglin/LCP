class Solution {
public:
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
        /*
        vector<int> uglyList;
        vector<int> facList(primes.size(),0);
        uglyList.push_back(1);
        while(uglyList.size() < n){
            vector<int> tmp;
            for(int i=0;i<primes.size();i++){
                tmp.push_back(uglyList[facList[i]]*primes[i]);
            }
            int minVal = INT_MAX;
            int minIdx = 0;
            for(int i=0;i<primes.size();i++){
                minVal = min(minVal,tmp[i]);
            }
            for(int i=0;i<primes.size();i++){
                if(tmp[i] == minVal) facList[i]++;
            }
            uglyList.push_back(minVal);
        }
        return uglyList.back();
        */
    }
};

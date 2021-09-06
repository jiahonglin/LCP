class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long res=0;
        long M=1e9+7;
        unordered_map<int,long> dp;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            dp[arr[i]] = 1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0 && dp.count(arr[i]/arr[j])!=0){
                    dp[arr[i]] = (dp[arr[i]] + (dp[arr[j]] * dp[arr[i]/arr[j]])) % M;
                }
            }
        }
        for(auto a:dp) res=(res+a.second)%M;
        return res;
    }
};

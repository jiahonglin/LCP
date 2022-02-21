class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        int minsum = (1+k)*k/2;
        if(n < minsum) return {};
        vector<int> combine;
        doCombination(k,n,1,combine);
        return ans;
    }
    void doCombination(int k, int n, int start, vector<int>& combine){
        if(combine.size() > k) return;
        if(combine.size() == k){
            int sum=0;
            for(int m=0;m<combine.size();m++) sum+=combine[m];
            if(sum==n) ans.push_back(combine);
            else return;
        }
        for(int i=start;i<=9;i++){
            combine.push_back(i);
            doCombination(k,n,i+1,combine);
            combine.pop_back();
        }
    }
};

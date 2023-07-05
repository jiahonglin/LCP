class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k > n) return {};
        vector<int> sum;
        vector<vector<int>> ans;
        generateSum(k,n,1,sum,ans);
        return ans;
    }
    void generateSum(int k, int n, int start, vector<int>& sum, vector<vector<int>>& ans){
        if(sum.size() == k && n==0){
            ans.push_back(sum);
            return;
        }
        if(n < 0 || sum.size() > k) return;
        for(int i=start;i<=9;i++){
            sum.push_back(i);
            generateSum(k,n-i,i+1,sum,ans);
            sum.pop_back();
        }
    }
/*
    vector<vector<int>> combinationSum3(int k, int n) {
        int minSum = (k+1)*k/2;
        if(n < minSum) return {};
        vector<int> combination;
        vector<vector<int>> ans;
        docombination(k,n,1,combination,ans);
        return ans;
    }
    void docombination(int k, int n, int start, vector<int>& combination, vector<vector<int>>& ans){
        if(combination.size() > k) return;
        if(combination.size() == k){
            int sum=0;
            for(int i=0;i<combination.size();i++) sum+=combination[i];
            if(sum == n) ans.push_back(combination);
            return; 
        }
        for(int j=start;j<=9;j++){
            combination.push_back(j);
            docombination(k,n,j+1,combination,ans);
            combination.pop_back();
        }
        
    }
    */
};

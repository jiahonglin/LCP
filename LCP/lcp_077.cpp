class Solution {
public:
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> sol;
        combineNum(res,sol,1,n,k);
        return res;
    }
    void combineNum(vector<vector<int>>& res, vector<int>& sol, int step, int n, int k){
        if(sol.size()==k){
            res.push_back(sol);
            return;
        };
        for(int i=step;i<=n;i++){
            sol.push_back(i);
            combineNum(res,sol,i+1,n,k);
            sol.pop_back();
        }
    }
    
    /*vector<vector<int>> combine(int n, int k) {
        if(k>n || k<0) return {};
        if(k==0) return {{}};
        vector<vector<int>> res = combine(n-1,k-1);
        for(auto &a : res) a.push_back(n);
        for(auto &a : combine(n-1,k)) res.push_back(a);
        return res;
    }
    */
};

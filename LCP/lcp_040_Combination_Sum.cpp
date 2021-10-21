class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> out;
        vector<vector<int>> sol;
        sort(candidates.begin(),candidates.end());
        doCombination2(candidates, target, 0, 0, out, sol);
        return sol;
    }
    void doCombination2(vector<int>& candidates,int target,int idx,int sum,vector<int>& out,vector<vector<int>>& sol){
        if(sum == target){
            sol.push_back(out);
            return;
        }
        if(sum > target) return;
        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i] == candidates[i-1]) continue;
            out.push_back(candidates[i]);
            doCombination2(candidates, target, i+1, sum+candidates[i], out, sol);
            out.pop_back();
        }
    }
};

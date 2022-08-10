class Solution {
public:
    vector<vector<int>> sol;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        doCombination(candidates,target,0,0,tmp);
        return sol;
    }
    void doCombination(vector<int>& candidates, int target, int sum, int idx, vector<int>& tmp){
        if(sum == target){
            sol.push_back(tmp);
            return;
        }
        if(sum > target || idx == candidates.size()) return;
        tmp.push_back(candidates[idx]);
        doCombination(candidates,target,sum+candidates[idx],idx,tmp);
        tmp.pop_back();
        doCombination(candidates,target,sum,idx+1,tmp);
    }
};

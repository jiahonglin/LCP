class Solution {
public:
    set<vector<int>> s;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> v;
        genSubset(nums,0,v);
        vector<vector<int>> sol(s.begin(),s.end());
        return sol;
    }
    void genSubset(vector<int>& nums, int idx, vector<int> v){
        s.insert(v);
        if(idx >= nums.size()) return;
        for(int i=idx;i<nums.size();i++){
            v.push_back(nums[i]);
            genSubset(nums,i+1,v);
            v.pop_back();
        }
    }
};

class Solution {
public:
    /*Mathod 1:Iterative*/
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sol;
        sol.push_back({});
        for(int i=0;i<nums.size();i++){
            int size = sol.size();
            for(int j=0;j<size;j++){
                sol.push_back(sol[j]);
                sol.back().push_back(nums[i]);
            }
        }
        return sol;
    }

    /*Mathod 2:Recursive*/
    /*
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> out;
        makeSubset(nums,0,out,sol);
        return sol;
    }

    void makeSubset(vector<int>& nums, int pos, vector<int>& out, vector<vector<int>>& sol){
        sol.push_back(out);
        for(int i=pos;i<nums.size();i++){
            out.push_back(nums[i]);
            makeSubset(nums,i+1,out,sol);
            out.pop_back();
        }
    }
    */
};

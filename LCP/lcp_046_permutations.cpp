class Solution {
public:
/*
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> out;
        vector<int> visited(nums.size(),0);
        permuteDFS(nums,sol,out,0, visited);
        return sol;
    }
    void permuteDFS(vector<int>& nums, vector<vector<int>>& sol, vector<int>& out, int step, vector<int>& visited){
        if(step == nums.size()){
            sol.push_back(out);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i] == 0){
                out.push_back(nums[i]);
                visited[i] =1;
                permuteDFS(nums,sol,out, step+1, visited);
                out.pop_back();
                visited[i]=0;
            }
        }
    }
 */
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> sol;
        helper(nums,0,sol);
        return sol;
    }
    void helper(vector<int>& nums, int pos, vector<vector<int>>& sol){
        if(pos >= nums.size()){
            sol.push_back(nums);
            return;
        }
        for(int i=pos ; i<nums.size() ; i++){
            swap(nums[pos],nums[i]);
            helper(nums,pos+1,sol);
            swap(nums[i],nums[pos]);
        }
    }
};

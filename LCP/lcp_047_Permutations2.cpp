class Solution {
public:
    /*Method 2*/
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>> sol;
        doPermute(nums,0,s);
        for(auto t:s){
            sol.push_back(t);
        }
        return sol;
    }
    void doPermute(vector<int>& nums, int start, set<vector<int>>& s){
        if(start < nums.size()){
            s.insert(nums);
        }
        for(int i=start;i<nums.size();i++){
            if(i>start && nums[i]==nums[start]) continue;
            swap(nums[i],nums[start]);
            doPermute(nums,start+1,s);
            swap(nums[start],nums[i]);
        }
    }
    
    /*Method 1*/
    /*
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> visited(nums.size(),0);
        vector<int> out;
        vector<vector<int>> sol;
        sort(nums.begin(),nums.end());
        doPermute(nums,visited,0,out,sol);
        return sol;
    }
    void doPermute(vector<int>& nums, vector<int>& visited, int cnt, vector<int>& out, vector<vector<int>>& sol){
        if(cnt >= nums.size()){
            sol.push_back(out);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i]==1) continue;
            if(i>0 && nums[i]==nums[i-1] && visited[i-1]==0) continue;
            visited[i]=1;
            out.push_back(nums[i]);
            doPermute(nums,visited,cnt+1,out,sol);
            out.pop_back();
            visited[i]=0;
        }
    }
    */
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> sol;
        if(nums.size()<4) return {};
        sort(nums.begin(),nums.end());
        if((target>=0 && nums.front() > target) || (target<=0 && nums.back() < target)) return{};
        for(int i=0;i<nums.size()-3;i++){
            for(int j=i+1;j<nums.size()-2;j++){
                if(j > i+1 && nums[j]==nums[j-1]) continue;
                int left = j+1;
                int right = nums.size()-1;
                while(left<right){
                    int sum = nums[i]+nums[j]+nums[left]+nums[right];
                    vector<int> tmp{nums[i],nums[j],nums[left],nums[right]};
                    if(sum == target && !isExist(sol, tmp)){
                        sol.push_back(tmp);
                    }
                    else if(sum < target) left++;
                    else right--;
                }
            }
        }
        return sol;
    }
    bool isExist(vector<vector<int>>& sol, vector<int> tmp){
        bool ret = false;
        for(int i=0;i<sol.size();i++){
            if(sol[i][0] == tmp[0] && sol[i][1] == tmp[1] && sol[i][2] == tmp[2] && sol[i][3] == tmp[3]){
                ret = true;
            }
        }
        return ret;
    }
};

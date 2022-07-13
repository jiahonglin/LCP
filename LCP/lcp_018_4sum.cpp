class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n  = nums.size();
        vector<vector<int>> sol;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n-3;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1;j<n-2;j++){
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                int left = j+1;
                int right = n-1;
                while(left < right){
                    long sum = (long)nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum == target){
                        vector<int> v{nums[i],nums[j],nums[left],nums[right]};
                        sol.push_back(v);
                        while(left < right && nums[left] == nums[left+1]) left++;
                        while(left < right && nums[right] == nums[right-1]) right--;
                        left++;
                        right--;
                    }
                    else if(sum < target){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
            }
        }
        return sol;
    }
};


/*class Solution {
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
};*/

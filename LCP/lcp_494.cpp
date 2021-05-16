class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sol=0;
        calculate(nums, target, 0, sol);
        return sol;
    }
    void calculate(vector<int> & nums, int target, int step, int& sol){
        if(step >= nums.size()){
            if(target == 0) sol++;
            return;
        }
        calculate(nums, target-nums[step], step+1, sol);
        calculate(nums, target+nums[step], step+1, sol);
    }
};

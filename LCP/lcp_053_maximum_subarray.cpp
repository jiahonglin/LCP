class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0, sol = INT_MIN;
        for(int i=0;i<nums.size();i++){
            curSum = max(curSum+nums[i], nums[i]);
            sol = max(curSum, sol);
        }
        return sol;
    }
};

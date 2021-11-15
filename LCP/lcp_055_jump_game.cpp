class Solution {
public:
    bool canJump(vector<int>& nums) {
        int stepLeft = nums[0];
        for(int i=1;i<nums.size();i++){
            if(stepLeft-- <= 0) return false;
            stepLeft = max(stepLeft,nums[i]);
        }
        return true;
    }
};

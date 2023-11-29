class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, int> memo;
        docombine(nums,target,memo);
        return memo[target];
    }
    int docombine(vector<int>& nums, int target, unordered_map<int, int>& memo){
        if(target == 0) return 1;
        if(target < 0) return 0;
        if(memo.count(target)) return memo[target];
        int res=0;
        for(int i=0;i<nums.size();i++){
            res+=docombine(nums,target-nums[i],memo);
        }
        memo[target] = res;
        return res;

    }

};

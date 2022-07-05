class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {};
        vector<vector<int>> sol;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i+1;
            int right = nums.size()-1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0){
                    sol.push_back(vector<int>{nums[i] , nums[left] , nums[right]});
                    while(left<nums.size()-1 && nums[left] == nums[left+1]) left++;
                    while(right>0 && nums[right] == nums[right-1] ) right--;
                    left++;
                    right--;
                }
                else if(sum < 0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        
        return sol;
    }
};

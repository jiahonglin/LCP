class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        int sum=0;
        int ans=INT_MAX;
        while(j < nums.size()){
            sum+=nums[j];
            while(true){
                if(sum-nums[i] < target) break;
                sum-=nums[i];
                i++;
            }
            if(sum >= target){
                ans = min(ans, j-i+1);
            }
            j++;
        }
        return ans==INT_MAX?0:ans;
    }
};

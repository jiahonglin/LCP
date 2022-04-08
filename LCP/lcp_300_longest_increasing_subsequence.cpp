class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> comp{nums[0]};
        for(int i=1;i<nums.size();i++){
            if(nums[i] < comp[0]) comp[0] = nums[i];
            else if(nums[i] > comp.back()) comp.push_back(nums[i]);
            else{
                int left = 0;
                int right = comp.size();
                while(left<right){
                    int mid = left+(right-left)/2;
                    if(comp[mid] < nums[i]) left = mid+1;
                    else right=mid;
                }
                comp[left] = nums[i];
            }
        }
        return comp.size();
    }
    
    /*O(n^2)*/
    /*
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int res=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
            res = max(res,dp[i]);
        }
        return res;
    }
    */
};

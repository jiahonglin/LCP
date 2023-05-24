class Solution {
public:
/*
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
*/
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0,right=0;
        int sum=0;
        int len=INT_MAX;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            while(left<=right && sum >= target){
                len = min(len,right-left+1);
                sum-=nums[left];
                left++;
            }
        }
        return (len==INT_MAX)?0:len;

    }
};

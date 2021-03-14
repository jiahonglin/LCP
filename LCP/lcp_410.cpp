class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left=0, right=0, mid=0;
        for(int i=0;i<nums.size();i++){
            left = max(left,nums[i]);
            right += nums[i];
        }
        while(left < right){
            mid = left+(right-left)/2;
            if(canSplit(nums, mid, m)) right=mid;
            else left = mid+1;
        }
        return right;
    }
    bool canSplit(vector<int>& nums, int mid, int m){
        int cnt=1, sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum > mid){
                sum = nums[i];
                cnt++;
                if(cnt > m) return false;
            }
        }
        return true;
    }
};

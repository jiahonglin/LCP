class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0, fast=0, t=0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }
        while(true){
            fast = nums[fast];
            t = nums[t];
            if(fast == t) break;
        }
        return t;
    }
    /*
    int findDuplicate(vector<int>& nums) {
        int left = 1;
        int right = nums.size();
        while(left < right){
            int mid = left+(right-left)/2;
            int cnt=0;
            for(auto num:nums){
                if(num <= mid) cnt++;
            }
            if(cnt <= mid) left=mid+1;
            else right=mid;
        }
        return right;
    }
    */
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int right = nums.size()-1;
        int left = 0;
        int mid;
        while(left < right)
        {
            mid = left + (right-left)/2;
            if(nums[mid] < nums[mid+1]) left = mid+1;
            else
                right = mid;
        }
        return left;
    }
};

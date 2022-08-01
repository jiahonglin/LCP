class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1 && nums[0]==target) return 0;
        if(n == 1 && nums[0] != target) return -1;
        return dosearch(nums,0,n-1,target);
    }
    int dosearch(vector<int>& nums, int start, int end, int target){
        if(start>end) return -1;
        int mid = start+ (end-start)/2;
        if(nums[mid] == target) return mid;
        if(nums[mid] < nums[end]){
            if(nums[mid] < target && target <= nums[end]){
                return dosearch(nums,mid+1,end,target);
            }
            else{
                return dosearch(nums,start,mid-1,target);
            }
        }
        else{
            if(nums[start] <= target && target < nums[mid]){
                return dosearch(nums,start,mid-1,target);
            }
            else{
                return dosearch(nums,mid+1,end,target);
            }
        }
    }
    /*
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1,mid=0;
        while(right >= left)
        {
            mid = left + (right-left)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > nums[right])
            {
                if(nums[mid] > target && nums[left] <= target) 
                    right = mid-1;
                else
                    left = mid+1;
            }
            else
            {
                if(nums[mid] < target && nums[right]>=target)
                    left = mid+1;
                else
                    right = mid-1;
            }
        }
        return -1;
    }
    */
};

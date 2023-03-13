class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        return findMinPos(0,nums.size()-1,nums);
    }
    int findMinPos(int left, int right, vector<int>& nums){
        if(left>=right) return nums[left];
        int mid = left+(right-left)/2;
        if(nums[mid] > nums[right]){
            return findMinPos(mid+1,right,nums);
        }
        else{
            return findMinPos(left,mid,nums);
        }
    }
};

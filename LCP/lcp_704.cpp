class Solution {
public:
    int search(vector<int>& nums, int target) {
      
        return searchTarget(nums, target, 0, nums.size()-1);
    }
    int searchTarget(vector<int>& num, int target, int start, int end)
    {
        if(start > end) return -1;
        int mid = start + (end - start)/2;
        if(num[mid] == target) return mid;
        else if(num[mid] > target)
        {
            return searchTarget(num,target,start,mid-1);
        }
        else
        {
            return searchTarget(num,target,mid+1,end);
        }
    }
};

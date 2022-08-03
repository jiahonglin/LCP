class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==1 && nums[0] == target) return {0,0};
        int left = 0, right = n-1;
        int start = -1, end = -1;
        vector<int> ans;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target){
                start = mid;
                end = mid;
                while(start > 0 && nums[start-1] == target) start--;
                while(end < n-1 && nums[end+1] == target) end++;
                break;
            }
            else if(nums[mid] > target){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
    /*
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> startEndIndex;
        int left,right,mid,hitIndex=-1;
        left = 0;
        right = nums.size()-1;
        startEndIndex.assign(2,-1);
        if(nums.size()==0) return startEndIndex;
        while(left+1 < right)
        {
            mid = left + (right-left)/2;
            if(nums[mid]==target)
            {
                hitIndex = mid;
                break;
            }
            else if(nums[mid] < target)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        if(nums[left] == target) hitIndex = left;
        if(nums[right] == target) hitIndex = right;
        if(hitIndex != -1)
        {
            int leftEnd = hitIndex;
            int rightEnd = hitIndex;
            while(leftEnd > 0 && nums[leftEnd-1] == target) --leftEnd;
            while(rightEnd < nums.size()-1 && nums[rightEnd+1] == target) ++rightEnd;
            startEndIndex[0] = leftEnd;
            startEndIndex[1] = rightEnd;
        }
        return startEndIndex;
    }
    */
};

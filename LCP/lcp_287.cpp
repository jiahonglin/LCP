class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*
        int sol=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]){
                sol = nums[i];
                break;
            }
        }
        return sol;
        */
        int left = 1;
        int right = nums.size();
        int cnt=0;
        int mid=0;
        while(left < right){
            mid = left + (right-left)/2;
            cnt = 0;
            for(int num:nums){
                if(num <= mid) cnt++;
            }
            if(cnt > mid) right = mid;
            else left = mid+1;
        }
        return right;
    }
};

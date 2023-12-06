class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int gap = INT_MIN;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1] > gap){
                gap = nums[i]-nums[i-1];
            }
        }
        return gap;
    }
};

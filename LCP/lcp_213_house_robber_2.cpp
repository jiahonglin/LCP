class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0],nums[1]);
        return max(robb(nums,0,nums.size()-2),robb(nums,1,nums.size()-1));
    }
    int robb(vector<int>& nums, int start, int end){
        int a = nums[start];
        int b = max(nums[start],nums[start+1]);
        int c = b;
        for(int i = start+2;i<=end;i++){
            c = max(b,a+nums[i]);
            a = b;
            b = c;
        }
        return c;
    }
};

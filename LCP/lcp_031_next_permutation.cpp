class Solution {
public:
    
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;
        int j = n-1;
        while(i>=0 && nums[i+1] <= nums[i]) i--;
        if(i >= 0){
            while(j > i && nums[j] <= nums[i]) j--;
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1,nums.end());
    }
    /*
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for(int i = n-2;i>=0;i--){
            if(nums[i+1] > nums[i]){
                for(int j=n-1;j>i;j--){
                    if(nums[j]>nums[i]){
                        swap(nums[i],nums[j]);
                        reverse(nums.begin()+i+1,nums.end());
                        return;
                    }
                }
            }
        }
        reverse(nums.begin(),nums.end());
    }
    */
};

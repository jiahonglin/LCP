class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        int n=nums.size();
        if(n==1) return 1;
        if(n==2) return 2;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i] == nums[i+1] && nums[i] == nums[i+2]){}
            else{
                nums[k]=nums[i];
                k++;
            }
        }
        nums[k++]=nums[n-2];
        nums[k++]=nums[n-1];
        return k;
    }
};

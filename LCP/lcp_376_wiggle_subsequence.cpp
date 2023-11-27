class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int positive=1, negative=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] < nums[i]) positive=negative+1;
            else if(nums[i-1] > nums[i]) negative=positive+1;
        }
        return max(positive,negative);
    }
    /*
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> positive(nums.size(), 1);
        vector<int> negative(nums.size(), 1);
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]) positive[i]  = max(negative[j]+1, positive[i]);
                else if(nums[j] > nums[i]) negative[i] = max(positive[j]+1, negative[i]);
            }
        }
        return max(positive.back(), negative.back());
    }
    */
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int longest=1,cur=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]){
                continue;
            }
            else if(nums[i]-nums[i-1] == 1){
                cur+=1;
            }
            else{
                longest=max(longest,cur);
                cur=1;
            }
        }
        longest=max(longest,cur);
        return longest;
    }
};

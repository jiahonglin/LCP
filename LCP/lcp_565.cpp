class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxNestLen = 0;
        vector<int> rec(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            int step = nums[i];
            if(rec[step] == -1){
                int nestLen = 1;
                int nestStart = nums[i];
                while(nums[step] != nestStart){
                    nestLen++;
                    rec[step] = 0;
                    step = nums[step];
                }
                maxNestLen = (maxNestLen>nestLen?maxNestLen:nestLen);
            }
        }
        return maxNestLen;
    }
    
};

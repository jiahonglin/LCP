class Solution {
public:
    int jump(vector<int>& nums) {
        int jumpNum=0, curStep=0, maxStep=0;
        for(int i=0;i<nums.size()-1;i++){
            maxStep=max(i+nums[i],maxStep);
            if(i == curStep){
                curStep = maxStep;
                jumpNum++;
            }
        }
        return jumpNum;
    }
    
    
    /*TLE*/
    /*
    int minStep = INT_MAX;
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        dojump(nums,0,0);
        return minStep;
    }
    void dojump(vector<int>& nums, int pos, int step){
        if(pos+nums[pos] >= nums.size()-1){
            step+=1;
            minStep = min(minStep,step);
        }
        int travel = nums[pos];
        while(travel > 0){
            if(pos+travel < nums.size())
                dojump(nums, pos+travel, step+1);
            travel--;
        }
    }
    */
};

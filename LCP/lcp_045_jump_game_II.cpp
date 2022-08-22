class Solution {
public:

    int jump(vector<int>& nums){
        int n = nums.size();
        vector<int> v(n,0);
        for(int i=n-2;i>=0;i--){
            if(nums[i] >= n-1-i){
                v[i] = 1;
            }
            else{
                int minStep = INT_MAX-1;
                for(int j=1;j<=nums[i];j++)
                    minStep = min(minStep,1+v[i+j]);
                v[i] = minStep;
            }
        }
        return v[0];
    }

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

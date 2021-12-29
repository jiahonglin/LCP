class Solution {
public:
    /* method 1 */
    int maxProduct(vector<int>& nums) {
        int sol=INT_MIN;
        int curProd=1;
        for(int i=0;i<nums.size();i++){
            curProd*=nums[i];
            sol=max(sol,curProd);
            if(curProd == 0) curProd=1;
        }
        curProd=1;
        for(int i=nums.size()-1;i>=0;i--){
            curProd*=nums[i];
            sol=max(sol,curProd);
            if(curProd == 0) curProd=1;
        }
        return sol;
    }
    /* method 2 */
    /*
    int maxProduct(vector<int>& nums) {
        vector<int> gx(nums.size(),0);
        vector<int> lx(nums.size(),0);
        int sol=nums[0];
        gx[0]=nums[0];
        lx[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            gx[i]=max(max(gx[i-1]*nums[i],nums[i]),lx[i-1]*nums[i]);
            lx[i]=min(min(gx[i-1]*nums[i],nums[i]),lx[i-1]*nums[i]);
            sol=max(sol,gx[i]);
        }
        if(nums.size()==1) sol=max(sol,gx[nums.size()-1]);
        return sol;
    }
    */
};

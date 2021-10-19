class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int closestSum=0;
        int closestDiff=INT_MAX;
        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k=n-1;
            while(j<k && k>=0){
                int sum = nums[i]+nums[j]+nums[k];
                int diff=abs(sum-target);
                if(sum==target){
                    return sum;
                }
                else if(sum < target){
                    j++;
                }
                else{
                    k--;
                }
                if(diff < closestDiff){
                    closestDiff=diff;
                    closestSum=sum;
                }
            }
        }
        return closestSum;
    }
};

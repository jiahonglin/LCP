class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff = INT_MAX;
        int sol = 0;
        for(int i = 0;i<nums.size()-2;i++){
            int left = i+1;
            int right = nums.size()-1;
            while(left < right){
                int sum = nums[i]+nums[left]+nums[right];
                if(sum == target) return target;
                else if(sum < target){
                    
                    left++;
                }
                else{
                    right--;
                }
                if(diff > abs(target-sum)){
                    diff = abs(target-sum);
                    sol = sum;
                }
                
            }
        }
        return sol;;
    }
};

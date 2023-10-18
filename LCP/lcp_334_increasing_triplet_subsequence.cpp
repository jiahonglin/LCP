class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> forward(nums.size(),nums[0]);
        vector<int> backward(nums.size(), nums.back());
        for(int i=1;i<nums.size();i++){
            forward[i] = min(nums[i], forward[i-1]);
        }
        for(int i=nums.size()-2;i>=0;i--){
            backward[i] = max(backward[i+1],nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] > forward[i] && nums[i] < backward[i]) return true;
        }
        return false;
    }
    /*
    bool increasingTriplet(vector<int>& nums) {
        int element1 = INT_MAX;
        int element2 = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(element1 >= nums[i]){
                element1 = nums[i];
            }
            else if(element2 >= nums[i]){
                element2 = nums[i];
            }
            else return true;
        }
        return false;
    }
    */
};

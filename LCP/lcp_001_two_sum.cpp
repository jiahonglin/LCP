class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sol;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(target-nums[i]) != m.end()){
                sol.push_back(m[target-nums[i]]);
                sol.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }
        return sol;
    }
    /*Method 2*/
    /*
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sol;
        for(int i = 0;i<nums.size();i++){
            for(int j = i+1;j < nums.size();j++){
                if(nums[i]+nums[j] == target){
                    sol.push_back(i);
                    sol.push_back(j);
                    break;
                }
            }
        }
        return sol;
    }
    */
};

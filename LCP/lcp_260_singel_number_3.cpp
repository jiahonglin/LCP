class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        unsigned int numxor=0; // different bit in two digit
        unsigned int diff=0; // two digit diff
        vector<int> res(2,0);
        for(int i=0;i<nums.size();i++){
            numxor ^= nums[i];
        }
        diff = numxor & (-numxor);

        for(auto &a : nums){
            if(diff & a) res[0] ^= a;
            else res[1] ^= a;
        }
        return res;

    }
};

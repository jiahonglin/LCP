class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){
            int sum=0;
            for(int n:nums){
                sum += (n >> i) & 1;
            }
            ans |= (sum%3) << i;
        }
        return ans;
    }

/*
    int singleNumber(vector<int>& nums) {
        vector<int> ans(32,0);
        for(int n:nums){
            for(int i=0;i<32;i++){
                ans[i] += (n >> i) & 1;
            }
        }
        int ret=0;
        for(int i=0;i<32;i++){
            ret += (ans[i]%3) << i;
        }
        return ret;
    }
*/
/*
    int singleNumber(vector<int>& nums) {
        int one = 0;
        int two = 0;
        for(auto n:nums){
            one = (one ^ n) & ~two;
            two = (two ^ n) & ~one;
        }
        return one;
    }
*/
/*
    int singleNumber(vector<int>& nums) {
        int sol=0;
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]--;
        }
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second!=-3) sol=it->first;
        }
        return sol;
    }
*/
};

class Solution {
public:
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
};

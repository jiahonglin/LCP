class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> m;
        m.insert({0,0});
        m.insert({1,0});
        m.insert({2,0});
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int idx=0;
        for(auto it=m.begin();it!=m.end();it++){
            while(it->second > 0){
                nums[idx]=it->first;
                idx++;
                it->second--;
            }
        }
    }
};

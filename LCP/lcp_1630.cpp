class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = l.size();
        int idx = 0;
        vector<bool> ans;
        while(idx < m){
            vector<int> subarr(nums.begin()+l[idx],nums.end()-(nums.size()-r[idx]-1));
            //vector<int> subarr;
            //for(int x=l[idx];x<=r[idx];x++){
            //    subarr.push_back(nums[x]);
            //}
            sort(subarr.begin(),subarr.end());
            int diff = subarr[1]-subarr[0];
            bool ari = true;
            for(int i=1;i<subarr.size();i++){
                if(subarr[i]-subarr[i-1] != diff) ari = false;
            }
            ans.push_back(ari);
            idx++;
        }
        return ans;
    }
};

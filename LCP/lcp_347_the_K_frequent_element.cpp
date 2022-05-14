class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for(int n:nums) m[n]++;
        
        vector<int> times;
        for(auto i:m) times.push_back(i.second);
        
        sort(times.begin(),times.end());
        
        vector<int> sol;
        while(k > 0){
            for(auto i:m){
                if(i.second == times.back()){
                    sol.push_back(i.first);
                    m.erase(i.first);
                    times.pop_back();
                    k--;
                    break;
                }
            }
        }
        return sol;
    }
};

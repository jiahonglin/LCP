class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        priority_queue<pair<int,int>> q;
        vector<int> ans;
        for(auto n:nums) m[n]++;
        for(auto s:m) q.push({s.second, s.first});
        for(int i=0;i<k;i++){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
    /*
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
    */
};

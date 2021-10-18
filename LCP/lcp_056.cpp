class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int,int> m;
        vector<vector<int>>sol;
        for(int i=0;i<intervals.size();i++){
            m[intervals[i][0]]++;
            m[intervals[i][1]]--;
        }
        vector<int> range(2,-1);
        int sum=0;
        for(auto it:m){
            sum+=it.second;
            if(range[0] == -1){
                range[0] = it.first;
            }
            if(sum == 0){
                range[1] = it.first;
            }
            if(range[0] != -1 && range[1] != -1){
                sol.push_back(range);
                range[0]=-1;
                range[1]=-1;
            }
        }
        return sol;
    }
};

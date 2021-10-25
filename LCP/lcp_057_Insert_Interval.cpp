class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        map<int,int> s;
        for(int i=0;i<intervals.size();i++){
            s[intervals[i][0]]++;
            s[intervals[i][1]]--;
        }
        s[newInterval[0]]++;
        s[newInterval[1]]--;
        int sum=0;
        vector<int> range(2,-1);
        vector<vector<int>> sol;
        for(auto it:s){
            sum+=it.second;
            if(it.second >= 0 && range[0] == -1){
                range[0] = it.first;
            }
            if(sum == 0){
                range[1] = it.first;
                sol.push_back(range);
                range[0]=-1;
                range[1]=-1;
            }
        }
        return sol;
    }

};

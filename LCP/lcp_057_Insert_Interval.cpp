class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> sol;
        int i=0, n=intervals.size();
        while(i < n && intervals[i][1] < newInterval[0]) sol.push_back(intervals[i++]);
        vector<int> in = newInterval;
        while(i<n && intervals[i][0] <= in[1]){
            in[0] = min(intervals[i][0],in[0]);
            in[1] = max(intervals[i][1],in[1]);
            i++;
        }
        sol.push_back(in);
        while(i<n) sol.push_back(intervals[i++]);
        return sol;
    }
/*
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
*/
};

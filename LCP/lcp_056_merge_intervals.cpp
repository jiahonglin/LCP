class Solution {
public:
/*
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
   */
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> sol;
        vector<int> out(2,0);
        for(int i=0;i<intervals.size();i++){
            out[0] = intervals[i][0];
            out[1] = intervals[i][1];
            while(i+1<intervals.size() && intervals[i+1][0] <= out[1]){
                i++;
                out[1] = max(intervals[i][1],out[1]);
            }
            sol.push_back(out);
        }
        return sol;
    }
};

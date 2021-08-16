class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = INT_MIN;
        int mx = INT_MIN;
        for(int i=0;i<values.size();i++){
            maxScore = max(maxScore,mx+values[i]-i);
            mx = max(mx, values[i]+i);
        }
        return maxScore;
    }
};

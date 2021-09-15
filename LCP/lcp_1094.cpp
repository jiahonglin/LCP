class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> v(1000,0);
        for(int i=0;i<trips.size();i++){
            for(int j=trips[i][1];j<trips[i][2];j++){
                v[j]+=trips[i][0];
            }
        }
        for(int i=0;i<1000;i++){
            if(v[i]>capacity) return false;
        }
        return true;
    }
};

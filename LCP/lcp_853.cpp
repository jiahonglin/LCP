class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int,double> m;
        for(int i=0;i<position.size();i++){
            m[-position[i]] = (double)(target-position[i])/speed[i];
        }
        double slowcar=0.0;
        int count=0;
        for(auto it:m){
            if(it.second > slowcar){
                count++;
                slowcar=it.second;
            }
        }
        return count;
    }
};

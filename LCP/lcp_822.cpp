class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int sol=INT_MAX;
        unordered_set<int> s;
        for(int i=0;i<fronts.size();i++){
            if(fronts[i] == backs[i]) s.insert(fronts[i]);
        }
        for(int f:fronts){
            if(!s.count(f)) sol=min(sol,f);
        }
        for(int b:backs){
            if(!s.count(b)) sol=min(sol,b);
        }
        return sol==INT_MAX?0:sol;
    }
};

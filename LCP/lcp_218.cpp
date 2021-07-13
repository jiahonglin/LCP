class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> verticalEdge,res;
        multiset<int> m; /*store the heigh value, multi set would auto sort*/
        int preH,curH;
        for(auto &a:buildings){
            verticalEdge.push_back({a[0],-a[2]});
            verticalEdge.push_back({a[1],a[2]});
        }
        sort(verticalEdge.begin(),verticalEdge.end());
        m.insert(0);
        for(auto &a:verticalEdge){
            if(a[1]<0) m.insert(-a[1]);
            else m.erase(m.find(a[1]));
            curH = *m.rbegin();
            if(curH!=preH){
                res.push_back({a[0],curH});
                preH=curH;
            }
        }
        return res;
    }
};

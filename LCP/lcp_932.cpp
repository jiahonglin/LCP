class Solution {
public:
    vector<int> beautifulArray(int n) {

        vector<int> res{1};
        
        while(res.size()<n){
            vector<int> t;
            for(int i=0;i<res.size();i++){
                if(2*res[i]-1<=n) t.push_back(2*res[i]-1);
            }
            for(int i=0;i<res.size();i++){
                if(2*res[i]<=n) t.push_back(2*res[i]);
            }
            res = t;
        }
        
        return res;

    }
};

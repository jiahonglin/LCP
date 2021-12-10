class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==1){
            return {0,1};
        }
        vector<int> v=grayCode(n-1);
        for(int i=v.size()-1;i>=0;i--){
            v.push_back(v[i] | 1<<n-1);
        }
        return v;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> sol;
        map<string,vector<string>> m;
        for(int i=0;i<strs.size();i++){
            string curr=strs[i];
            sort(curr.begin(),curr.end());
            m[curr].push_back(strs[i]);
        }
        for(auto it=m.begin();it!=m.end();it++){
            sol.push_back(it->second);
        }
        return sol;
    }
};

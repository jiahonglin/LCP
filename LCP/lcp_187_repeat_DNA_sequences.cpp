class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length() <= 10) return {};
        vector<string> sol;
        map<string,int> m;
        string ans = s.substr(0,10);
        m[ans]++;
        for(int i=10;i<s.length();i++){
            ans = ans.substr(1)+s[i];
            m[ans]++;
            if(m[ans]==2){
                sol.push_back(ans);
            }
        }
        return sol;
    }
};

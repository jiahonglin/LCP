class Solution {
public:
/*
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
*/
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length()< 10) return {};
        set<string> ss;
        vector<string> ans;
        for(int i=0;i<=s.length()-10;i++){
            string tmp = s.substr(i,10);
            if(ss.count(tmp) == 0){
                ss.insert(tmp);
            }
            else{
                //vector<string>::iterator it = find(ans.begin(),ans.end(),tmp);
                if(find(ans.begin(),ans.end(),tmp) == ans.end())
                    ans.push_back(tmp);
            }
        }
        return ans;
    }
};

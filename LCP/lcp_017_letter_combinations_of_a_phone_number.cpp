class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> sol;
        if(digits.size() == 0) return sol;
        unordered_map<char,string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        combine(digits,m, 0, sol,"");
        return sol;
    }
    void combine(string digits,unordered_map<char,string>& m, int idx, vector<string>& sol, string s){
        if (s.size() >= digits.size()){
            sol.push_back(s);
            return;
        }
        for(auto c:m[digits[idx]]){
            s.push_back(c);
            combine(digits,m,idx+1,sol,s);
            s.pop_back();
        }
        
    }
};

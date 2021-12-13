class Solution {
public:
    vector<string> sol;
    vector<string> restoreIpAddresses(string s) {
        string cur;
        genIpAddr(s,0,0,cur);
        return sol;
    }
    void genIpAddr(string s, int idx, int sec, string cur){
        if(idx == s.length()  && sec == 4){
            cur.pop_back();
            sol.push_back(cur);
        }
        if(idx >= s.length() || sec >= 4) return;
        
        if(isValid(s,idx,1))
            genIpAddr(s,idx+1,sec+1,cur+s.substr(idx,1)+'.');
        if(isValid(s,idx,2))
            genIpAddr(s,idx+2,sec+1,cur+s.substr(idx,2)+'.');
        if(isValid(s,idx,3))
            genIpAddr(s,idx+3,sec+1,cur+s.substr(idx,3)+'.');
    }
    bool isValid(string s, int idx, int len){
        if(idx+len > s.length()) return false;
        string str=s.substr(idx,len);
        if(str.length()>1 && str[0]=='0') return false;
        int num=stoi(str);
        if(num > 255) return false;
        return true;
    }
};

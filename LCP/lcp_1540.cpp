class Solution {
public:
    bool canConvertString(string s, string t, int k) {
                
        if(s.length() != t.length()) return false;
        map<int,int> mp;
        for(int i=0;i<s.length();i++){
            int tmp = t[i]-s[i];
            if(tmp<0) tmp+=26;
            if(tmp == 0) continue;
            mp[tmp]++;
        }
        for(auto t:mp){
            if(t.first > k) return false;
            if(t.second > 1){
                mp[t.first+26]+=t.second-1;
            }
        }
        return true;
    }
};

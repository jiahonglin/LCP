class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> m(26,0);
        vector<int> visited(26,0);
        string sol="";
        for(auto c:s) m[c-'a']++;
        for(auto c:s){
            m[c-'a']--;
            if(visited[c-'a']) continue;
            while(sol!="" && c < sol.back() && m[sol.back()-'a']){
                visited[sol.back()-'a'] = 0;
                sol.pop_back();
            }
            sol+=c;
            visited[c-'a']=1;
        }
        return sol;
    }
};

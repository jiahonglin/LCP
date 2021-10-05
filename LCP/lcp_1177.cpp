class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> cnt(s.size()+1, vector<int>(26));
        vector<bool> sol;
        for(int i=0;i<s.size();i++){
            cnt[i+1]=cnt[i];
            cnt[i+1][s[i]-'a']++;
        }
        for(int i=0;i<queries.size();i++){
            int sum=0;
            for(int j=0;j<26;j++){
                sum+=(cnt[queries[i][1]+1][j]-cnt[queries[i][0]][j])%2;
            }
            if(sum/2 <= queries[i][2]){
                sol.push_back(true);
            }
            else{
                sol.push_back(false);
            }
        }
        return sol;
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1=s1.length();
        int l2=s2.length();
        int l3=s3.length();
        if(l1+l2 != l3) return false;
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(l1+1,vector<bool>(l2+1,false));
        q.push({0,0});
        while(!q.empty()){
            auto p = q.front(); q.pop();
            if(p.first == l1 && p.second == l2) return true;
            if(visited[p.first][p.second]) continue;
            if(p.first < l1 && s1[p.first] == s3[p.first+p.second]) q.push({p.first+1,p.second});
            if(p.second < l2 && s2[p.second] == s3[p.first+p.second]) q.push({p.first,p.second+1});
            visited[p.first][p.second]=true;
        }
        return false;
        
    }
};

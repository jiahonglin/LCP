class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(mat.size(),vector<int> (mat[0].size(),0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    res[i][j] = 0;
                }
                else{
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    int distance=0;
                    while(!q.empty()){
                        int qsize = q.size();
                        for(int k=0;k<qsize;k++){
                            auto t = q.front();q.pop();
                            if(t.first<0 || t.first>=m || t.second<0 || t.second>=n) continue;
                            if(mat[t.first][t.second] == 1){
                                q.push({t.first-1,t.second});
                                q.push({t.first+1,t.second});
                                q.push({t.first,t.second-1});
                                q.push({t.first,t.second+1});
                            }
                            else{
                                res[i][j]=distance;
                                while(!q.empty()) q.pop();
                                break;
                            }
                        }
                        distance++;
                    }
                }
            }
        }
        return res;
    }
};

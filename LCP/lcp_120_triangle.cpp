class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height=triangle.size();
        for(int i=1;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                if(j==0){
                    triangle[i][j]+= triangle[i-1][j];
                }
                else if(j==triangle[i].size()-1){
                    triangle[i][j]+= triangle[i-1][j-1];
                }
                else{
                    triangle[i][j]+= min(triangle[i-1][j],triangle[i-1][j-1]);
                }
            }
        }
        sort(triangle[height-1].begin(),triangle[height-1].end());
        return triangle[height-1][0];
    }
};

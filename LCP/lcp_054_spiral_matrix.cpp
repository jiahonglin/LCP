class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> sol;
        int up=0, right=matrix[0].size()-1, down=matrix.size()-1, left=0;

        while(true){
            for(int j=left;j<=right;j++){
                sol.push_back(matrix[up][j]);
            }
            if(++up > down) break;
            for(int i=up;i<=down;i++){
                sol.push_back(matrix[i][right]);
            }
            if(--right < left) break;
            for(int j=right;j>=left;j--){
                sol.push_back(matrix[down][j]);
            }
            if(--down < up) break;
            for(int i=down;i>=up;i--){
                sol.push_back(matrix[i][left]);
            }
            if(++left > right) break;
        }
        return sol;
    }

};

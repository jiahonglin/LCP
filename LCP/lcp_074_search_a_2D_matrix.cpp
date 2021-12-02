class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i=0;
        for(;i<m;i++){
            if(matrix[i][0] <= target && matrix[i][n-1] >= target)
                break;
            if(i == m-1) return false;
        }

        for(int j=0;j<n;j++){
            if(matrix[i][j] == target) return true;
        }
        return false;

        
    }
};

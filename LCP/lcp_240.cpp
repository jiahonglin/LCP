class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int startR = m-1;
        int startC = 0;
        if(matrix.size()==0 || matrix[0].size()==0) return false;
        if(target < matrix[0][0] || target > matrix[m-1][n-1]) return false;

        while(true){
            if(target > matrix[startR][startC]) startC++;
            else if(target < matrix[startR][startC]) startR--;
            else return true;
            if(startR < 0 || startC >= n) break;
        }
        return false;
    }
    /*
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0;i<m;i++){
            if(target >= matrix[i][0] && target <= matrix[i][n-1]){
                for(int j=0;j<n;j++){
                    if(target == matrix[i][j]) return true;
                }
            }
        }
        return false;
    }
    */
};

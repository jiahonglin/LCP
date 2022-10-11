class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool bFind = false;
        if(m == 1){
            for(int j=0;j<n;j++){
                if(matrix[0][j] == target){
                    bFind=true;
                    break;
                } 
            }
            return bFind;
        }

        if(n == 1){
            for(int i=0;i<m;i++){
                if(matrix[i][0] == target){
                    bFind=true;
                    break;
                }
            }
            return bFind;
        }

        for(int i=0;i<m;i++){
            if(matrix[i][0] <= target && target <= matrix[i][n-1]){
                for(int j=0;j<n;j++){
                    if(matrix[i][j] == target){
                        bFind=true;
                        break;
                    }
                }
                return bFind;
            }
        }

        return bFind;

    }
    /*
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
    */
};

class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        return searchRec(matrix,target,0,matrix[0].size()-1,0,matrix.size()-1);
    }
    bool searchRec(vector<vector<int>>& matrix,int target, int left, int right, int up, int down){
        if(left>right || up>down) return false;
        if(matrix[up][left] > target || matrix[down][right] < target) return false;
        int mid = left+(right-left)/2;
        int row=up;
        while(row <= down && matrix[row][mid] <= target){
            if(matrix[row][mid] == target) return true;
            row++;
        }
     return searchRec(matrix,target,left,mid-1,row,down) || searchRec(matrix,target,mid+1,right,up,row-1);
    }
    
    /*
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.size() == 0) return false;
        int x = matrix.size()-1;
        int y = 0;
        while(true){
            if(matrix[x][y] < target) y++;
            else if(matrix[x][y] > target) x--;
            else return true;
            if(x<0||y>=matrix[0].size()) break;
        }
        return false;
    }
    */
};

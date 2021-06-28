class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> queen(n,string(n,'.'));
        helper(queen,0,res);
        return res;
    }
    void helper(vector<string>& queen, int row, vector<vector<string>>& res){
        if(row == queen.size()){
            res.push_back(queen);
            return;
        }
        for(int i=0;i<queen.size();i++){
            if(isvalid(queen,row,i)){
                queen[row][i] = 'Q';
                helper(queen,row+1,res);
                queen[row][i] = '.';
            }
        }
    }
    bool isvalid(vector<string>& queen, int row, int col){
        for(int i=0;i<row;i++){
            if(queen[i][col] == 'Q') return false;
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(queen[i][j] == 'Q') return false;
        }
        for(int i=row-1,j=col+1;i>=0 && j<queen.size();i--,j++){
            if(queen[i][j] == 'Q') return false;
        }
        return true;
    }
};

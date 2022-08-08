class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return checkSudoku(board, 0, 0);
    }
    bool checkSudoku(vector<vector<char>>& board, int row, int col){
        if(col >= 9) return checkSudoku(board, row+1, 0);
        if(row >= 9) return true;
        if(board[row][col] == '.') return checkSudoku(board,row,col+1);
        for(int i=0;i<9;i++){
            if(i!=row && board[i][col] == board[row][col]) return false;
        }
        for(int j=0;j<9;j++){
            if(j!=col && board[row][j] == board[row][col]) return false;
        }
        int x=row-(row%3);
        int y=col-(col%3);
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                if(i!=row && j !=col){
                    if(board[i][j] == board[row][col]) return false;
                }
            }
        }
        return checkSudoku(board,row,col+1);
    }
};

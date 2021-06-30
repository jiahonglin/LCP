class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        Sudoku(board, 0, 0);
    }
    bool Sudoku(vector<vector<char>>& board, int row, int col){
        if(row == 9) return true;
        if(col >= 9) return Sudoku(board, row+1, 0);
        if(board[row][col] != '.') return Sudoku(board,row,col+1);
        for(char c='1';c<='9';c++){
            if(isValid(board,row,col,c)){
                board[row][col]=c;
                if(Sudoku(board,row,col+1)) return true;
                board[row][col]='.';
            }
        }
        return false;
    }
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int i=0;i<9;i++){
            if(board[i][col] == c) return false;
        }
        for(int j=0;j<9;j++){
            if(board[row][j] == c) return false;
        }
        int x = row-(row%3);
        int y = col-(col%3);
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                if(board[i][j] == c) return false;
            }
        }
        return true;
    }
};

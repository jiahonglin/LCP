class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0;i<m;i++){
            checkIsolate(board,i,0);
            checkIsolate(board,i,n-1);
        }
        for(int j=0;j<n;j++){
            checkIsolate(board,0,j);
            checkIsolate(board,m-1,j);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='#')
                    board[i][j]='O';
            }
        }
    }
    void checkIsolate(vector<vector<char>>& board, int m, int n){
        if(m<0 || m>=board.size() || n<0 || n>=board[0].size() || board[m][n]=='X' || board[m][n]=='#') return;
        board[m][n]='#';
        checkIsolate(board,m+1,n);
        checkIsolate(board,m-1,n);
        checkIsolate(board,m,n+1);
        checkIsolate(board,m,n-1);
    }
};

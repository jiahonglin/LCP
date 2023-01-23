class Solution {
public:
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0;i < m ;i++){
            isolate(board,i,0);
            if(n>0)
                isolate(board,i,n-1);
        }
        for(int j = 1; j< n-1; j++){
            isolate(board,0,j);
            if(m>0)
                isolate(board,m-1,j);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O')
                    board[i][j] = 'X';
                if(board[i][j]=='1')
                    board[i][j] = 'O';
            }
        }
    }
    void isolate(vector<vector<char>>& board, int x, int y){
    
        if(board[x][y] == 'O'){
            board[x][y] = '1';

            if(x > 0)
                isolate(board,x-1,y);
            if(x < board.size()-1)
                isolate(board,x+1,y);
            if(y > 0)
                isolate(board,x,y-1);
            if(y < board[0].size()-1)
                isolate(board,x,y+1);
        }

    }
/*
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
*/
};

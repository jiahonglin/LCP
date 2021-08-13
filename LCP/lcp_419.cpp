class Solution {
public:
    /*DFS*/
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(); 
        int n = board[0].size();
        int sol = 0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.' || visited[i][j]==true) continue;
                DFS(board,visited,i,j);
                sol++;
            }
        }
        return sol;
    }
    void DFS(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='.'|| visited[i][j]==true) return;
        visited[i][j] = true;
        DFS(board,visited,i+1,j);
        DFS(board,visited,i-1,j);
        DFS(board,visited,i,j-1);
        DFS(board,visited,i,j+1);
    }
    /*Iterative*/
    /*
    int countBattleships(vector<vector<char>>& board) {
        int battleships = 0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == '.' || (i>0 && board[i-1][j] == 'X') || (j>0 && board[i][j-1]=='X')) continue;
                battleships++;
            }
        }
        return battleships;
    }
    */
};

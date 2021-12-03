class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0]){
                    if(findexist(board,visited,word,i,j,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool findexist(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int i, int j, int cnt){
        
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || visited[i][j]==true || board[i][j]!=word[cnt]) return false;
        if(cnt == word.length()-1) return true;
        visited[i][j] = true;
        bool ret = findexist(board,visited,word,i+1,j,cnt+1)||
            findexist(board,visited,word,i-1,j,cnt+1)||
            findexist(board,visited,word,i,j+1,cnt+1)||
            findexist(board,visited,word,i,j-1,cnt+1);
        visited[i][j] = false;
        return ret;
            
    }
};

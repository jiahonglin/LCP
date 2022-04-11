class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<pair<int,int>> dir = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int cnt=0;
                for(auto d:dir){
                    int row = i+d.first;
                    int col = j+d.second;
                    if( row>=0 && row<m && col>=0 && col<n && (board[row][col] == 1 || board[row][col]==2)) cnt++;
                }
                if(board[i][j] == 1 && (cnt < 2 || cnt > 3)) board[i][j]=2;
                else if(board[i][j] == 0 && cnt == 3) board[i][j]=3;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j]%=2;
            }
        }
    }
    /*method 1*/
    /*
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        ans=board;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int ones = 0;
                int zeros = 0;
                calc(board,i,j,ones,zeros);
                if(board[i][j] == 1){
                    if(ones < 2) ans[i][j] = 0;
                    else if (ones > 3) ans[i][j] = 0;
                }
                else{
                    if(ones == 3) ans[i][j]=1;
                }
            }
        }
        board = ans;
    }
    void calc(vector<vector<int>>& board, int i, int j, int& ones, int& zeros){
        vector<int> x={-1,0,1};
        vector<int> y={-1,0,1};
        for(auto p:x){
            for(auto q:y){
                if(i+p >=0 && i+p<board.size() && j+q >=0 && j+q<board[0].size() ){
                    if(board[i+p][j+q] == 1) ones++;
                    else zeros++;
                }
            }
        }
        if(board[i][j] == 1) ones--;
        else zeros--;
    }
    */
};

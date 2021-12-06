class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> sol(n,vector<int>(n,0));
        int upper=0,down=n-1,left=0,right=n-1;
        int num=1;
        while(true){
            for(int j=left;j<=right;j++){
                sol[upper][j]=num++;
            }
            if(++upper > down) break;
            for(int i=upper;i<=down;i++){
                sol[i][right] = num++;
            }
            if(--right < left) break;
            for(int j=right;j>=left;j--){
                sol[down][j]=num++;
            }
            if(--down < upper) break;
            for(int i=down;i>=upper;i--){
                sol[i][left] = num++;
            }
            if(++left > right) break;
        }
        return sol;
    }
};

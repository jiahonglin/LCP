class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> r;
        vector<int> c;
        for(int m=0;m<matrix.size();m++){
            for(int n=0;n<matrix[0].size();n++){
                if(matrix[m][n] == 0){
                    r.push_back(m);
                    c.push_back(n);
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(find(r.begin(),r.end(),i)!=r.end() || find(c.begin(),c.end(),j)!=c.end()){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

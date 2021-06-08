class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> sol(rowIndex+1,0);
        sol[0] = 1;
        for(int i=1;i<=rowIndex;i++){
            for(int j=i;j>=1;j--){
                sol[j]+=sol[j-1];
            }
        }
        return sol;
    }
    
};

class Solution {
public:
    int countArrangement(int n) {
        int sol=0;
        vector<int> visited(n+1,0);
        doArrange(n,visited,1,sol);
        return sol;
    }
    void doArrange(int n, vector<int>& visited, int pos, int& sol){
        if(pos>n){
            sol++;
            return;
        }
        for(int i=1;i<=n;i++){
            if(visited[i]==0 && (i%pos==0 || pos%i==0)){
                visited[i]=1;
                doArrange(n,visited,pos+1,sol);
                visited[i]=0;
            }
        }
    }
};

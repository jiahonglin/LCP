class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int res=1;
        for(int i=0;i<b.size();i++){
            res = mypow(res,10) * mypow(a, b[i]) % 1337;
        }
        return res;
    }
    int mypow(int x, int n){
        if(n == 0) return 1;
        if(n == 1) return x%1337;
        return mypow(x%1337, n/2) * mypow(x%1337, n-n/2) %1337;
    }
};

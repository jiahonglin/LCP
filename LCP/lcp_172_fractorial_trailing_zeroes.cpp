class Solution {
public:
    int trailingZeroes(int n) {
        int sol=0;
        while(n){
            n/=5;
            sol+=n;
        }
        return sol;
    }
};

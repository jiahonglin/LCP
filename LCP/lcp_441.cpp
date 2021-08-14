class Solution {
public:
    int arrangeCoins(int n) {
        double stairNum = 1;
        int ans = 0;
        while(stairNum*(stairNum+1)/2 <= n){
            stairNum++;
            ans++;
        }
        return ans;
    }
    /*
    int arrangeCoins(int n) {
        int stairNum = 1;
        long long int allcoins = 1;
        while(n>allcoins){
            stairNum++;
            allcoins+=stairNum;
        }
        return n==allcoins?stairNum:stairNum-1;
    }
    */
};

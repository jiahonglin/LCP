class Solution {
public:
    int reverse(int x) {
        int sol=0;
        while(x){
            int digit = x%10;
            if((sol > 0 && sol > (INT_MAX-digit)/10) || (sol < 0 && sol < (INT_MIN-digit)/10)) return 0;
            sol=sol*10 + digit;
            x/=10;
        }
        return sol;
    }
};

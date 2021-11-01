class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == -2147483648 && divisor==-1)
            return 2147483647;
        int sign=1;
        long quotient=0, l_dividend, l_divisor;
        if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
            sign=-1;
        l_dividend = abs((long)dividend);
        l_divisor = abs((long)divisor);

        for(int i=31;i>=0;i--){
            if(l_dividend >= (l_divisor << i)){
                l_dividend-=l_divisor<<i;
                quotient=quotient|(long)1<<i;
            }
        }
        return sign*quotient;
    }
};

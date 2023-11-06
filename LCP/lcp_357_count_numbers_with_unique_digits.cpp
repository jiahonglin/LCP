class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n<=1) return pow(10,n);
        int add=0;
        while(n > 1){
            int fac=9;
            for(int i=9;i>=(11-n);i--){
                fac*=i;
            }
            add+=fac;
            n--;
        }
        return add+10;
    }
};

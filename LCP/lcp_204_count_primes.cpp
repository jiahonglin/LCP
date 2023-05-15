class Solution {
public:

    int countPrimes(int n) {
        int sol = 0;
        vector<bool> primes(n,true);
        for(int i=2;i<=sqrt(n);i++){
            for(int j=2*i;j<n;j=j+i){
                primes[j] = false;
            }
        }
        for(int k=2;k<n;k++){
            if(primes[k]) sol++;
        }
        return sol;
    }
    
    /*
    int countPrimes(int n) {
        int sol = 0;
        vector<bool> primes(n,true);

        for(int i=2;i<n;i++){
            if(primes[i]) sol++;
            else continue;
            if(i*2 < n){
                for(int j=i*2;j<n;j=j+i){
                    primes[j]=false;
                }
            }
        }
        return sol;
    }
    */

};

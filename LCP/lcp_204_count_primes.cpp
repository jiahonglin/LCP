class Solution {
public:
    int countPrimes(int n) {

        if(n<=2) return 0;
        vector<int> nums(n,0);
        int cnt=0;
        for(int i=2;i<n;i++){
            if(nums[i]==0) cnt++;
            else continue;
            if(i*2 < n){
                for(int j=i*2;j<n;j=j+i){
                    nums[j]=1;
                }   
            }
        }
        return cnt;
    }

};

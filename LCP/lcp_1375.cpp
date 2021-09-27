class Solution {
public:
    /*Method 1*/
    int numTimesAllBlue(vector<int>& light) {
        long int bulbSum = 0;
        long int momentSum = 0;
        int sol = 0;
        for(long int i=0;i<light.size();i++){
            bulbSum+=light[i];
            momentSum = (i+1)*((i+1)+1)/2;
            if(bulbSum == momentSum) sol++;
        }
        return sol;
    }
    /*Method 2*/
    /*
    int numTimesAllBlue(vector<int>& light) {
        int sol=0;
        int mx=-1;
        for(int i=0;i<light.size();i++){
            mx=max(mx,light[i]);
            if(mx<=i+1) sol++;
        }
        return sol;
    }
    */
};

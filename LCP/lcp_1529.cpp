class Solution {
public:
    int minFlips(string target) {
        int sol=0;
        char bulb='0';
        for(int i=0;i<target.length();i++){
            if(bulb != target[i]){
                bulb = target[i];
                sol++;
            }
        }
        return sol;
    }
};

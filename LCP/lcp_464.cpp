class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal <= maxChoosableInteger) return true;
        if(desiredTotal > (maxChoosableInteger*(maxChoosableInteger+1)/2)) return false;
         unordered_map<int,bool> mp;
        return canIwin(maxChoosableInteger, desiredTotal, 0, mp);
    }
    bool canIwin(int maxInt, int desire, int use, unordered_map<int,bool>& mp){
        if(mp.count(use)) return mp[use];
        for(int i=0;i<maxInt;i++){
            int cur=(1<<i);
            if((cur & use) == 0){
                if(desire <= i+1 || !canIwin(maxInt,desire-(i+1),cur|use, mp)){
                    mp[use]=true;
                    return true;
                }
            }
        }
        mp[use]=false;
        return false;
    }
};

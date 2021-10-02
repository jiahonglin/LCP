class Solution {
public:
    vector<char> v; //status:0(unknown), 1(win), -1(lose)
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal <= maxChoosableInteger) return true;
        if(desiredTotal > (maxChoosableInteger*(maxChoosableInteger+1)/2)) return false;
        v=vector<char>(1<<maxChoosableInteger,0);
        return canIwin(maxChoosableInteger, desiredTotal, 0);
    }
    bool canIwin(int M, int T, int state){
        
        if(T<=0) return false;
        if(v[state]!=0) return v[state]==1;
        for(int i=0;i<M;i++){
            if(state & (1<<i)) continue;
            if(!canIwin(M,T-(i+1), (state|(1<<i)))){
                v[state] = 1;
                return true;
            }
        }
        v[state]=-1;
        return false;
    }
    /*
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal <= maxChoosableInteger) return true;
        if(desiredTotal > (maxChoosableInteger*(maxChoosableInteger+1)/2)) return false;
         unordered_map<int,bool> mp;
        return canIwin(maxChoosableInteger, desiredTotal, 0, mp);
    }
    bool canIwin(int maxInt, int desire, int use, unordered_map<int,bool>& mp){
        if(mp.count(use)) return mp[use];
        for(int i=1;i<=maxInt;i++){
            int cur=(1<<i);
            if((cur & use) == 0){
                if(desire <= i || !canIwin(maxInt,desire-i,cur|use, mp)){
                    mp[use]=true;
                    return true;
                }
            }
        }
        mp[use]=false;
        return false;
    }
    */
};

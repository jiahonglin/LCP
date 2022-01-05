class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int stationNum=gas.size();
        int remainGas=0;
        int deficit=0;
        int startPos=0;
        for(int i=0;i<stationNum;i++){
            remainGas+=gas[i]-cost[i];
            if(remainGas<0){
                deficit+=remainGas;
                remainGas=0;
                startPos=(i+1)%stationNum;
            }
        }
        return remainGas+deficit >= 0?startPos:-1;
    }
};

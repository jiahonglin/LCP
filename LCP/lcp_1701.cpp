class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double waitTime = 0;
        int startTime = 0;
        for(int i=0;i<customers.size();i++){
            if(startTime>customers[i][0]){
                waitTime += (startTime+customers[i][1])-customers[i][0];
                startTime += customers[i][1];
            }
            else{
                waitTime += customers[i][1];
                startTime = customers[i][0]+customers[i][1];
            }
        }
        return waitTime/customers.size();
    }
};

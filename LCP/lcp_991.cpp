class Solution {
public:
    /*Iterative*/
    int brokenCalc(int startValue, int target){
        int cur=target;
        int steps=0;
        while(startValue < cur){
            if(cur%2 != 0){
                steps++;
                cur+=1;
            }
            steps++;
            cur/=2;
        }
        return steps+=(startValue-cur);
    }
    
    /*Recursive*/
    /*
    int brokenCalc(int startValue, int target) {
        if(startValue >= target) return startValue-target;
        if(target%2 != 0) return 1+brokenCalc(startValue, target+1);
        return 1+brokenCalc(startValue, target/2);
    }
    */
};
